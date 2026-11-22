# Section 6: Module 3 (Part 1) — Monte Carlo Methods

---

## Q24. [Bank Q51] The Windy Bridge — Analytic Expectation vs. Monte Carlo Sample Mean

### Prompt:
On a windy bridge ($\gamma = 1$), crossing from State $S$ reaches the Goal (+12 reward) with probability $p = 0.75$ and falls into the water (−16 reward) with probability $1 - p = 0.25$.
(a) Compute the exact model-based expected return $E[G \mid S]$ using $p$.
(b) A model-free agent does not know $p = 0.75$, so it crosses the bridge $N = 6$ times and records the finished episode returns: $[+12, -16, +12, +12, -16, +12]$. Compute the Monte Carlo estimate $\hat{V}(S)$, explain why no single episode ever observes the value +5, and state the theorem that guarantees $\hat{V}(S) \to E[G \mid S]$ as $N \to \infty$.

### Response:

**First, understand the concept:** This problem contrasts **Model-Based planning** (where you know the probabilities and calculate the theoretical expectation on paper) with **Model-Free Monte Carlo** (where you have no idea what the probabilities are, so you average actual empirical sample runs).

---

### (a) Model-Based Expected Return $E[G \mid S]$
Since $\gamma = 1$, the return is simply the immediate terminal reward:
$$E[G \mid S] = p \cdot R_{\text{goal}} + (1 - p) \cdot R_{\text{water}}$$
$$E[G \mid S] = (0.75)(+12) + (0.25)(-16)$$
$$E[G \mid S] = +9.0 - 4.0$$
$$\boxed{E[G \mid S] = +5.0}$$

---

### (b) Model-Free Monte Carlo Estimation

#### 1. Compute the Sample Mean $\hat{V}(S)$:
The agent observes $N = 6$ sample episode returns:
$$G = [+12, -16, +12, +12, -16, +12]$$

Sum of observed returns:
$$\sum_{i=1}^6 G^{(i)} = 12 - 16 + 12 + 12 - 16 + 12 = 36$$

Monte Carlo sample mean:
$$\hat{V}(S) = \frac{1}{N} \sum_{i=1}^N G^{(i)} = \frac{36}{6}$$
$$\boxed{\hat{V}(S) = +6.0}$$

---

#### 2. Why does no single episode ever observe the value +5?
* The environment has **binary discrete outcomes**: every crossing either reaches the Goal ($+12$) or falls in the water ($-16$).
* The value $+5.0$ is the **mathematical expectation** (the long-run weighted average of many trials), **not a possible state realization of any individual episode**.
* Just like flipping a fair coin where Heads $= 1$ and Tails $= 0$ has an expected value of $0.5$, you will never observe a coin land on $0.5$ in a single toss.

---

#### 3. Theorem guaranteeing convergence:
The theorem is the **Strong Law of Large Numbers (LLN)**.
It states that the sample average of independent and identically distributed (i.i.d.) random variables converges almost surely to the true mathematical expectation as the number of samples approaches infinity:
$$\Pr\left(\lim_{N \to \infty} \hat{V}_N(S) = E[G \mid S]\right) = 1$$

---

## Q25. [Bank Q52] Ground-Truth Bellman Solution on Spear World ($\gamma = 0.8$)

### Prompt:
Consider the 4-cell Spear World ($A \text{ [start]}, B, C \text{ [spear]}, G \text{ [terminal]}$) from Slide 6 of `Rl_class.pdf`, where choosing Right at $A$ goes to $B$ ($r = 0$), Right at $B$ goes to $C$ ($r = 0$), and Right at $C$ reaches $G$ ($r = +1$, terminal $v(G) = 0$) with probability 1/2 or slips back to $B$ ($r = 0$) with probability 1/2. Set up the system of linear equations for the always-Right policy with discount factor $\gamma = 0.8$ and solve for the exact ground-truth values $v(C), v(B)$, and $v(A)$ as fractions and decimals.

### Response:

**First, visualize Spear World:**
```
[ A ] ---> [ B ] ---> [ C (Spear) ] --(50%)--> [ G (Goal +1) ]
             ^              |
             +---(50% slip)-+
```
Policy: Always choose **Right**.
Discount factor: $\gamma = 0.8$.

---

### Step 1: Set up the Bellman Linear Equations

1. **At State $A$:** Deterministically moves to $B$ ($r = 0$):
   $$v(A) = 0 + \gamma v(B) \implies v(A) = 0.8 v(B)$$

