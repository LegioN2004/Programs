# Section 7: Module 3 (Part 2) — Monte Carlo Model-Free Control

---

## Q29. [Bank Q61] Discounted Backward Return & Estimator Comparison on $\{S_1, S_2, S_3\}$

### Prompt:
Consider the trajectory $S_1 \xrightarrow{R_1 = +2} S_2 \xrightarrow{R_2 = +1} S_1 \xrightarrow{R_3 = +4} S_3 \xrightarrow{R_4 = +10} T$. With $\gamma = 1.0$, Slides 6–7 gave $\hat{V}_{\text{FV}}(S_1) = 17.0$ and $\hat{V}_{\text{EV}}(S_1) = 15.5$. Now recompute the backward returns $G_3, G_2, G_1, G_0$ and the single-episode estimates $\hat{V}_{\text{FV}}(S_1)$ and $\hat{V}_{\text{EV}}(S_1)$ when the discount factor is $\gamma = 0.5$.

### Response:

**First, understand the trajectory timeline:**
```
Time t:    0               1               2               3               4
State:    S_1 --(R1=+2)--> S_2 --(R2=+1)--> S_1 --(R3=+4)--> S_3 --(R4=+10)-> Terminal
```
Discount factor: $\gamma = 0.5$.

---

### Step 1: Recompute Backward Returns $G_3, G_2, G_1, G_0$
Using the backward recursion:
$$G_t = R_{t+1} + \gamma G_{t+1}, \quad \text{with } G_4 = 0$$

1. **At** $t = 3$ ($S_3 \to T$):
   $$G_3 = R_4 + 0.5 \times G_4 = 10 + 0.5(0) = \mathbf{10.0}$$
   $$\boxed{G_3 = 10.0}$$

2. **At** $t = 2$ ($S_1 \to S_3$):
   $$G_2 = R_3 + 0.5 \times G_3 = 4 + 0.5(10.0) = 4 + 5.0 = \mathbf{9.0}$$
   $$\boxed{G_2 = 9.0}$$

3. **At** $t = 1$ ($S_2 \to S_1$):
   $$G_1 = R_2 + 0.5 \times G_2 = 1 + 0.5(9.0) = 1 + 4.5 = \mathbf{5.5}$$
   $$\boxed{G_1 = 5.5}$$

4. **At** $t = 0$ ($S_1 \to S_2$):
   $$G_0 = R_1 + 0.5 \times G_1 = 2 + 0.5(5.5) = 2 + 2.75 = \mathbf{4.75}$$
   $$\boxed{G_0 = 4.75}$$

---

### Step 2: Compute Single-Episode Estimates for State $S_1$

Notice that **State $S_1$ is visited at two distinct time steps**:
* First visit at $t = 0$ with return $G_0 = 4.75$.
* Second visit at $t = 2$ with return $G_2 = 9.0$.

#### 1. First-Visit Monte Carlo ($\hat{V}_{\text{FV}}(S_1)$):
Takes only the return from the first occurrence:
$$\hat{V}_{\text{FV}}(S_1) = G_0$$
$$\boxed{\hat{V}_{\text{FV}}(S_1) = 4.75}$$

#### 2. Every-Visit Monte Carlo ($\hat{V}_{\text{EV}}(S_1)$):
Averages the returns from all occurrences:
$$\hat{V}_{\text{EV}}(S_1) = \frac{G_0 + G_2}{2} = \frac{4.75 + 9.0}{2} = \frac{13.75}{2}$$
$$\boxed{\hat{V}_{\text{EV}}(S_1) = 6.875}$$

---

### Comparison Table ($\gamma = 1.0$ vs. $\gamma = 0.5$)

| Quantity | Undiscounted ($\gamma = 1.0$) | Discounted ($\gamma = 0.5$) |
| :--- | :---: | :---: |
| $G_3$ | $10.0$ | **$10.0$** |
| $G_2$ | $14.0$ | **$9.0$** |
| $G_1$ | $15.0$ | **$5.5$** |
| $G_0$ | $17.0$ | **$4.75$** |
| $\hat{V}_{\text{FV}}(S_1)$ | $17.0$ | **$4.75$** |
| $\hat{V}_{\text{EV}}(S_1)$ | $15.5$ | **$6.875$** |

