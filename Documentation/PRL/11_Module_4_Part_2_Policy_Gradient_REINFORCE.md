# Section 11: Module 4 (Part 2) — Policy Gradient Methods & the REINFORCE Algorithm

---

## Q47. [Bank Q101] Architectural Comparison — Value-Based (DQN) vs. Policy-Based (REINFORCE)

### Prompt:
Compare Value-Based methods (e.g., DQN) and Policy-Based methods (e.g., REINFORCE) across the five architectural dimensions in Table 1 of `Reinforce Class Notes.pdf`: (a) Network Output, (b) Action Spaces (discrete vs. continuous), (c) Stochastic Policies (and why games like Rock-Paper-Scissors require stochastic policies), (d) Convergence properties, and (e) Sample Efficiency.

### Response:

**First, understand the paradigm shift:** 
* **Value-based (DQN):** Learns how good each action is ($Q(s, a)$), then picks the highest one greedily.
* **Policy-based (REINFORCE):** Directly optimizes the policy $\pi_\theta(a \mid s)$ without needing a value function intermediary!

---

### Detailed Comparison Across the 5 Dimensions

#### (a) Network Output
* **Value-Based (DQN):** Outputs a vector of real numbers representing action-values:
  $$\mathbf{Q}(s) = [Q(s, a_1), Q(s, a_2), \dots, Q(s, a_n)]^\top \in \mathbb{R}^{|A|}$$
* **Policy-Based (REINFORCE):** Outputs a parameterized probability distribution over actions:
  $$\pi_\theta(a \mid s) = \Pr(A_t = a \mid S_t = s)$$
  (Uses Softmax over logits for discrete actions; outputs Gaussian mean $\mu(s)$ and variance $\sigma^2(s)$ for continuous actions).

#### (b) Action Spaces (Discrete vs. Continuous)
* **Value-Based (DQN):** Naturally restricted to **discrete** action spaces.
  * In continuous action spaces (e.g., torques $\in \mathbb{R}^6$), finding the greedy action requires solving $\max_a Q(s, a)$, which is an intractable non-convex optimization problem at every time step.
* **Policy-Based (REINFORCE):** Seamlessly handles **both discrete and continuous** action spaces.
  * For continuous control, the network simply outputs the parameters of a continuous PDF (e.g., $\mu_\theta(s), \sigma_\theta(s)$) and samples directly.

#### (c) Stochastic Policies & Rock-Paper-Scissors
* **Value-Based (DQN):** Inherently deterministic. It always chooses $a = \arg\max_a Q(s, a)$ (or uniform random during $\varepsilon$ exploration). It cannot learn an intentional mixed/stochastic strategy.
* **Policy-Based (REINFORCE):** Can learn arbitrary **stochastic policies** directly.
* **Why Rock-Paper-Scissors requires a stochastic policy:**
  * In zero-sum imperfect information games like Rock-Paper-Scissors, any deterministic policy is 100% exploitable! (If you always play Rock, your opponent always plays Paper and you lose every game).
  * The unique Nash Equilibrium is a stochastic mixed strategy:
    $$\pi(\text{Rock}) = \frac{1}{3}, \quad \pi(\text{Paper}) = \frac{1}{3}, \quad \pi(\text{Scissors}) = \frac{1}{3}$$
  * A policy gradient method can converge naturally to this exact mixed probability distribution; a DQN cannot.

#### (d) Convergence Properties
* **Value-Based (DQN):** Has **no general convergence guarantees** when combined with non-linear neural networks (subject to the Deadly Triad; values can oscillate or diverge).
* **Policy-Based (REINFORCE):** **Guaranteed to converge to at least a local optimum** of the expected return objective $J(\theta)$ via standard gradient ascent:
  $$\theta \leftarrow \theta + \alpha \nabla_\theta J(\theta)$$