2. **At State $B$:** Deterministically moves to $C$ ($r = 0$):
   $$v(B) = 0 + \gamma v(C) \implies v(B) = 0.8 v(C)$$

3. **At State $C$:**
   * 50% chance of reaching Goal $G$ ($r = +1, v(G) = 0$): Contribution $= 0.5 \times [1 + \gamma(0)] = 0.5$
   * 50% chance of slipping back to $B$ ($r = 0$): Contribution $= 0.5 \times [0 + \gamma v(B)] = 0.5(0.8 v(B)) = 0.4 v(B)$
   $$v(C) = 0.5 + 0.4 v(B)$$

---

### Step 2: Solve the System Algebraically

Substitute $v(B) = 0.8 v(C)$ into the equation for $v(C)$:
$$v(C) = 0.5 + 0.4(0.8 v(C))$$
$$v(C) = 0.5 + 0.32 v(C)$$
$$v(C) - 0.32 v(C) = 0.5$$
$$0.68 v(C) = 0.5$$
$$v(C) = \frac{0.5}{0.68} = \frac{50}{68} = \frac{25}{34}$$

Now substitute $v(C)$ back to find $v(B)$:
$$v(B) = 0.8 \times v(C) = \frac{4}{5} \times \frac{25}{34} = \frac{4 \times 5}{34} = \frac{20}{34} = \frac{10}{17}$$

Now substitute $v(B)$ back to find $v(A)$:
$$v(A) = 0.8 \times v(B) = \frac{4}{5} \times \frac{10}{17} = \frac{4 \times 2}{17} = \frac{8}{17}$$

---

### Final Exact Values Table

| State | Exact Fraction | Decimal (4 places) | Physical Meaning |
| :---: | :---: | :---: | :--- |
| **$v(C)$** | **$\frac{25}{34}$** | **$\approx 0.7353$** | Highest value (directly faces Goal, subject to 50% slip). |
| **$v(B)$** | **$\frac{10}{17} = \frac{20}{34}$** | **$\approx 0.5882$** | Discounted by 1 step from $C$ ($\gamma = 0.8$). |
| **$v(A)$** | **$\frac{8}{17} = \frac{16}{34}$** | **$\approx 0.4706$** | Discounted by 2 steps from $C$ ($\gamma^2 = 0.64$). |

---

## Q26. [Bank Q54] Looped Episode Notebook Comparison ($\gamma = 1$)

### Prompt:
Consider an undiscounted ($\gamma = 1$) looped trajectory where State $A$ is visited three times and State $B$ is visited twice before reaching terminal $G$:
$$\tau = [(S_0 = A, R_1 = -2), (S_1 = B, R_2 = -1), (S_2 = A, R_3 = -2), (S_3 = B, R_4 = -1), (S_4 = A, R_5 = +12), S_5 = G]$$
(a) Compute $G_0, G_1, G_2, G_3$, and $G_4$ by backward accumulation.
(b) Write the "notebook" return lists `list(A)` and `list(B)` and the resulting state-value estimates $V(A)$ and $V(B)$ under both First-Visit MC and Every-Visit MC.

### Response:

**First, understand the difference between First-Visit and Every-Visit:**
* **First-Visit MC:** Only records the return from the *very first time* you step into a state during an episode. Subsequent visits are completely ignored.
* **Every-Visit MC:** Records a separate return *every single time* you step into the state, even if you loop through it multiple times in the same run.

---

### (a) Compute returns $G_0, G_1, G_2, G_3, G_4$ by Backward Accumulation
Given $\gamma = 1$, the backward recursion formula is:
$$G_t = R_{t+1} + G_{t+1}, \quad \text{with } G_5 = 0$$

1. **Step $t = 4$ ($S_4 = A$):**
   $$G_4 = R_5 + G_5 = +12 + 0 = \mathbf{12}$$
2. **Step $t = 3$ ($S_3 = B$):**
   $$G_3 = R_4 + G_4 = -1 + 12 = \mathbf{11}$$
3. **Step $t = 2$ ($S_2 = A$):**
   $$G_2 = R_3 + G_3 = -2 + 11 = \mathbf{9}$$
4. **Step $t = 1$ ($S_1 = B$):**
   $$G_1 = R_2 + G_2 = -1 + 9 = \mathbf{8}$$
