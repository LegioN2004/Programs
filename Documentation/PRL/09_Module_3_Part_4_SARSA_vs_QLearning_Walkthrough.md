# Section 9: Module 3 (Part 4) — Step-by-Step Episode Walkthrough: SARSA vs. Q-Learning

---

## Q38. [Bank Q81] Deriving the 50/50 Tie Rule and 90/10 Split Rule

### Prompt:
In `TD_example.pdf`, the 3-state chain ($A, B, C, \text{Goal}$) has two actions $\{\text{Left}, \text{Right}\}$ per state and uses parameters $\alpha = 0.5, \gamma = 0.9, \varepsilon = 0.2$. Using the $\varepsilon$-greedy formula $\pi(a^* \mid s) = 1 - \varepsilon + \varepsilon / |A|$ and $\pi(a \mid s) = \varepsilon / |A|$, verify mathematically why any state with a unique greedy action has a 90%/10% behaviour policy split, while Q-Learning's target policy ($\varepsilon = 0$) has a 100%/0% split.

### Response:

**First, understand what these probabilities mean:** In reinforcement learning walkthroughs, before any learning takes place, values are tied at 0 (50/50). But as soon as one action gets a positive point, the agent exploits that action heavily while keeping a small exploration window open.

---

### Step 1: Deriving the 90%/10% Split Rule for the Behaviour Policy ($\varepsilon = 0.2$)

Given:
* Number of discrete actions: $|A| = 2$ ($\text{Left}$ and $\text{Right}$).
* Exploration rate: $\varepsilon = 0.2$.

#### 1. For the Unique Greedy Action $a^*$:
Substitute $|A| = 2$ and $\varepsilon = 0.2$ into the formula:
$$\pi(a^* \mid s) = 1 - \varepsilon + \frac{\varepsilon}{|A|}$$
$$\pi(a^* \mid s) = 1 - 0.2 + \frac{0.2}{2}$$
$$\pi(a^* \mid s) = 0.8 + 0.1$$
$$\boxed{\pi(a^* \mid s) = 0.90} \quad (90\%)$$

#### 2. For the Suboptimal (Exploratory) Action $a \neq a^*$:
Substitute into the exploratory formula:
$$\pi(a \mid s) = \frac{\varepsilon}{|A|}$$
$$\pi(a \mid s) = \frac{0.2}{2}$$
$$\boxed{\pi(a \mid s) = 0.10} \quad (10\%)$$

**Conclusion:** The behaviour policy assigns exactly **90%** probability to the greedy action and **10%** probability to the exploratory action.

---

### Step 2: Deriving the 50/50 Tie Rule When $Q(s, \text{Left}) = Q(s, \text{Right})$
* When both actions have identical $Q$-values (e.g., both are 0.0), neither action is uniquely greedy.
* By definition, the agent breaks ties uniformly at random:
  $$\pi(\text{Left} \mid s) = \frac{1}{|A|} = \frac{1}{2} = 0.50 \quad (50\%)$$
  $$\pi(\text{Right} \mid s) = \frac{1}{|A|} = \frac{1}{2} = 0.50 \quad (50\%)$$
* This represents the **50/50 Tie Rule**.

---

### Step 3: Deriving Q-Learning's Target Policy (100%/0% Split)