#### (e) Sample Efficiency
* **Value-Based (DQN):** **High sample efficiency.** Off-policy algorithm; can store transitions in an Experience Replay Buffer and reuse each sample hundreds of times across training.
* **Policy-Based (REINFORCE):** **Low sample efficiency.** Strictly on-policy Monte Carlo algorithm; samples must be collected under the current policy $\pi_\theta$, used once to compute the gradient, and then discarded immediately.

---

### Master Comparison Table (Table 1 from Class Notes)

| Dimension | Value-Based (DQN) | Policy-Based (REINFORCE) |
| :--- | :--- | :--- |
| **(a) Output** | Unbounded action-values $Q(s, a) \in \mathbb{R}$. | Action probability distribution $\pi_\theta(a \mid s) \in [0, 1]$. |
| **(b) Action Spaces** | Discrete only (Intractable continuous $\max_a$). | **Both Discrete and Continuous** action spaces. |
| **(c) Stochastic Policies** | No (Deterministic $\arg\max$; fails at bluffing/RPS). | **Yes** (Naturally learns mixed Nash equilibria). |
| **(d) Convergence** | No guarantee with deep nets (Deadly Triad). | **Guaranteed local optimum** via gradient ascent. |
| **(e) Sample Efficiency** | **High** (Off-policy, Experience Replay). | **Low** (On-policy, single-use trajectories). |

---

## Q48. [Bank Q102 & Q103] Policy Gradient Theorem & Model-Free Dynamics Proof

### Prompt:
Starting from $J(\theta) = E_{\tau \sim \pi_\theta}[R(\tau)] = \int P(\tau; \theta) R(\tau) d\tau$:
(a) Explain why $\nabla_\theta$ cannot simply be moved inside the expectation as in supervised learning, and apply the Log-Derivative Identity ($\nabla_\theta f(\theta) = f(\theta) \nabla_\theta \log f(\theta)$) to derive $\nabla_\theta J(\theta) = E_{\tau \sim \pi_\theta}[\nabla_\theta \log P(\tau; \theta) R(\tau)]$.
(b) Given $P(\tau; \theta) = \rho_0(s_0) \prod_{t=0}^{T-1} \pi_\theta(a_t \mid s_t) \mathcal{P}(s_{t+1} \mid s_t, a_t)$, take the natural logarithm and apply $\nabla_\theta$ to prove step by step that both $\rho_0(s_0)$ and $\mathcal{P}(s_{t+1} \mid s_t, a_t)$ vanish identically, establishing the model-free property.

### Response:

**First, understand the fundamental mathematical challenge:** In supervised learning, the data distribution is fixed. In reinforcement learning, changing the policy parameters $\theta$ changes which states and trajectories the agent visits! That makes finding the gradient tricky—until the log-derivative trick solves it.

---

### (a) Deriving the Policy Gradient via the Log-Derivative Trick

#### 1. Why can't we simply move $\nabla_\theta$ inside the expectation?
In supervised learning:
$$J(\theta) = \mathbb{E}_{x \sim \mathcal{D}} [L(f_\theta(x), y)]$$
Here, the data distribution $\mathcal{D}$ has zero dependence on $\theta$. Thus $\nabla_\theta \mathbb{E}[\dots] = \mathbb{E}[\nabla_\theta \dots]$.

In Reinforcement Learning:
$$J(\theta) = \mathbb{E}_{\tau \sim \pi_\theta}[R(\tau)] = \int P(\tau; \theta) R(\tau) d\tau$$
Notice that the **probability distribution itself ($P(\tau; \theta)$) depends on $\theta$**!
Differentiating directly gives:
$$\nabla_\theta J(\theta) = \int \nabla_\theta P(\tau; \theta) R(\tau) d\tau$$
This integral **is NOT an expectation over $P(\tau; \theta)$** because $\nabla_\theta P$ is not a valid probability distribution! You cannot evaluate this integral using standard Monte Carlo sampling.

---

