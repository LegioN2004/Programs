# Section 8: Module 3 (Part 3) — Temporal Difference Learning, SARSA & Q-Learning

---

## Q33. [Bank Q71] Two-Step Sequential TD(0) Update Trace

### Prompt:
An agent traverses three states $S_A \to S_B \to S_C$ with learning rate $\alpha = 0.2$ and discount factor $\gamma = 0.9$. Before the transitions, the state-value table is initialized to $V(S_A) = 4.0, V(S_B) = 6.0$, and $V(S_C) = 10.0$.
* **Step 1:** The agent transitions $S_A \to S_B$ and receives reward $R_1 = +3$; compute the TD target, TD error $\delta_0$, and updated value $V(S_A)$.
* **Step 2:** The agent transitions $S_B \to S_C$ and receives reward $R_2 = -1$; compute the TD target, TD error $\delta_1$, and updated value $V(S_B)$.

### Response:

**First, understand the TD(0) update rule:** Temporal Difference learning updates the current state value immediately after taking a single step, without waiting for the episode to finish:

$$\text{TD Target} = R_{t+1} + \gamma V(S_{t+1})$$
$$\text{TD Error: } \delta_t = \text{Target} - V(S_t) = [R_{t+1} + \gamma V(S_{t+1})] - V(S_t)$$
$$\text{Update: } V(S_t) \leftarrow V(S_t) + \alpha \delta_t$$

Given parameters: $\alpha = 0.2, \gamma = 0.9$. Initial table: $V(S_A) = 4.0, V(S_B) = 6.0, V(S_C) = 10.0$.

---

### Step 1: Transition $S_A \to S_B$ with Reward $R_1 = +3$

1. **Compute TD Target:**
   $$\text{Target}_0 = R_1 + \gamma V(S_B) = 3 + 0.9 \times (6.0) = 3 + 5.4 = \mathbf{8.4}$$
   $$\boxed{\text{TD Target}_0 = 8.4}$$

2. **Compute TD Error $\delta_0$:**
   $$\delta_0 = \text{Target}_0 - V(S_A) = 8.4 - 4.0 = \mathbf{+4.4}$$
   $$\boxed{\delta_0 = +4.4}$$

3. **Compute Updated Value $V(S_A)$:**
   $$V(S_A) \leftarrow V(S_A) + \alpha \delta_0 = 4.0 + 0.2 \times (4.4) = 4.0 + 0.88 = \mathbf{4.88}$$
   $$\boxed{V(S_A) = 4.88}$$

---

### Step 2: Transition $S_B \to S_C$ with Reward $R_2 = -1$

1. **Compute TD Target:**
   $$\text{Target}_1 = R_2 + \gamma V(S_C) = -1 + 0.9 \times (10.0) = -1 + 9.0 = \mathbf{8.0}$$
   $$\boxed{\text{TD Target}_1 = 8.0}$$

2. **Compute TD Error $\delta_1$:**
   $$\delta_1 = \text{Target}_1 - V(S_B) = 8.0 - 6.0 = \mathbf{+2.0}$$
   $$\boxed{\delta_1 = +2.0}$$

3. **Compute Updated Value $V(S_B)$:**
   $$V(S_B) \leftarrow V(S_B) + \alpha \delta_1 = 6.0 + 0.2 \times (2.0) = 6.0 + 0.40 = \mathbf{6.40}$$
   $$\boxed{V(S_B) = 6.40}$$

---

### Sequential Trace Summary Table

| Step | Transition | Reward ($R$) | Old Value | TD Target | TD Error ($\delta$) | New Value |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Step 1** | $S_A \to S_B$ | $+3$ | $V(S_A) = 4.0$ | $3 + 0.9(6.0) = \mathbf{8.4}$ | $8.4 - 4.0 = \mathbf{+4.4}$ | **$V(S_A) = 4.88$** |
| **Step 2** | $S_B \to S_C$ | $-1$ | $V(S_B) = 6.0$ | $-1 + 0.9(10.0) = \mathbf{8.0}$ | $8.0 - 6.0 = \mathbf{+2.0}$ | **$V(S_B) = 6.40$** |

---

## Q34. [Bank Q72] Bootstrapping — Monte Carlo vs. Temporal Difference