Recall that Q-Learning is an **off-policy** algorithm:
* Its **behaviour policy** (generating trajectories) uses $\varepsilon = 0.2$ $\implies$ 90%/10% split.
* Its **target policy** (used inside the update equation $\max_{a'} Q(S', a')$) is **purely greedy**, meaning $\varepsilon = 0$.

Substitute $\varepsilon = 0$ into the formula:
* For the greedy action $a^*$:
  $$\pi_{\text{target}}(a^* \mid s) = 1 - 0 + \frac{0}{2} = \mathbf{1.0} \quad (100\%)$$
* For the non-greedy action $a$:
  $$\pi_{\text{target}}(a \mid s) = \frac{0}{2} = \mathbf{0.0} \quad (0\%)$$

$$\boxed{\text{Q-Learning Target Policy Split: } 1.0 \text{ Greedy} \;/\; 0.0 \text{ Non-Greedy}} \quad (100\% / 0\%)$$

---

### Summary Table

| Policy Type | Exploration ($\varepsilon$) | Action with Higher $Q$ | Action with Lower $Q$ | Tie ($Q_L = Q_R$) |
| :--- | :---: | :---: | :---: | :---: |
| **Behaviour Policy ($\mu$)** | $\varepsilon = 0.2$ | **90%** | **10%** | **50% / 50%** |
| **Q-Learning Target Policy ($\pi$)** | $\varepsilon = 0.0$ | **100%** | **0%** | **50% / 50%** |

---

## Q39. [Bank Q83] Backward Wave Propagation Across Episodes

### Prompt:
In the walkthrough, State $C$ first acquires a positive Q-value at the end of Episode 1 (0.5), State $B$ at the end of Episode 2 (0.225), and State $A$ at the end of Episode 3 (0.10125). In general, on a 1D chain of $N$ non-terminal states initialized to $Q = 0$ with reward only at the Goal, what is the minimum number of episodes required for the first non-zero TD update to reach the start state $S_1$, and how does this contrast with a single Monte Carlo episode?

### Response:

**First, visualize the 1D Chain:**
```
[ S_1 ] ---> [ S_2 ] ---> [ S_3 ] ---> ... ---> [ S_N ] ---> [ GOAL (+1) ]
```
* All states are initialized to $Q(s, a) = 0$.
* Reward is $0$ everywhere except entering the Goal, which gives $R = +1$.

---

### 1. Step-by-Step Analysis of TD(0) Value Propagation

#### Episode 1:
* The agent walks: $S_1 \to S_2 \to S_3 \to \dots \to S_N \to \text{Goal}$.
* **Transitions along the chain ($S_i \to S_{i+1}$):**
  * Immediate reward $R = 0$.
  * Successor value $Q(S_{i+1}, a) = 0$.
  * TD Target $= 0 + \gamma(0) = 0$.
  * TD Error $\delta = 0 - 0 = 0$.
  * **Result:** No update happens for any state $S_1, S_2, \dots, S_{N-1}$!
* **The Final Step ($S_N \to \text{Goal}$):**
  * Immediate reward $R = +1$.
  * TD Target $= +1 + \gamma(0) = 1.0$.
  * TD Error $\delta = 1.0 - 0 = +1.0$.
  * **Result:** State $S_N$ receives its first non-zero update: $Q(S_N, \text{Right}) = \alpha(1.0) > 0$.
* **End of Episode 1:** Only the final state $S_N$ has positive value!

#### Episode 2:
* When the agent reaches $S_{N-1}$ and moves to $S_N$:
  * Successor state $S_N$ now has positive value $Q(S_N) > 0$ from Episode 1!
  * TD Target $= 0 + \gamma Q(S_N) > 0$.
  * **Result:** State $S_{N-1}$ receives its first non-zero update.
* **End of Episode 2:** Non-zero values have propagated back to $S_{N-1}$.

#### General Rule for a Chain of $N$ States:
* Because 1-step TD only bootstraps from the immediate next state, non-zero reward information travels **backwards by exactly 1 state per episode**.
* Therefore, for non-zero information to propagate from the Goal all the way back across $N$ states to start state $S_1$, the agent requires:
  $$\boxed{\text{Minimum Episodes for TD(0)} = N \text{ episodes}}$$

---

### 2. Contrast with a Single Monte Carlo Episode
* Monte Carlo does **not bootstrap**.
* Instead, MC waits for the episode to finish, observes the terminal reward $+1$, and computes the discounted return **backwards across the entire trajectory at once**:
  $$G_t = \gamma^{T-t-1} R_{\text{goal}}$$
* Therefore, in a **single episode ($N = 1$)** that reaches the Goal, Monte Carlo immediately updates **every single state along the trajectory ($S_1, S_2, \dots, S_N$) simultaneously** with positive non-zero returns:
  $$V(S_N) \leftarrow \gamma^0(1) = 1.0, \quad V(S_{N-1}) \leftarrow \gamma^1, \quad \dots \quad V(S_1) \leftarrow \gamma^{N-1}$$

---

### Comparison Table (TD vs. MC Value Wave)

| Dimension | 1-Step TD / SARSA / Q-Learning | Monte Carlo (MC) |
| :--- | :--- | :--- |
| **Propagation Mechanism** | 1-step local bootstrap. | Full backward trajectory return. |
| **Speed of Propagation** | **1 state per episode.** | **Entire trajectory in 1 episode.** |
| **Episodes to reach start $S_1$** | **$N$ episodes.** | **1 episode.** |
| **Variance of Updates** | Very Low (incremental). | High (dependent on full path). |

---

## Q40. [Bank Q86] Breaking the Symmetry When the Agent Rolls the 10% Exploratory Action at State C in Episode 2

### Prompt:
Suppose in Episode 2, the agent starts at $A$, moves $A \xrightarrow{\text{Right}} B$ ($R = 0$) and then moves $B \xrightarrow{\text{Right}} C$ ($R = 0$). Upon arriving at State $C$ (where $Q(C, L) = 0.0$ and $Q(C, R) = 0.5$ from Episode 1), the agent rolls the 10% exploratory action $A_{t+1} = \text{Left}$.
(a) Compute SARSA's update to $Q(B, \text{Right})$ on this transition and state SARSA's resulting behaviour policy at State $B$.
(b) Compute Q-Learning's update to $Q(B, \text{Right})$ on this exact same transition and state Q-Learning's resulting target and behaviour policies at State $B$.

### Response:

**First, understand the drama of this transition:** 
The transition being updated is:
$$\text{Transition: } \big(S_t = B, \; A_t = \text{Right}, \; R_{t+1} = 0, \; S_{t+1} = C\big)$$
* Current estimate: $Q(B, \text{Right}) = 0.0$.
* Values at landing state $C$: $Q(C, \text{Left}) = 0.0, \; Q(C, \text{Right}) = 0.5$.
* Hyperparameters: $\alpha = 0.5, \gamma = 0.9$.
* But upon arriving at $C$, the agent rolls an exploratory blunder: it selects $A_{t+1} = \text{Left}$!

---

### (a) SARSA Update (On-Policy: Bound to the Blunder)

SARSA's update target is bound to the action actually selected ($A_{t+1} = \text{Left}$):
$$\text{Target}_{\text{SARSA}} = R_{t+1} + \gamma Q(C, A_{t+1}) = 0 + 0.9 \times Q(C, \text{Left}) = 0 + 0.9(0.0) = \mathbf{0.0}$$

Compute the update:
$$Q(B, \text{Right}) \leftarrow Q(B, \text{Right}) + \alpha \big[\text{Target} - Q(B, \text{Right})\big]$$
$$Q(B, \text{Right}) \leftarrow 0.0 + 0.5 [0.0 - 0.0] = \mathbf{0.0}$$
$$\boxed{Q_{\text{SARSA}}(B, \text{Right}) = 0.0}$$

#### Resulting SARSA Behaviour Policy at State $B$:
* $Q(B, \text{Left}) = 0.0$ and $Q(B, \text{Right}) = 0.0$.
* Because values are tied at 0.0, the 50/50 tie rule applies:
  $$\boxed{\pi_{\text{SARSA}}(\text{Right} \mid B) = 0.50, \quad \pi_{\text{SARSA}}(\text{Left} \mid B) = 0.50} \quad (50\% / 50\%)$$
* **Impact:** SARSA learned *nothing* from this transition because it evaluated the bad exploratory left move!

---

### (b) Q-Learning Update (Off-Policy: Ignores the Blunder)

Q-Learning's target completely ignores the exploratory choice and takes the maximum action-value at State $C$:
$$\text{Target}_{\text{QL}} = R_{t+1} + \gamma \max_{a'} Q(C, a') = 0 + 0.9 \times \max\big(Q(C, \text{Left}), Q(C, \text{Right})\big)$$
$$\text{Target}_{\text{QL}} = 0 + 0.9 \times \max(0.0, 0.5) = 0 + 0.9(0.5) = \mathbf{0.45}$$

Compute the update:
$$Q(B, \text{Right}) \leftarrow Q(B, \text{Right}) + \alpha \big[\text{Target} - Q(B, \text{Right})\big]$$
$$Q(B, \text{Right}) \leftarrow 0.0 + 0.5 [0.45 - 0.0] = \mathbf{0.225}$$
$$\boxed{Q_{\text{QL}}(B, \text{Right}) = 0.225}$$

#### Resulting Q-Learning Policies at State $B$:
Now, $Q(B, \text{Right}) = 0.225 > Q(B, \text{Left}) = 0.0$. The symmetry is broken! Action Right is the unique greedy action.

1. **Target Policy ($\pi$ with $\varepsilon = 0$):**
   $$\boxed{\pi_{\text{target}}(\text{Right} \mid B) = 1.0, \quad \pi_{\text{target}}(\text{Left} \mid B) = 0.0} \quad (100\% / 0\%)$$
2. **Behaviour Policy ($\mu$ with $\varepsilon = 0.2$, 90/10 split rule):**
   $$\boxed{\mu(\text{Right} \mid B) = 0.90, \quad \mu(\text{Left} \mid B) = 0.10} \quad (90\% / 10\%)$$

---

### Summary Table

| Metric | SARSA (On-Policy) | Q-Learning (Off-Policy) |
| :--- | :---: | :---: |
| **Next Action Evaluated** | Actual Choice: $\text{Left}$ ($Q = 0.0$) | Best Choice: $\max = \text{Right}$ ($Q = 0.5$) |
| **TD Target** | $0 + 0.9(0.0) = \mathbf{0.0}$ | $0 + 0.9(0.5) = \mathbf{0.45}$ |
| **Updated $Q(B, \text{Right})$** | **$0.0$** (Learned nothing) | **$0.225$** (Propagated reward!) |
| **Policy at State $B$** | **50% / 50% Tie** | **90% Right / 10% Left** |

---

## Q41. [Bank Q89] Asymptotic Fixed-Point Values $Q^*(s, a)$ on the 3-State Chain

### Prompt:
As the number of episodes $n \to \infty$ with $\gamma = 0.9$ on the deterministic 3-state chain ($A \leftrightarrow B \leftrightarrow C \to \text{Goal}$, where Left at $A$ stays in $A$ and only $C \xrightarrow{\text{Right}} \text{Goal}$ gives $R = +1$), what are the exact converged Q-Learning values $Q^*(s, \text{Right})$ and $Q^*(s, \text{Left})$ for all $s \in \{A, B, C\}$?

### Response:

**First, understand what $Q^*(s, a)$ represents:** Under Q-learning, as $n \to \infty$, action-values converge to the optimal Bellman optimality fixed point:
$$Q^*(s, a) = R(s, a) + \gamma \max_{a'} Q^*(s', a')$$

---

### Step-by-Step Backwards Derivation

#### 1. At State $C$:
* **Action Right:** Steps directly into Goal ($R = +1, \text{Goal is Terminal} \implies Q^* = 0$):
  $$Q^*(C, \text{Right}) = 1.0 + \gamma(0) = \mathbf{1.0}$$
  $$\boxed{Q^*(C, \text{Right}) = 1.000}$$

* **Action Left:** Moves to State $B$ ($R = 0$):
  $$Q^*(C, \text{Left}) = 0 + \gamma \max_{a'} Q^*(B, a') = 0.9 \max\big(Q^*(B, \text{Left}), Q^*(B, \text{Right})\big)$$

---

#### 2. At State $B$:
* **Action Right:** Moves to State $C$ ($R = 0$):
  $$Q^*(B, \text{Right}) = 0 + \gamma \max_{a'} Q^*(C, a') = 0.9 \max(1.0, Q^*(C, \text{Left})) = 0.9 \times 1.0 = \mathbf{0.90}$$
  $$\boxed{Q^*(B, \text{Right}) = 0.900}$$

* Now we can resolve $Q^*(C, \text{Left})$:
  $$Q^*(C, \text{Left}) = 0.9 \times Q^*(B, \text{Right}) = 0.9 \times 0.90 = \mathbf{0.81}$$
  $$\boxed{Q^*(C, \text{Left}) = 0.810}$$

* **Action Left:** Moves to State $A$ ($R = 0$):
  $$Q^*(B, \text{Left}) = 0 + \gamma \max_{a'} Q^*(A, a') = 0.9 \max\big(Q^*(A, \text{Left}), Q^*(A, \text{Right})\big)$$

---

#### 3. At State $A$:
* **Action Right:** Moves to State $B$ ($R = 0$):
  $$Q^*(A, \text{Right}) = 0 + \gamma \max_{a'} Q^*(B, a') = 0.9 \times Q^*(B, \text{Right}) = 0.9 \times 0.90 = \mathbf{0.81}$$
  $$\boxed{Q^*(A, \text{Right}) = 0.810}$$

* Now we can resolve $Q^*(B, \text{Left})$:
  $$Q^*(B, \text{Left}) = 0.9 \times Q^*(A, \text{Right}) = 0.9 \times 0.81 = \mathbf{0.729}$$
  $$\boxed{Q^*(B, \text{Left}) = 0.729}$$

* **Action Left:** Hitting the left wall keeps the agent in State $A$ ($R = 0$):
  $$Q^*(A, \text{Left}) = 0 + \gamma \max_{a'} Q^*(A, a') = 0.9 \times Q^*(A, \text{Right}) = 0.9 \times 0.81 = \mathbf{0.729}$$
  $$\boxed{Q^*(A, \text{Left}) = 0.729}$$

---

### Master Asymptotic $Q^*(s, a)$ Table

| State ($s$) | $Q^*(s, \text{Right})$ | $Q^*(s, \text{Left})$ | Optimal Greedy Action ($\arg\max$) |
| :---: | :---: | :---: | :---: |
| **State $C$** | **$1.000$** | **$0.810$** | **Right** |
| **State $B$** | **$0.900$** | **$0.729$** | **Right** |
| **State $A$** | **$0.810$** | **$0.729$** | **Right** |
