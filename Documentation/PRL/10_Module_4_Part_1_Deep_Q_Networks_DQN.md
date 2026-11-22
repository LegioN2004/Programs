# Section 10: Module 4 (Part 1) — From Q-Learning to Deep Q-Networks (DQN)

---

## Q42. [Bank Q91] Why Tabular Q-Learning Fails in Large & Continuous State Spaces

### Prompt:
Give three distinct reasons from `DQNSlides.pdf` (Slide 6) why a tabular representation $Q(s, a)$ breaks down in environments like CartPole-v1 or pixel-based video games, focusing on memory scaling, continuous real-valued observations, and generalization across nearby states.

### Response:

**First, understand the limitation of a table:** A table is simply an Excel spreadsheet where every row is a state and every column is an action. For simple gridworlds with 16 squares, a table is great. But in the real world, tables fall apart completely.

---

### The 3 Core Reasons Tabular RL Fails

#### 1. Memory Scaling & The Curse of Dimensionality
* A tabular representation requires storing a table of size $|S| \times |A|$.
* In pixel-based environments (like Atari games), an observation is a raw image of $84 \times 84$ pixels with 256 grayscale levels. The number of possible discrete states is:
  $$|S| = 256^{84 \times 84} = 256^{7056} \approx 10^{16991}$$
* This number exceeds the total number of atoms in the observable universe ($\approx 10^{80}$). Storing such a table is physically impossible.

#### 2. Continuous Real-Valued Observations
* In physical control benchmarks like **CartPole-v1**, observations are continuous real numbers $\mathbb{R}^4$:
  $$\mathbf{s} = [x, \dot{x}, \theta, \dot{\theta}] \in \mathbb{R}^4$$
* In continuous spaces, the probability of encountering the exact same floating-point state twice (e.g., angle $\theta = 0.0523419...$) is mathematically **zero**.
* If an agent discretizes continuous space into bins, discretization either destroys critical precision (coarse bins) or leads to an exponential explosion in table size (fine bins).

#### 3. Lack of Generalization Across Nearby States
* In a lookup table, every cell $Q(s, a)$ is completely independent of every other cell.
* If a self-driving car learns that steering left avoids a tree at GPS coordinate $(X = 100.000, Y = 50.000)$, a tabular agent learns **absolutely nothing** about what to do at coordinate $(X = 100.001, Y = 50.000)$!
* Tabular representations cannot **generalize** knowledge across nearby, semantically identical states. A function approximator (like a Deep Neural Network) naturally shares weights and smoothly generalizes across similar states.

---

### Summary Table

| Limitation | Tabular Q-Learning | Deep Q-Networks (DQN) |
| :--- | :--- | :--- |
| **Memory Requirement** | $\mathcal{O}(\|S\| \cdot \|A\|)$ (Explodes to gigabytes/terabytes). | Fixed neural weights $\mathcal{O}(\|\theta\|)$ (Few megabytes). |
| **Continuous Inputs** | Requires fragile, lossy discretization. | Directly ingests continuous vectors $\mathbf{s} \in \mathbb{R}^d$. |
| **Generalization** | **Zero:** Each table entry is isolated. | **High:** Similar inputs share neural activations. |

---

## Q43. [Bank Q92] CartPole-v1 DQN Architecture & Exact Parameter Count

### Prompt:
For CartPole-v1 (4 continuous state features, 2 discrete actions), the architecture is:
$$\text{Input } \mathbb{R}^4 \to \text{Dense}(64) + \text{ReLU} \to \text{Dense}(64) + \text{ReLU} \to \mathbb{R}^2$$
(a) Calculate the exact number of trainable parameters (weights and biases) in each of the three linear layers and the total parameter count $\|\theta\|$ of the network.
(b) Answer the question on Slide 26: "Why are there two outputs rather than one, and why do we NOT apply a Softmax layer to the outputs of a DQN?"

### Response:

**First, understand the network design:** A DQN takes the state features as input and outputs the predicted $Q(s, a)$ value for every possible action in one single forward pass.

---

### (a) Exact Trainable Parameter Count Calculation

For a standard linear (dense) layer with $N_{\text{in}}$ inputs and $N_{\text{out}}$ outputs:
$$\text{Parameters} = \text{Weights} + \text{Biases} = (N_{\text{in}} \times N_{\text{out}}) + N_{\text{out}}$$

---

#### Layer 1: Input ($\mathbb{R}^4$) $\to$ Dense(64)
* $N_{\text{in}} = 4, \quad N_{\text{out}} = 64$
* Weights: $4 \times 64 = 256$
* Biases: $64$
$$\text{Params}_1 = 256 + 64 = \mathbf{320}$$