---

## Q30. [Bank Q62] Statistical Properties of First-Visit vs. Every-Visit MC

### Prompt:
Compare First-Visit MC and Every-Visit MC in terms of: (a) finite-sample bias, (b) why Every-Visit MC is biased for finite samples when a trajectory loops, (c) asymptotic bias as $N \to \infty$, and (d) variance decay rate with respect to the number of episodes $N$.

### Response:

**First, understand the core statistical trade-off:** In statistics, estimators are judged by two properties: **Bias** (do they hit the bullseye on average?) and **Variance** (how widely scattered are their estimates?).

---

### (a) Finite-Sample Bias
* **First-Visit MC is strictly UNBIASED:**
  * For any finite number of episodes $N$, the expected value of the sample average equals the true value function: $E[\hat{V}_{\text{FV}}(s)] = V^\pi(s)$.
* **Every-Visit MC is BIASED for finite samples:**
  * When an episode contains repeated visits to the same state, the expected value of the estimator does not equal the true state value: $E[\hat{V}_{\text{EV}}(s)] \neq V^\pi(s)$.

---

### (b) Why Every-Visit MC is Biased for Finite Samples When a Trajectory Loops
* When an agent visits state $s$ at time $t_1$ and again at time $t_2$ within the *same* trajectory, the returns $G_{t_1}$ and $G_{t_2}$ are **statistically dependent (correlated)** because $G_{t_1} = R_{t_1+1} + \dots + \gamma^{t_2 - t_1} G_{t_2}$.
* Every-Visit MC treats these two correlated returns as independent data points in its denominator.
* As a result, episodes that loop many times inside a state contribute multiple correlated samples, disproportionately biasing the average toward whatever random downstream event happened during that specific episode.

---

### (c) Asymptotic Bias as $N \to \infty$
* **Both estimators are ASYMPTOTICALLY UNBIASED:**
  $$\lim_{N \to \infty} \hat{V}_{\text{FV}}(s) = V^\pi(s) \quad \text{and} \quad \lim_{N \to \infty} \hat{V}_{\text{EV}}(s) = V^\pi(s)$$
* By the Law of Large Numbers, as the number of independent episodes approaches infinity, the correlation bias in Every-Visit MC vanishes, and both methods converge to the exact ground-truth value function.

---

### (d) Variance Decay Rate with Respect to $N$
* Both estimators have a variance that decays at the standard parametric rate of:
  $$\text{Var}(\hat{V}) = \mathcal{O}\left(\frac{1}{N}\right)$$
* **Practical variance difference:** In practice, Every-Visit MC often achieves slightly **lower variance** than First-Visit MC because it averages over more data points per episode, making it popular in practice when episode lengths are long or data is scarce.

---

### Summary Table (Important for Exams)

| Dimension | First-Visit MC | Every-Visit MC |
| :--- | :--- | :--- |
| **(a) Finite-Sample Bias** | **Unbiased** ($E[\hat{V}] = V^\pi$). | **Biased** ($E[\hat{V}] \neq V^\pi$). |
| **(b) Source of Bias** | None (1 independent sample per episode). | Cross-temporal correlation among repeated returns in loops. |
| **(c) Asymptotic Bias ($N \to \infty$)** | **Unbiased** (Converges to $V^\pi$). | **Unbiased** (Converges to $V^\pi$). |
| **(d) Variance Decay Rate** | $\mathcal{O}(1/N)$ | $\mathcal{O}(1/N)$ (Often lower absolute variance in practice). |

---

## Q31. [Bank Q64] Deriving the $\varepsilon$-Soft Action Probability Formula

### Prompt:
Under $\varepsilon$-greedy action selection on an action space $A$ with $|A| = n$ discrete actions, the agent chooses a uniform random action with probability $\varepsilon$ and the greedy action $a^* = \arg\max_{a'} Q(s, a')$ with probability $1 - \varepsilon$. Show algebraically why the resulting total probability of selecting the greedy action $a^*$ is $\pi(a^* \mid s) = 1 - \varepsilon + \varepsilon/n$ (not just $1 - \varepsilon$), and verify that $\sum_{a \in A} \pi(a \mid s) = 1$.