5. **Step $t = 0$ ($S_0 = A$):**
   $$G_0 = R_1 + G_1 = -2 + 8 = \mathbf{6}$$

---

### (b) Notebook Return Lists & Resulting Value Estimates

Let's group the visits by state:
* **State $A$ visits:**
  * Visit 1 (at $t = 0$): Return $G_0 = 6$
  * Visit 2 (at $t = 2$): Return $G_2 = 9$
  * Visit 3 (at $t = 4$): Return $G_4 = 12$
* **State $B$ visits:**
  * Visit 1 (at $t = 1$): Return $G_1 = 8$
  * Visit 2 (at $t = 3$): Return $G_3 = 11$

---

#### 1. First-Visit Monte Carlo (FV-MC)
* Only takes the first entry:
  * `list(A) = [6]`
  * `list(B) = [8]`
* **Estimates:**
  $$\boxed{V_{\text{FV}}(A) = 6.0}$$
  $$\boxed{V_{\text{FV}}(B) = 8.0}$$

---

#### 2. Every-Visit Monte Carlo (EV-MC)
* Averages all visits within the episode:
  * `list(A) = [6, 9, 12]`
  * `list(B) = [8, 11]`
* **Estimates:**
  $$V_{\text{EV}}(A) = \frac{6 + 9 + 12}{3} = \frac{27}{3} = \mathbf{9.0}$$
  $$\boxed{V_{\text{EV}}(A) = 9.0}$$

  $$V_{\text{EV}}(B) = \frac{8 + 11}{2} = \frac{19}{2} = \mathbf{9.5}$$
  $$\boxed{V_{\text{EV}}(B) = 9.5}$$

---

### Comparison Summary Table

| Metric | First-Visit MC | Every-Visit MC |
| :--- | :---: | :---: |
| **`list(A)`** | `[6]` | `[6, 9, 12]` |
| **$V(A)$ Estimate** | **$6.0$** | **$9.0$** |
| **`list(B)`** | `[8]` | `[8, 11]` |
| **$V(B)$ Estimate** | **$8.0$** | **$9.5$** |
| **Statistical Property** | Strictly Unbiased | Biased for finite looped episodes |

---

## Q27. [Bank Q57] Why $V(C)$ Alone Cannot Choose Left vs. Right Without $P$

### Prompt:
On Slides 21–22 of `Rl_class.pdf`, under the always-Right policy on Spear World ($\gamma = 0.9$), the ground-truth state values are $V(C) \approx 0.840$ and $V(B) \approx 0.756$.
(a) Write the two one-step lookahead equations that a model-based agent uses to score Left vs. Right at State $C$ from $V(B)$, and verify their numerical values (0.680 vs. 0.840).
(b) Explain why a model-free agent that only learns the state-value table $V(A), V(B), V(C)$ is completely unable to perform greedy action selection at State $C$.

### Response:

**First, understand the core dilemma:** If you only know how good the rooms in a house are ($V(s)$), but you have no idea which doors lead to which rooms (no model $P$), knowing room values does not help you choose a door!

---

### (a) One-Step Lookahead Equations for a Model-Based Agent