#### Layer 2: Hidden 1 (64) $\to$ Dense(64)
* $N_{\text{in}} = 64, \quad N_{\text{out}} = 64$
* Weights: $64 \times 64 = 4096$
* Biases: $64$
$$\text{Params}_2 = 4096 + 64 = \mathbf{4160}$$

#### Layer 3: Hidden 2 (64) $\to$ Output ($\mathbb{R}^2$)
* $N_{\text{in}} = 64, \quad N_{\text{out}} = 2$ (representing $Q(s, \text{Left})$ and $Q(s, \text{Right})$)
* Weights: $64 \times 2 = 128$
* Biases: $2$
$$\text{Params}_3 = 128 + 2 = \mathbf{130}$$

---

#### Total Trainable Parameters $\|\theta\|$:
$$\|\theta\| = \text{Params}_1 + \text{Params}_2 + \text{Params}_3$$
$$\|\theta\| = 320 + 4160 + 130$$
$$\boxed{\|\theta\| = 4610 \text{ trainable parameters}}$$

---

### (b) Architectural Design Questions (Slide 26)

#### 1. Why are there two outputs rather than one?
* **Alternative 1 (Naive design):** Input state $s$ AND action $a$ $\to$ output scalar $Q(s, a)$.
  * To find the greedy action $\arg\max_a Q(s, a)$, you would have to execute $|A|$ separate forward passes through the network!
* **DQN Design (Mnih et al., 2015):** Input state $s$ only $\to$ output a vector of $|A|$ values simultaneously:
  $$\mathbf{Q}(s) = \big[Q(s, a_1), Q(s, a_2), \dots, Q(s, a_{|A|})\big]$$
  * With a **single forward pass**, the agent obtains the action values for *all* actions at once. 
  * Computing the greedy action $\arg\max_a Q(s, a)$ is an instantaneous $\mathcal{O}(1)$ operation.