### Response:

**First, understand why people make mistakes here:** Most students think the greedy action is chosen with probability $1 - \varepsilon$. But remember: when the agent rolls an exploration step (with probability $\varepsilon$), it picks uniformly from **ALL** $n$ actions—and that uniform random draw might accidentally pick the greedy action $a^*$ too!

---

### Step 1: Algebraic Derivation for the Greedy Action $a^*$

The selection of the greedy action $a^*$ occurs through two mutually exclusive events:
1. **Event 1 (Exploitation):** The agent decides to exploit (probability $1 - \varepsilon$) and deterministically chooses $a^*$.
   $$\Pr(\text{Choose } a^* \cap \text{Exploitation}) = (1 - \varepsilon) \times 1 = 1 - \varepsilon$$
2. **Event 2 (Exploration):** The agent decides to explore (probability $\varepsilon$). In exploration, it selects uniformly at random among all $n$ actions, meaning each action has probability $\frac{1}{n}$. Thus, $a^*$ is chosen with probability $\frac{1}{n}$.
   $$\Pr(\text{Choose } a^* \cap \text{Exploration}) = \varepsilon \times \frac{1}{n} = \frac{\varepsilon}{n}$$

By the Law of Total Probability, the total probability of selecting $a^*$ is the sum of both paths:
$$\pi(a^* \mid s) = \Pr(\text{Choose } a^* \cap \text{Exploitation}) + \Pr(\text{Choose } a^* \cap \text{Exploration})$$
$$\boxed{\pi(a^* \mid s) = 1 - \varepsilon + \frac{\varepsilon}{n}}$$

---

### Step 2: Probability for Any Non-Greedy Action $a \neq a^*$
A non-greedy action can *only* be selected during an exploration event:
$$\pi(a \mid s) = \varepsilon \times \frac{1}{n}$$
$$\boxed{\pi(a \mid s) = \frac{\varepsilon}{n}, \quad \forall a \neq a^*}$$

---

### Step 3: Verify that $\sum_{a \in A} \pi(a \mid s) = 1$

Split the sum over all $n$ actions into the greedy action $a^*$ and the remaining $(n - 1)$ non-greedy actions:
$$\sum_{a \in A} \pi(a \mid s) = \pi(a^* \mid s) + \sum_{a \neq a^*} \pi(a \mid s)$$

Substitute the derived expressions:
$$\sum_{a \in A} \pi(a \mid s) = \left(1 - \varepsilon + \frac{\varepsilon}{n}\right) + \sum_{a \neq a^*} \left(\frac{\varepsilon}{n}\right)$$

Since there are exactly $(n - 1)$ non-greedy actions:
$$\sum_{a \in A} \pi(a \mid s) = 1 - \varepsilon + \frac{\varepsilon}{n} + (n - 1) \frac{\varepsilon}{n}$$
$$\sum_{a \in A} \pi(a \mid s) = 1 - \varepsilon + \frac{\varepsilon + (n - 1)\varepsilon}{n}$$
$$\sum_{a \in A} \pi(a \mid s) = 1 - \varepsilon + \frac{n\varepsilon}{n}$$
$$\sum_{a \in A} \pi(a \mid s) = 1 - \varepsilon + \varepsilon$$
$$\boxed{\sum_{a \in A} \pi(a \mid s) = 1 \quad \text{(Q.E.D.)}}$$

---

### Numerical Sanity Check
If $|A| = 4$ actions and $\varepsilon = 0.20$:
* $\pi(a^* \mid s) = 1 - 0.20 + \frac{0.20}{4} = 0.80 + 0.05 = \mathbf{0.85}$ (85%)
* Each non-greedy action: $\pi(a \mid s) = \frac{0.20}{4} = \mathbf{0.05}$ (5% each)
* Total: $0.85 + 3 \times (0.05) = 0.85 + 0.15 = 1.00$.

---

## Q32. [Bank Q69] Exploring Starts vs. On-Policy $\varepsilon$-Greedy Control