#### 2. The Log-Derivative Identity (Likelihood Ratio Trick):
From basic calculus:
$$\nabla_\theta \log f(\theta) = \frac{\nabla_\theta f(\theta)}{f(\theta)} \implies \nabla_\theta f(\theta) = f(\theta) \nabla_\theta \log f(\theta)$$

#### 3. Substitute into the Integral:
Replace $\nabla_\theta P(\tau; \theta)$ with $P(\tau; \theta) \nabla_\theta \log P(\tau; \theta)$:
$$\nabla_\theta J(\theta) = \int \Big[P(\tau; \theta) \nabla_\theta \log P(\tau; \theta)\Big] R(\tau) d\tau$$

Notice that $P(\tau; \theta)$ is restored! This is now the definition of an expectation:
$$\boxed{\nabla_\theta J(\theta) = \mathbb{E}_{\tau \sim \pi_\theta}\big[\nabla_\theta \log P(\tau; \theta) R(\tau)\big]} \quad \text{(Q.E.D.)}$$

---

### (b) Proof that Environmental Dynamics Vanish (The Model-Free Property)

A trajectory $\tau = (s_0, a_0, s_1, a_1, \dots, s_T)$ has probability:
$$P(\tau; \theta) = \rho_0(s_0) \prod_{t=0}^{T-1} \pi_\theta(a_t \mid s_t) \mathcal{P}(s_{t+1} \mid s_t, a_t)$$

#### Step 1: Take the natural logarithm ($\ln$ or $\log$):
The log turns the product into a sum of logs:
$$\log P(\tau; \theta) = \log \rho_0(s_0) + \sum_{t=0}^{T-1} \log \pi_\theta(a_t \mid s_t) + \sum_{t=0}^{T-1} \log \mathcal{P}(s_{t+1} \mid s_t, a_t)$$

#### Step 2: Apply the gradient operator $\nabla_\theta$:
Differentiate term by term with respect to the network weights $\theta$:
$$\nabla_\theta \log P(\tau; \theta) = \nabla_\theta \log \rho_0(s_0) + \nabla_\theta \sum_{t=0}^{T-1} \log \pi_\theta(a_t \mid s_t) + \nabla_\theta \sum_{t=0}^{T-1} \log \mathcal{P}(s_{t+1} \mid s_t, a_t)$$

Now analyze each term:
1. $\rho_0(s_0)$ is the initial state distribution of the environment. It does **not depend on** $\theta$:
   $$\nabla_\theta \log \rho_0(s_0) = \mathbf{0}$$
2. $\mathcal{P}(s_{t+1} \mid s_t, a_t)$ is the environment transition dynamics (physics/nature). It does **not depend on** $\theta$:
   $$\nabla_\theta \log \mathcal{P}(s_{t+1} \mid s_t, a_t) = \mathbf{0}$$

#### Step 3: Conclusion:
Both environmental terms vanish identically!
$$\boxed{\nabla_\theta \log P(\tau; \theta) = \sum_{t=0}^{T-1} \nabla_\theta \log \pi_\theta(a_t \mid s_t)}$$

Substitute this back into the policy gradient:
$$\boxed{\nabla_\theta J(\theta) = \mathbb{E}_{\tau \sim \pi_\theta}\left[ \left(\sum_{t=0}^{T-1} \nabla_\theta \log \pi_\theta(a_t \mid s_t)\right) R(\tau) \right]}$$

#### Why is this profound?
We can compute the exact gradient of expected return in a completely unknown, black-box environment **without knowing the transition probabilities $\mathcal{P}$ or initial state distribution $\rho_0$!** This proves mathematically that Policy Gradient is a **strictly model-free** algorithm.

---

## Q49. [Bank Q104] Verifying the REINFORCE Execution Trace & Surrogate Loss (Table 2, $\gamma = 1$)