### Prompt:
Define bootstrapping in reinforcement learning. Using the update equations $V(S_t) \leftarrow V(S_t) + \alpha[G_t - V(S_t)]$ and $V(S_t) \leftarrow V(S_t) + \alpha[R_{t+1} + \gamma V(S_{t+1}) - V(S_t)]$, explain why TD learning can update online at every step of a continuing (non-terminating) task whereas Monte Carlo cannot.

### Response:

**First, understand the meaning of bootstrapping:** In everyday English, "pulling yourself up by your own bootstraps" means accomplishing something without external help. In RL, **bootstrapping means updating an estimate using another existing estimate**, rather than waiting for the true actual outcome.

---

### 1. Definition of Bootstrapping in RL
> **Bootstrapping** occurs whenever a learning algorithm updates its value estimate for the current state $S_t$ using the current value estimate of a successor state $V(S_{t+1})$ as part of its target.

---

### 2. Comparison of Update Equations

* **Monte Carlo (MC) Update (No Bootstrapping):**
  $$V(S_t) \leftarrow V(S_t) + \alpha \big[G_t - V(S_t)\big]$$
  where the return is the full sum of all future rewards:
  $$G_t = R_{t+1} + \gamma R_{t+2} + \gamma^2 R_{t+3} + \dots + \gamma^{T-t-1} R_T$$

* **Temporal Difference (TD) Update (Bootstrapping):**
  $$V(S_t) \leftarrow V(S_t) + \alpha \big[\underbrace{R_{t+1} + \gamma V(S_{t+1})}_{\text{TD Target}} - V(S_t)\big]$$

---

### 3. Why TD Can Update Online in Continuing Tasks while MC Cannot

#### The Monte Carlo Bottleneck:
* Look at the MC target: $G_t = \sum_{k=0}^{T-t-1} \gamma^k R_{t+k+1}$.
* To compute $G_t$, the agent **must wait until the episode reaches terminal step $T$** so that every future reward in the trajectory is known.
* In a **continuing task** (such as server temperature control, stock trading, or factory regulation), the system runs indefinitely ($T = \infty$). **There is no terminal state.**
* Therefore, the Monte Carlo agent waits forever for the episode to end, never computes $G_t$, and **can never make a single update!**

#### The TD Solution:
* Look at the TD target: $R_{t+1} + \gamma V(S_{t+1})$.
* To compute the TD target, the agent takes **just one single step**:
  1. It executes action $A_t$.
  2. It observes the immediate reward $R_{t+1}$ and next state $S_{t+1}$.
  3. It substitutes its *current estimate* $V(S_{t+1})$ for all remaining future rewards.
* Because it does not need to know future rewards beyond step $t+1$, TD learning updates **online, incrementally, and immediately at every single clock tick**, making it perfectly suited for infinite-horizon continuing tasks.

---

### Summary Table

| Feature | Monte Carlo (MC) | Temporal Difference (TD) |
| :--- | :--- | :--- |
| **Bootstrapping?** | **No** (Uses actual observed return $G_t$). | **Yes** (Substitutes $V(S_{t+1})$ for future return). |
| **When can it update?** | Only at the end of a completed episode. | Online, at every individual time step. |
| **Works on Continuing Tasks?** | **No** ($T = \infty \implies$ hangs forever). | **Yes** (Requires only 1-step transitions). |
| **Bias / Variance** | Zero Bias, High Variance. | Low Variance, Introduces Bootstrapping Bias. |

---

## Q35. [Bank Q74] Divergent Updates on the Same Transition (SARSA vs. Q-Learning)

### Prompt:
Suppose an agent in state $S_t$ takes action $A_t$ (with current estimate $Q(S_t, A_t) = 5.0$), receives immediate reward $R_{t+1} = -2.0$, and lands in state $S'$ where $Q(S', A_1) = 4.0, Q(S', A_2) = 12.0$, and $Q(S', A_3) = 8.0$. Because the behaviour policy is $\varepsilon$-greedy, the agent rolls an exploratory action and actually selects $A_{t+1} = A_1$ at state $S'$. Given $\alpha = 0.25$ and $\gamma = 0.8$:
(a) Compute the target, TD error, and updated $Q_{\text{SARSA}}(S_t, A_t)$.
(b) Compute the target, TD error, and updated $Q_{\text{Q-Learning}}(S_t, A_t)$.
(c) Under what condition on the selected next action $A_{t+1}$ would SARSA and Q-Learning produce the exact same numerical update?