### Prompt:
Compare Exploring Starts (MC-ES) and on-policy $\varepsilon$-greedy MC control across three practical dimensions: (a) whether the improvement operator remains strictly greedy ($\arg\max$), (b) whether the algorithm can be deployed on a physical robot driving in traffic or an online user recommendation system, and (c) the optimality guarantee of the converged policy ($\pi^*$ vs. best $\varepsilon$-soft policy).

### Response:

**First, understand the core problem in MC Control:** To find the optimal policy, an agent must try every action in every state. But if an agent follows a deterministic policy, it stops exploring. How do we guarantee every state-action pair $(s, a)$ gets visited?
* **Exploring Starts (MC-ES):** Magically spawns the agent at every possible $(s, a)$ starting point.
* **On-Policy $\varepsilon$-Greedy:** Starts normally, but injects continuous $\varepsilon$ randomness into every step.

---

### (a) Whether the Improvement Operator Remains Strictly Greedy ($\arg\max$)
* **Exploring Starts (MC-ES):**
  * **YES, strictly greedy:** The policy update operator is $\pi(s) \leftarrow \arg\max_a Q(s, a)$.
  * Because exploration is guaranteed by starting in every $(s, a)$ at $t=0$, the policy itself can remain 100% deterministic and strictly greedy during the episode.
* **On-Policy $\varepsilon$-Greedy Control:**
  * **NO, it uses an $\varepsilon$-soft improvement operator.**
  * The policy update shifts the $\varepsilon$-soft distribution toward the greedy action:

$$
\pi(a \mid s) \leftarrow \begin{cases}
1 - \varepsilon + \frac{\varepsilon}{|A|}, & a = \arg\max_{a'} Q(s, a') \\
\frac{\varepsilon}{|A|}, & a \neq \arg\max_{a'} Q(s, a')
\end{cases}
$$
  * The policy itself must remain stochastic forever to ensure continual exploration.

---

### (b) Deployment on a Physical Robot or Online Recommendation System
* **Exploring Starts (MC-ES):**
  * **COMPLETELY IMPOSSIBLE in practice.**
  * You cannot teleport a physical autonomous car into arbitrary dangerous starting states (e.g., spawn the car sideways at 80 mph directly in front of oncoming highway traffic).
  * You cannot force real-world online e-commerce users to start their website session on an arbitrary confirmation or checkout page.
* **On-Policy $\varepsilon$-Greedy Control:**
  * **HIGHLY PRACTICAL and deployable.**
  * The agent starts naturally from standard starting states (e.g., parked position, website homepage).
  * Exploration happens organically at each time step through small, continuous probabilistic choices ($\varepsilon$).

---

### (c) Optimality Guarantee of the Converged Policy
* **Exploring Starts (MC-ES):**
  * Converges to the **TRUE OPTIMAL POLICY $\pi^*$**.
  * Because the policy is strictly greedy and all pairs are sampled via exploring starts, it achieves the global maximum return $V^*(s)$.
* **On-Policy $\varepsilon$-Greedy Control:**
  * Converges **ONLY to the best $\varepsilon$-soft policy** ($\pi_\varepsilon^*$), NOT the true optimal policy $\pi^*$.
  * Because it is forced to take random exploratory actions with probability $\varepsilon$, its return is suboptimal (it continually makes random mistakes).
  * *Fix:* To reach $\pi^*$, $\varepsilon$ must be decayed over time following GLIE conditions (Greedy in the Limit with Infinite Exploration: $\varepsilon_k \to 0$ as $k \to \infty$).

---

### Comparison Table (Important for Exams)

| Dimension | Exploring Starts (MC-ES) | On-Policy $\varepsilon$-Greedy Control |
| :--- | :--- | :--- |
| **(a) Improvement Operator** | Strictly greedy: $\pi(s) \leftarrow \arg\max_a Q(s, a)$. | $\varepsilon$-soft update: weights greedy action by $1 - \varepsilon + \frac{\varepsilon}{|A|}$. |
| **(b) Real-World Feasibility** | **Impossible:** Requires arbitrary environmental state-action teleportation. | **Feasible:** Starts from standard states; explores organically. |
| **(c) Convergence Guarantee** | Converges to true optimal policy $\pi^*$. | Converges to best $\varepsilon$-soft policy $\pi_\varepsilon^*$ (Suboptimal unless GLIE decayed). |