A model-based agent knows the environment transition probabilities $P(s' \mid s, a)$ and rewards $R$:
* Choosing **Left** deterministically moves to State $B$ ($r = 0$).
* Choosing **Right** gives a 50% chance of hitting Goal $G$ ($r = +1, V(G) = 0$) and a 50% chance of slipping to State $B$ ($r = 0, V(B) \approx 0.756$).

#### 1. Score for Action Left:
$$\text{Score}(\text{Left}) = R(C, \text{Left}) + \gamma V(B)$$
$$\text{Score}(\text{Left}) = 0 + 0.9 \times 0.756$$
$$\boxed{\text{Score}(\text{Left}) = 0.6804 \approx 0.680}$$

#### 2. Score for Action Right:
$$\text{Score}(\text{Right}) = \sum_{s', r} P(s', r \mid C, \text{Right}) [r + \gamma V(s')]$$
$$\text{Score}(\text{Right}) = 0.5 \times [1 + 0.9(0)] + 0.5 \times [0 + 0.9 V(B)]$$
$$\text{Score}(\text{Right}) = 0.5 + 0.45 \times (0.756)$$
$$\text{Score}(\text{Right}) = 0.5 + 0.3402$$
$$\boxed{\text{Score}(\text{Right}) = 0.8402 \approx 0.840}$$

---

### (b) Why a Model-Free Agent Cannot Do This with Only $V(s)$

1. **Greedy action selection requires evaluating:**
   $$a^* = \arg\max_{a} \sum_{s'} P(s' \mid s, a)[R(s, a, s') + \gamma V(s')]$$
2. Notice the formula explicitly requires:
   * The transition probability distribution $P(s' \mid s, a)$
   * The reward model $R(s, a, s')$
3. By definition, a **model-free agent does not know $P$ or $R$**. It does not know that choosing Right leads to the Goal 50% of the time, nor does it know that Left moves to State $B$.
4. Therefore, having a lookup table of state values $V(A), V(B), V(C)$ is completely useless for action selection in a model-free setting!
5. **The Architectural Fix:** To act without a model, the agent must learn **Action-Values $Q(s, a)$** directly. With a $Q$-table, the agent simply looks up:
   $$a^* = \arg\max_a Q(s, a)$$
   which requires zero knowledge of environmental physics or transition probabilities!

---

## Q28. [Bank Q58] The Coward Policy Coverage Hole

### Prompt:
On Slide 26 of `Rl_class.pdf`, the "coward policy" $\pi_0$ chooses Right in $A$ and $B$, but Left in $C$ (fearing the spear).
(a) What trajectory occurs when following $\pi_0$ from $A$, and why does standard Monte Carlo evaluation fail if there is no step limit / timeout?
(b) Even if episodes are truncated with reward 0 so that $Q(A, R) = Q(B, R) = Q(C, L) = 0$, why can greedy policy improvement $\pi(s) \leftarrow \arg\max_a Q(s, a)$ never discover the optimal action at $C$? Is the goal unreachable in the MDP or merely unseen under $\pi_0$?

### Response:

**First, understand the "Coward Policy":**
* In State $A$: Agent moves Right $\to B$.
* In State $B$: Agent moves Right $\to C$.
* In State $C$: The agent sees the dangerous spear ahead and panics, choosing **Left** $\to$ sending it straight back to $B$!

---

### (a) Trajectory and Failure of Standard Monte Carlo

#### 1. What trajectory occurs?
Starting from State $A$:
$$A \xrightarrow{\text{Right}} B \xrightarrow{\text{Right}} C \xrightarrow{\text{Left}} B \xrightarrow{\text{Right}} C \xrightarrow{\text{Left}} B \xrightarrow{\text{Right}} C \dots$$
The agent enters an **infinite deterministic oscillation between State $B$ and State $C$**.

#### 2. Why does standard Monte Carlo evaluation fail?
* By fundamental definition, **Monte Carlo methods learn only from completed episodes** (they compute the return $G_t = \sum_{k=0}^T \gamma^k R_{t+k+1}$ by backward accumulation from the terminal state).
* Because the agent is trapped in an infinite cycle, the episode **never reaches a terminal state** ($T = \infty$).
* The episode never ends, the return $G_t$ cannot be computed, and the algorithm hangs in an infinite loop without ever updating its values!

---

### (b) Why Greedy Policy Improvement Cannot Discover the Goal

#### 1. Why $\arg\max_a Q(s, a)$ fails:
* If episodes are truncated with reward 0, the agent observes returns of 0 for the actions it took:
  $$Q(A, \text{Right}) = 0, \quad Q(B, \text{Right}) = 0, \quad Q(C, \text{Left}) = 0$$
* But what about the action **$\text{Right}$ at State $C$** (which leads to the $+1$ Goal)?
  * Action $(C, \text{Right})$ was **never executed even once!**
  * Its value remains at its initial value: $Q(C, \text{Right}) = 0$.
* When greedy improvement executes at State $C$:
  $$\pi'(C) = \arg\max_{a} Q(C, a) = \arg\max \{Q(C, \text{Left})=0, Q(C, \text{Right})=0\}$$
* Due to tie-breaking, the agent stays with Left. The greedy policy never tries Right, meaning it can never discover that Right leads to the Goal!

#### 2. Unreachable vs. Unseen:
$$\boxed{\text{The goal is merely UNSEEN under } \pi_0, \text{ NOT unreachable in the MDP.}}$$
* The physical path to Goal $G$ exists in the MDP environment dynamics.
* But under policy $\pi_0$, the probability of visiting $(C, \text{Right})$ is exactly $0$. 
* Without an exploratory mechanism (like **Exploring Starts** or **$\varepsilon$-greedy** exploration), a purely greedy agent remains permanently blind to unseen optimal paths.