#### 2. Why do we NOT apply a Softmax layer to the outputs of a DQN?
* **$Q$-values are NOT probabilities:** $Q(s, a)$ represents the **expected cumulative discounted return**, which can take any real value in $(-\infty, +\infty)$ (e.g., $+855$, $-1060$, or $+0.808$).
* A Softmax function squashes numbers into a probability distribution between $0$ and $1$ that must sum to $1.0$.
* If you applied Softmax to $Q$-values:
  * It would completely destroy their scale and absolute magnitude.
  * You could no longer compute valid Bellman error targets $r + \gamma \max_{a'} Q(s', a')$.
  * Softmax belongs in **Policy Gradient methods** (which output action probabilities $\pi(a \mid s)$), **never in Q-Networks**.

---

## Q44. [Bank Q93] Single-Transition DQN Target, Error, and Squared Loss Calculation

### Prompt:
Suppose for a transition $(s, a, r, s', d_{\text{term}})$, the agent took action $a = \text{Left}$, received reward $r = 2$, and landed in a non-terminal state $s'$ ($d_{\text{term}} = 0$) with discount factor $\gamma = 0.9$. The online network outputs $Q_\theta(s, \text{Left}) = 4.0$ and $Q_\theta(s, \text{Right}) = 7.0$, while the target network outputs $Q_{\bar{\theta}}(s', \text{Left}) = 3.0$ and $Q_{\bar{\theta}}(s', \text{Right}) = 5.0$.
(a) Which of the two online network outputs (4.0 or 7.0) is used as the prediction $\hat{q}$ for this transition, and why?
(b) Compute the target $y$, the TD error $\delta = y - \hat{q}$, and the squared loss $L(\theta) = (y - \hat{q})^2$.
(c) What would $y$ and $L(\theta)$ be if this transition were terminal ($d_{\text{term}} = 1$)?

### Response:

**First, understand the two networks in DQN:**
* **Online Network ($\theta$):** Generates the prediction for the action that was *actually taken* ($\hat{q} = Q_\theta(s, a)$).
* **Target Network ($\bar{\theta}$):** Held stable to compute the regression label ($y = r + \gamma(1 - d_{\text{term}}) \max_{a'} Q_{\bar{\theta}}(s', a')$).

---

### (a) Which online network output is used as prediction $\hat{q}$?
* **Answer:** $\mathbf{4.0}$ is used.
* **Reason:** The transition specifies that the agent took action **$a = \text{Left}$**. The squared loss updates the network's prediction for the action that was actually chosen in that state:
  $$\hat{q} = Q_\theta(s, \text{Left}) = 4.0$$
* The value $Q_\theta(s, \text{Right}) = 7.0$ is completely ignored during the backpropagation step for this transition because Right was not taken.

---

### (b) Compute Target $y$, TD Error $\delta$, and Loss $L(\theta)$ when $d_{\text{term}} = 0$

1. **Regression Target $y$:**
   $$y = r + \gamma (1 - d_{\text{term}}) \max_{a'} Q_{\bar{\theta}}(s', a')$$
   $$y = 2 + 0.9 \times (1 - 0) \times \max(3.0, 5.0)$$
   $$y = 2 + 0.9 \times (5.0) = 2 + 4.5 = \mathbf{6.5}$$
   $$\boxed{y = 6.5}$$

2. **TD Error $\delta$:**
   $$\delta = y - \hat{q} = 6.5 - 4.0 = \mathbf{+2.5}$$
   $$\boxed{\delta = +2.5}$$

3. **Squared Loss $L(\theta)$:**
   $$L(\theta) = (y - \hat{q})^2 = (2.5)^2 = \mathbf{6.25}$$
   $$\boxed{L(\theta) = 6.25}$$

---

### (c) Calculations if the transition were terminal ($d_{\text{term}} = 1$)

If $d_{\text{term}} = 1$, the episode ends immediately. There is no future state, so the bootstrap term is multiplied by $(1 - 1) = 0$:

1. **Terminal Target $y$:**
   $$y = r + \gamma (1 - 1) \max_{a'} Q_{\bar{\theta}}(s', a') = r + 0 = \mathbf{2.0}$$
   $$\boxed{y_{\text{terminal}} = 2.0}$$

2. **Terminal TD Error $\delta$:**
   $$\delta = y - \hat{q} = 2.0 - 4.0 = \mathbf{-2.0}$$
   $$\boxed{\delta = -2.0}$$

3. **Terminal Squared Loss $L(\theta)$:**
   $$L(\theta) = (\delta)^2 = (-2.0)^2 = \mathbf{4.0}$$
   $$\boxed{L(\theta) = 4.0}$$

---

### Summary Table

| Quantity | Non-Terminal ($d_{\text{term}} = 0$) | Terminal ($d_{\text{term}} = 1$) |
| :--- | :---: | :---: |
| **Prediction ($\hat{q}$)** | $4.0$ | $4.0$ |
| **Target ($y$)** | $2 + 0.9(5.0) = \mathbf{6.5}$ | $2 + 0 = \mathbf{2.0}$ |
| **TD Error ($\delta$)** | $\mathbf{+2.5}$ | $\mathbf{-2.0}$ |
| **Squared Loss ($L(\theta)$)** | $\mathbf{6.25}$ | $\mathbf{4.00}$ |

---

## Q45. [Bank Q95] Why Naive Sequential Neural Q-Learning Fails (The Three Instabilities)

### Prompt:
Explain the three core difficulties of training a neural Q-network online on consecutive single transitions without replay or a target network (Slide 18): (1) correlated consecutive observations, (2) moving regression targets, and (3) the "Deadly Triad" (function approximation + bootstrapping + off-policy learning).

### Response:

**First, understand why plugging a Neural Network into Q-learning breaks down:** In standard supervised deep learning, we assume data samples are **i.i.d.** (independent and identically distributed) and target labels $y$ are **fixed**. In naive reinforcement learning, both assumptions are violated catastrophically!

---

### 1. Correlated Consecutive Observations
* **The Problem:** In consecutive physical transitions $s_t \to s_{t+1} \to s_{t+2}$, the observations are virtually identical ($s_{t+1} \approx s_t$).
* Consecutive frames in a game or positions of a robotic arm are **strongly temporally correlated**.
* **Failure Mode:** Feeding highly correlated, non-i.i.d. samples into Stochastic Gradient Descent (SGD) causes the neural network to overfit to the local region of the state space it is currently traversing, causing **catastrophic forgetting** of previously learned skills in other parts of the environment.
* **The Fix:** **Experience Replay Buffer**, which randomly shuffles and samples transitions across thousands of historical episodes, restoring the i.i.d. property.

---

### 2. Moving Regression Targets (Chasing Your Own Tail)
* **The Problem:** In supervised learning, when predicting $y = \text{cat}$, the label $y$ never changes.
* But in naive Q-learning, the regression target is:
  $$y = r + \gamma \max_{a'} Q_\theta(s', a')$$
* Notice that the target $y$ is computed using the **very same network weights $\theta$ that are being updated by gradient descent!**
* **Failure Mode:** Whenever you update $\theta$ to make $Q_\theta(s, a)$ closer to $y$, the target $y$ moves too! It is like a dog trying to catch its own tail. This non-stationary feedback loop causes severe oscillations or divergence.
* **The Fix:** **Target Network ($Q_{\bar{\theta}}$)**, which freezes a copy of the weights $\bar{\theta}$ for thousands of steps to provide stable, stationary targets.

---

### 3. The "Deadly Triad" (Sutton & Barto)
The Deadly Triad is the dangerous theoretical combination of three elements:
1. **Function Approximation:** Using non-linear neural networks to represent values.
2. **Bootstrapping:** Updating values based on other estimated values ($r + \gamma Q(s')$) rather than true Monte Carlo returns.
3. **Off-Policy Learning:** Training on transitions generated by an exploratory policy that differs from the greedy target policy.

* **Failure Mode:** When all three conditions are present simultaneously, the contraction mapping guarantees of the Bellman operator break down. The update operator is no longer a strict contraction, causing value estimates to amplify errors recursively and **diverge to positive or negative infinity**.

---

### Summary Table

| Instability | Underlying Cause | Consequence | DQN Solution |
| :--- | :--- | :--- | :--- |
| **1. Correlated Data** | Sequential time-series steps are nearly identical. | Catastrophic forgetting; SGD collapses. | **Experience Replay Buffer** (Uniform random sampling). |
| **2. Moving Targets** | Target $y$ depends on changing weights $\theta$. | Non-stationary oscillations; chasing own tail. | **Separate Target Network** ($\bar{\theta}$ held fixed). |
| **3. Deadly Triad** | Bootstrapping + Function Approx + Off-Policy. | Bellman contraction fails; values diverge to $\pm \infty$. | **Replay + Target Network + Gradient Clipping**. |

---

## Q46. [Bank Q97] Gymnasium Practical Detail — `terminated` vs. `truncated`

### Prompt:
Slide 20 highlights a critical distinction in modern Gymnasium environments (such as CartPole-v1, which truncates at 500 steps): "Gymnasium reports `terminated` and `truncated` separately. A time-limit truncation generally does not zero out the bootstrap term." Explain the physical difference between pole-angle failure (`terminated=True`) and hitting the 500-step time clock (`truncated=True`), and explain what goes wrong mathematically if a student sets $d_{\text{term}} = \text{terminated or truncated}$ when building the target $y$.

### Response:

**First, understand why Gymnasium split `done` into two flags:** In older Gym versions, there was only one boolean: `done = True`. But an episode can stop for two completely different reasons: either the agent failed/won the task, or the simulation clock simply ran out of time!

---

### 1. Physical Difference: `terminated` vs. `truncated`

* **`terminated = True` (True MDP Terminal State):**
  * The agent reached an intrinsic terminal absorbing state dictated by the physics of the MDP.
  * In CartPole-v1: The pole tilted beyond $\pm 12^\circ$ or the cart moved off the screen ($\pm 2.4$ units).
  * **Physical meaning:** The cart crashed. The task is over. **There are literally no future rewards possible.**

* **`truncated = True` (Artificial Horizon / Clock Timeout):**
  * The environment has an artificial safety limit (e.g., maximum 500 steps).
  * At step 500, the pole is still perfectly upright, balanced, and healthy. The environment stops only because the programmer set `max_episode_steps=500`.
  * **Physical meaning:** If the clock had allowed it, the cart could have easily continued balancing for another 10,000 steps! **Future value is NOT zero.**

---

### 2. What Goes Wrong Mathematically if $d_{\text{term}} = \text{terminated or truncated}$?

Recall the DQN target formula:
$$y = r + \gamma (1 - d_{\text{term}}) \max_{a'} Q(s', a')$$

#### If the student wrongly sets $d_{\text{term}} = \text{terminated or truncated}$:
When the agent successfully survives to step 500, `truncated = True`, causing $d_{\text{term}} = 1$.
The target calculation becomes:
$$y = r + \gamma(1 - 1) \max_{a'} Q(s', a') = r + 0 = \mathbf{1.0}$$

#### The Mathematical Disaster:
1. At step 499, the state value was estimated at:
   $$Q(s_{499}) \approx \sum_{k=0}^{100} \gamma^k \approx 10.0$$
2. But at step 500, because the student zeroed out the bootstrap term, the network is trained toward a target of:
   $$y = 1.0$$
3. **The student has just penalized the agent for surviving!**
   * The network is taught that reaching step 500 causes a catastrophic drop in value (from $10.0$ down to $1.0$).
   * An agent trained this way can learn perverse behavior: it might deliberately crash at step 490 to avoid the "catastrophic cliff" at step 500!

#### The Mathematically Correct Target:
$$d_{\text{term}} = \mathbf{terminated} \quad (\text{Ignore truncation for bootstrapping!})$$
$$y = \begin{cases} r, & \text{if terminated = True (Crashed)} \\ r + \gamma \max_{a'} Q(s', a'), & \text{if truncated = True (Healthy, clock ran out)} \end{cases}$$

---

### Summary Table

| Flag | Meaning | Future Potential | Should Bootstrap Term be Zeroed Out? |
| :--- | :--- | :---: | :---: |
| **`terminated = True`** | Cart crashed / pole fell. | Exactly $0$ | **YES: $(1 - 1) = 0$** |
| **`truncated = True`** | Hit 500-step clock timeout. | High ($V(s') \approx 10.0$) | **NO: Keep bootstrap $\gamma Q(s', a')$!** |