### Prompt:
Consider the 3-step episode trace:
* $t = 0$: State $S_0$, Action $a_0 = 1$, Scalar Prob $P_0 = 0.70$, Reward $R_1 = -1$
* $t = 1$: State $S_1$, Action $a_1 = 2$, Scalar Prob $P_1 = 0.65$, Reward $R_2 = -100$
* $t = 2$: State $S_2$, Action $a_2 = 4$, Scalar Prob $P_2 = 0.40$, Reward $R_3 = -1$
* $t = 3$: State $S_3$ (Terminal), $R_4 = 0$
(a) Verify the backward return accumulation values $G_3, G_2, G_1, G_0$.
(b) Compute the exact numerical value of the surrogate loss $L(\theta) = -\sum_{t=0}^2 \ln(P_t) \cdot G_t$ (rounded to 4 decimal places).
(c) Explain how the negative returns $G_0, G_1, G_2 < 0$ affect the probabilities $P_0, P_1, P_2$ when a gradient descent optimizer minimizes $L(\theta)$.

### Response:

**First, understand the REINFORCE objective:**
In deep learning, optimizers (like Adam or SGD) perform **gradient descent** to *minimize* a loss. To maximize expected return $J(\theta)$ via gradient ascent, we define the **surrogate loss** as the negative objective:
$$L(\theta) = -\sum_{t=0}^{T-1} \ln\big(\pi_\theta(a_t \mid s_t)\big) \cdot G_t$$

---

### (a) Verify Backward Return Accumulation ($\gamma = 1$)

Using backward recursion $G_t = R_{t+1} + G_{t+1}$ with terminal state $G_3 = 0$:
1. **At** $t = 3$ **(Terminal):**
   $$\boxed{G_3 = 0}$$
2. **At** $t = 2$ ($S_2 \to S_3$ **with** $R_3 = -1$):
   $$G_2 = R_3 + G_3 = -1 + 0 = \mathbf{-1}$$
   $$\boxed{G_2 = -1}$$
3. **At** $t = 1$ ($S_1 \to S_2$ **with** $R_2 = -100$):
   $$G_1 = R_2 + G_2 = -100 + (-1) = \mathbf{-101}$$
   $$\boxed{G_1 = -101}$$
4. **At** $t = 0$ ($S_0 \to S_1$ **with** $R_1 = -1$):
   $$G_0 = R_1 + G_1 = -1 + (-101) = \mathbf{-102}$$
   $$\boxed{G_0 = -102}$$

---

### (b) Compute Exact Numerical Value of Surrogate Loss $L(\theta)$

$$L(\theta) = -\Big[\ln(P_0) G_0 + \ln(P_1) G_1 + \ln(P_2) G_2\Big]$$

#### 1. Evaluate Natural Logarithms:
* $\ln(P_0) = \ln(0.70) \approx -0.356675$
* $\ln(P_1) = \ln(0.65) \approx -0.430783$
* $\ln(P_2) = \ln(0.40) \approx -0.916291$

#### 2. Multiply by Returns $G_t$:
* **Term 0 ($t = 0$):**
  $$\ln(P_0) \cdot G_0 = (-0.356675) \times (-102) = +36.38085$$
* **Term 1 ($t = 1$):**
  $$\ln(P_1) \cdot G_1 = (-0.430783) \times (-101) = +43.50908$$
* **Term 2 ($t = 2$):**
  $$\ln(P_2) \cdot G_2 = (-0.916291) \times (-1) = +0.91629$$

#### 3. Sum and Apply Leading Negative Sign:
$$\text{Inner Sum} = 36.38085 + 43.50908 + 0.91629 = +80.80622$$
$$L(\theta) = -(\text{Inner Sum}) = -80.80622$$
$$\boxed{L(\theta) \approx -80.8062}$$

---

### (c) How Negative Returns Affect Probabilities Under Gradient Descent