### Response:

**First, understand the core difference between SARSA and Q-Learning:**
* **SARSA (On-Policy):** Looks at what the agent *actually did next* ($A_{t+1}$), even if it was a silly random exploratory mistake!
* **Q-Learning (Off-Policy):** Completely ignores what action was actually taken; it targets the *best possible action* ($\max_a Q(S', a)$).

Given setup:
* Current estimate: $Q(S_t, A_t) = 5.0$
* Reward: $R_{t+1} = -2.0$
* Landing state $S'$ values: $Q(S', A_1) = 4.0, Q(S', A_2) = 12.0, Q(S', A_3) = 8.0$
* Exploratory action rolled: $A_{t+1} = A_1$ (value $4.0$)
* Best greedy action: $A_2$ (value $12.0$)
* Hyperparameters: $\alpha = 0.25, \gamma = 0.8$

---

### (a) SARSA Update (Uses Actual Action $A_1$)

1. **Target:**
   $$\text{Target}_{\text{SARSA}} = R_{t+1} + \gamma Q(S', A_{t+1}) = -2.0 + 0.8 \times (4.0) = -2.0 + 3.2 = \mathbf{1.2}$$
   $$\boxed{\text{Target}_{\text{SARSA}} = 1.2}$$

2. **TD Error** $\delta_{\text{SARSA}}$:
   $$\delta_{\text{SARSA}} = 1.2 - Q(S_t, A_t) = 1.2 - 5.0 = \mathbf{-3.8}$$
   $$\boxed{\delta_{\text{SARSA}} = -3.8}$$

3. **Updated** $Q_{\text{SARSA}}(S_t, A_t)$:
   $$Q(S_t, A_t) \leftarrow 5.0 + 0.25 \times (-3.8) = 5.0 - 0.95 = \mathbf{4.05}$$
   $$\boxed{Q_{\text{SARSA}}(S_t, A_t) = 4.05}$$

---

### (b) Q-Learning Update (Uses Greedy Max Action $A_2$)

1. **Target:**
   $$\text{Target}_{\text{QL}} = R_{t+1} + \gamma \max_{a'} Q(S', a') = -2.0 + 0.8 \times \max(4.0, 12.0, 8.0) = -2.0 + 0.8(12.0) = -2.0 + 9.6 = \mathbf{7.6}$$
   $$\boxed{\text{Target}_{\text{QL}} = 7.6}$$

2. **TD Error** $\delta_{\text{QL}}$:
   $$\delta_{\text{QL}} = 7.6 - Q(S_t, A_t) = 7.6 - 5.0 = \mathbf{+2.6}$$
   $$\boxed{\delta_{\text{QL}} = +2.6}$$

3. **Updated** $Q_{\text{QL}}(S_t, A_t)$:
   $$Q(S_t, A_t) \leftarrow 5.0 + 0.25 \times (+2.6) = 5.0 + 0.65 = \mathbf{5.65}$$
   $$\boxed{Q_{\text{QL}}(S_t, A_t) = 5.65}$$

---

### (c) Under what condition would SARSA and Q-Learning produce the exact same update?

SARSA and Q-Learning produce identical updates if and only if:
$$Q(S', A_{t+1}) = \max_{a'} Q(S', a')$$
* **Condition:** When the action selected at the next step $A_{t+1}$ **is the greedy action** (in this case, $A_{t+1} = A_2$), or any action tied for the maximal $Q$-value ($12.0$).
* Whenever the agent exploits rather than explores, SARSA's target matches Q-Learning's target exactly.

---

### Summary Comparison Table

| Algorithm | Next Action Evaluated | TD Target | TD Error ($\delta$) | New $Q(S_t, A_t)$ | Direction of Update |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **SARSA** | $A_1$ (Exploratory, $Q = 4.0$) | **$1.2$** | **$-3.8$** | **$4.05$** | **Decreases** (penalizes for poor next action) |
| **Q-Learning** | $A_2$ (Greedy Max, $Q = 12.0$) | **$7.6$** | **$+2.6$** | **$5.65$** | **Increases** (optimistic about potential) |

---

## Q36. [Bank Q78] If the Behaviour Policy Changes Over Time, Is It Still Q-Learning?

### Prompt:
A student asks (Slide 48 of `TD.pdf`): "In Q-Learning, when $Q_t(s, a)$ is updated, our $\varepsilon$-greedy behaviour policy $\mu_t = \varepsilon\text{-greedy}(Q_t)$ changes its probabilities at the next step. Since the behaviour policy is changing based on $Q_t$, doesn't that make Q-Learning on-policy like SARSA?" Provide a rigorous explanation to resolve the student's confusion.

### Response:

**First, understand why the student is confused:** The student thinks "on-policy" means the behaviour policy adapts over time. That is a fundamental misconception!

---

### Rigorous Resolution of the Student's Confusion

The definition of **on-policy vs. off-policy** has **nothing to do with whether the behaviour policy changes over time**. It is strictly defined by the relationship between two specific policies:
1. **The Behaviour Policy ($\mu$):** The policy used to generate actions and collect experience in the environment.
2. **The Target Policy ($\pi$):** The policy being evaluated, learned, and updated mathematically in the Bellman equation.

$$\text{On-Policy: } \mu = \pi \qquad \text{vs.} \qquad \text{Off-Policy: } \mu \neq \pi$$

---

### Let Us Compare SARSA and Q-Learning Under This Criterion:

#### 1. In SARSA:
* **Behaviour Policy $\mu$:** $\varepsilon\text{-greedy}(Q)$ (it explores).
* **Target Policy $\pi$:** $\varepsilon\text{-greedy}(Q)$ (the update target is $R + \gamma Q(S', A_{t+1})$, where $A_{t+1}$ was drawn directly from $\mu$).
* Because the target policy $\pi$ **is identical** to the behaviour policy $\mu$, **SARSA is strictly On-Policy**.

#### 2. In Q-Learning:
* **Behaviour Policy $\mu$:** $\varepsilon\text{-greedy}(Q)$ (it explores with $\varepsilon > 0$).
* **Target Policy $\pi$:** Purely greedy ($\varepsilon = 0$).
* **Target Formula:** In the Q-Learning update target $\text{Target} = R + \gamma \max_{a'} Q(S', a')$, the $\max_{a'}$ operator corresponds to a target policy that chooses the optimal greedy action with 100% probability:

$$
\pi_{\text{target}}(a \mid s) = \begin{cases}
1, & a = \arg\max_{a'} Q(s, a') \\
0, & \text{otherwise}
\end{cases}
$$

* **Notice the mismatch:** Because $\mu = \varepsilon\text{-greedy} \neq \pi = \text{purely greedy}$, at *every single time step* the policy generating the data ($\varepsilon$-greedy) is mathematically different from the policy being learned (pure greedy).
* Therefore, **Q-Learning is provably, strictly Off-Policy**.

---

### Summary Table

| Algorithm | Behaviour Policy ($\mu$) | Target Policy ($\pi$) | Are $\mu$ and $\pi$ Identical? | Classification |
| :--- | :--- | :--- | :---: | :--- |
| **SARSA** | $\varepsilon$-greedy | $\varepsilon$-greedy (actual $A_{t+1}$) | **Yes** ($\mu = \pi$) | **On-Policy** |
| **Q-Learning** | $\varepsilon$-greedy | Pure Greedy ($\max_{a'} Q$) | **No** ($\mu \neq \pi$) | **Off-Policy** |

---

## Q37. [Bank Q79] Cliff-Walking Gridworld — Conservative SARSA vs. Optimistic Q-Learning

### Prompt:
In the classic Cliff-Walking gridworld (Slide 65 of `TD.pdf`), the shortest path from Start ($S$) to Goal ($G$) runs directly alongside a cliff of terminal hazard states ($X$, reward −100), while a longer path arches safely around the top of the grid (−1 per step). Assuming both agents use an $\varepsilon$-greedy behaviour policy with fixed $\varepsilon = 0.1$ during training:
(a) Which algorithm learns the safer upper route, and which learns the risky cliff-edge route?
(b) Which algorithm achieves higher online average return during training (while $\varepsilon = 0.1$ is active), and how does that change if $\varepsilon$ is set to 0 during evaluation?

### Response:

**First, visualize the Cliff-Walking Gridworld:**
```
+---+---+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   | The Safe Upper Route          |
+---+---+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
|   | The Risky Cliff-Edge Route                |
+---+---+---+---+---+---+---+---+---+---+---+---+
| S | X | X | X | X | X | X | X | X | X | X | G |  <-- Bottom Row: Cliff (Reward -100)
+---+---+---+---+---+---+---+---+---+---+---+---+
```
* **Start ($S$):** Bottom-Left.
* **Goal ($G$):** Bottom-Right.
* **The Cliff ($X$):** The 10 cells between $S$ and $G$ in the bottom row. Stepping into the cliff incurs a catastrophic penalty of **$-100$** and teleports the agent back to $S$.
* **All normal steps:** Cost $-1$.

---

### (a) Which algorithm learns which route?

* **SARSA learns the SAFER UPPER ROUTE (Conservative):**
  * Because SARSA is **on-policy**, its update target evaluates the *actual next action* taken by its $\varepsilon$-greedy policy ($A_{t+1}$).
  * If SARSA tries to walk along the cliff edge, with probability $\varepsilon = 0.10$ it will roll a random action and accidentally plunge off the cliff into the $-100$ abyss.
  * SARSA's $Q$-values directly incorporate this 10% risk of falling, making the cliff-edge tiles look terrible.
  * Therefore, SARSA learns to walk safely around the top of the grid, staying far away from the cliff edge!

* **Q-Learning learns the RISKY CLIFF-EDGE ROUTE (Optimistic):**
  * Because Q-Learning is **off-policy**, its update target uses $\max_a Q(S', a)$ (assuming it will always choose the optimal action in the future).
  * It evaluates the optimal shortest path: 12 steps along the cliff edge.
  * In theory, if you never take an exploratory mistake, walking along the cliff edge is the fastest possible route ($-1$ per step $\times 12$ steps = $-12$ total return).
  * Q-Learning assumes perfect future execution, so it converges to the cliff-edge policy.

---

### (b) Performance Comparison: Training ($\varepsilon = 0.1$) vs. Evaluation ($\varepsilon = 0$)

#### 1. During Training (with $\varepsilon = 0.10$ active exploration):
* **SARSA achieves HIGHER online average return (Wins Training):**
  * Even though SARSA's route is longer (e.g., $-1$ per step for 16 steps $\approx -16$), it rarely falls off the cliff because it maintains a safety buffer.
  * Q-Learning tries to tightrope along the cliff edge. With $\varepsilon = 0.10$, every step along the edge has a high risk of rolling a downward action and plummeting into the cliff ($-100$).
  * Consequently, Q-Learning frequently crashes during training, dragging its online average return down to roughly $-40$ to $-50$.

#### 2. During Evaluation (with $\varepsilon = 0$ purely greedy testing):
* **Q-Learning achieves HIGHER return (Wins Evaluation):**
  * When exploration is turned off ($\varepsilon = 0$), the agent never rolls random mistakes.
  * Q-Learning executes the mathematically shortest path along the cliff edge with zero crashes, achieving the optimal return: $G_{\text{optimal}} = -13$.
  * SARSA continues to take its roundabout safe detour through the top rows, earning a lower return: $G_{\text{SARSA}} = -17$.

---

### Summary Table (Important for Exams)

| Condition | SARSA (On-Policy) | Q-Learning (Off-Policy) | Winner |
| :--- | :--- | :--- | :---: |
| **Learned Route** | Safe upper path (maintains buffer). | Dangerous cliff-edge (shortest path). | — |
| **Training Return ($\varepsilon = 0.1$)** | Higher return ($\approx -16$); avoids cliff falls. | Lower return ($\approx -45$); repeatedly falls off cliff. | **SARSA** |
| **Evaluation Return ($\varepsilon = 0$)** | Suboptimal ($-17$); takes long safe detour. | **Optimal ($-13$)**; executes shortest path safely. | **Q-Learning** |