#### The Gradient Descent Update:
The optimizer updates weights via:
$$\theta \leftarrow \theta - \alpha \nabla_\theta L(\theta)$$

Differentiating the surrogate loss:
$$\nabla_\theta L(\theta) = -\sum_{t=0}^2 G_t \nabla_\theta \ln P_t$$
Substituting into the update:
$$\theta \leftarrow \theta + \alpha \sum_{t=0}^2 G_t \nabla_\theta \ln P_t$$

#### Physical & Mathematical Effect:
* Notice that all returns are negative: $G_0 = -102 < 0$, $G_1 = -101 < 0$, and $G_2 = -1 < 0$.
* When $G_t < 0$, the update adds a **negative gradient**, which pushes the network weights in the direction that **DECREASES** $\ln P_t$.
* Therefore, the optimizer **actively reduces the selection probabilities** $P_0, P_1, P_2$ of actions $a_0, a_1, a_2$.
* The catastrophic crash penalty at step 1 ($G_1 = -101, G_0 = -102$) exerts immense downward pressure, teaching the policy to avoid selecting Action 1 in $S_0$ and Action 2 in $S_1$ in future episodes!

---

## Q50. [Bank Q108 & Q109] Unbiasedness of State-Dependent Baselines & PyTorch Sign Bug

### Prompt:
(a) Prove Theorem 7.1: show mathematically that subtracting any state-dependent baseline $b(s_t)$ that does not depend on the action $a_t$ satisfies $E_{a_t \sim \pi_\theta}[\nabla_\theta \log \pi_\theta(a_t \mid s_t) b(s_t)] = 0$, and compute the standardized returns $\tilde{G} = (G - \mu_G) / \sigma_G$ for $G = [10.0, 20.0, 30.0]$ (using sample standard deviation $\sigma_G$).
(b) A student implements REINFORCE in PyTorch using Adam and writes `loss = torch.sum(log_probs * returns)` instead of `loss = -torch.sum(log_probs * returns)`. Assuming all returns $G_t > 0$ are positive, explain mathematically using the gradient descent update rule $\theta \leftarrow \theta - \alpha \nabla_\theta \text{loss}$ what happens to $\log \pi_\theta(a_t \mid s_t)$ and the resulting policy during training.

### Response:

**First, understand the two big concepts here:**
1. A **baseline** reduces variance without introducing any bias.
2. The **negative sign** in PyTorch turns gradient descent (minimizing loss) into gradient ascent (maximizing reward). Forgetting it is a fatal bug!

---

### (a) Proof of Theorem 7.1 (Unbiasedness of Baseline)

We want to prove that:
$$\mathbb{E}_{a_t \sim \pi_\theta}\big[\nabla_\theta \log \pi_\theta(a_t \mid s_t) \cdot b(s_t)\big] = 0$$

#### Step-by-Step Mathematical Proof:
1. Write the expectation explicitly as a discrete sum over all actions:
   $$\mathbb{E}_{a_t \sim \pi_\theta}\big[\nabla_\theta \log \pi_\theta(a_t \mid s_t) \cdot b(s_t)\big] = \sum_{a_t \in A} \pi_\theta(a_t \mid s_t) \Big[\nabla_\theta \log \pi_\theta(a_t \mid s_t) \cdot b(s_t)\Big]$$
2. Apply the log-derivative identity in reverse ($\pi \nabla \log \pi = \nabla \pi$):
   $$\pi_\theta(a_t \mid s_t) \nabla_\theta \log \pi_\theta(a_t \mid s_t) = \nabla_\theta \pi_\theta(a_t \mid s_t)$$
3. Substitute this into the sum:
   $$= \sum_{a_t \in A} \nabla_\theta \pi_\theta(a_t \mid s_t) \cdot b(s_t)$$
4. Because the baseline $b(s_t)$ **does not depend on action $a_t$**, we pull $b(s_t)$ outside the summation:
   $$= b(s_t) \sum_{a_t \in A} \nabla_\theta \pi_\theta(a_t \mid s_t)$$
5. By linearity of differentiation, pull the gradient operator $\nabla_\theta$ outside the sum:
   $$= b(s_t) \nabla_\theta \left[\sum_{a_t \in A} \pi_\theta(a_t \mid s_t)\right]$$
6. Because $\pi_\theta(\cdot \mid s_t)$ is a valid probability distribution, **its sum over all actions is identically 1**:
   $$\sum_{a_t \in A} \pi_\theta(a_t \mid s_t) = 1.0$$
7. The gradient of the constant $1$ is identically zero:
   $$= b(s_t) \nabla_\theta [1] = b(s_t) \times \mathbf{0} = \mathbf{0} \quad \text{(Q.E.D.)}$$

---

### Numerical Return Standardization for $G = [10.0, 20.0, 30.0]$

1. **Mean** ($\mu_G$):
   $$\mu_G = \frac{10.0 + 20.0 + 30.0}{3} = \frac{60.0}{3} = \mathbf{20.0}$$

2. **Sample Standard Deviation** ($\sigma_G$ **with** $N-1 = 2$ **degrees of freedom):**
   $$s^2 = \frac{(10 - 20)^2 + (20 - 20)^2 + (30 - 20)^2}{3 - 1} = \frac{(-10)^2 + 0^2 + (10)^2}{2} = \frac{100 + 100}{2} = 100.0$$
   $$\sigma_G = \sqrt{100.0} = \mathbf{10.0}$$

3. **Standardized Returns** $\tilde{G}_i = \frac{G_i - \mu_G}{\sigma_G}$:
   * $\tilde{G}_1 = \frac{10.0 - 20.0}{10.0} = \frac{-10.0}{10.0} = \mathbf{-1.0}$
   * $\tilde{G}_2 = \frac{20.0 - 20.0}{10.0} = \frac{0.0}{10.0} = \mathbf{0.0}$
   * $\tilde{G}_3 = \frac{30.0 - 20.0}{10.0} = \frac{+10.0}{10.0} = \mathbf{+1.0}$

$$\boxed{\tilde{G} = [-1.0, \; 0.0, \; +1.0]}$$

---

### (b) The Missing Minus Sign Bug in PyTorch

#### The Mathematical Anatomy of the Bug:
In PyTorch, the student writes:
$$\text{loss} = \sum_t \log \pi_\theta(a_t \mid s_t) \cdot G_t$$
The PyTorch optimizer (Adam/SGD) updates network parameters using standard **gradient descent**:
$$\theta \leftarrow \theta - \alpha \nabla_\theta \text{loss}$$

Compute the gradient of the student's buggy loss:
$$\nabla_\theta \text{loss} = \sum_t G_t \nabla_\theta \log \pi_\theta(a_t \mid s_t)$$

Substitute this into the optimizer update rule:
$$\theta \leftarrow \theta - \alpha \sum_t G_t \nabla_\theta \log \pi_\theta(a_t \mid s_t)$$

#### What Happens to $\log \pi_\theta(a_t \mid s_t)$ and the Policy?
* We are given that all returns $G_t > 0$ are positive (e.g., $+10, +20, +30$).
* In correct RL, actions that yield positive returns should have their probabilities **increased** (gradient ascent).
* But look at the negative sign in the update: $-\alpha G_t \nabla_\theta \log \pi$.
* The optimizer moves in the **opposite direction** of the gradient, actively **subtracting probability mass from the very actions that produced high positive rewards!**
* **The Catastrophic Result:**
  $$\boxed{\text{The policy actively minimizes expected return, learning the worst possible behavior!}}$$
* Instead of learning to balance the pole or win the game, the agent learns to crash immediately, seeking out lowest possible rewards.
* **The Fix:** Always write `loss = -torch.sum(log_probs * returns)` to invert the gradient for descent optimizers!
