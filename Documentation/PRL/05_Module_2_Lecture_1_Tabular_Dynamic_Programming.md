# Section 5: Module 2, Lecture 1 — Tabular Methods & Dynamic Programming

---

## Q19. [Bank Q41] Model-Based vs. Model-Free RL & the City-Map Analogy

### Prompt:
Compare Model-Based RL and Model-Free RL across all five properties from Slide 7 of Module 2 Lecture 1 (Transition model $p$, Reward model $r$, Planning, Interaction, and representative Algorithms), and explain how the "City-Map Intuition" (Slide 6) illustrates this distinction.

### Response:

**First, understand the core concept:** In reinforcement learning, the biggest dividing line is whether the agent possesses an internal "simulator" or "rulebook" of how the world works (a **model**), or whether it must learn purely by jumping into the world and trying things out (**model-free**).

---

### The City-Map Analogy (Slide 6 Intuition)

* **Model-Based RL is like navigating a city with a complete street map and GPS:**
  * You sit at home at your desk. You look at the map.
  * You plan your route: *"If I turn left on Elm St, then right on 4th Ave, I avoid the highway traffic."*
  * You do not need to physically drive around and hit dead ends to figure out the fastest route; you **plan in your head** using the map.
* **Model-Free RL is like navigating a city with NO map:**
  * You are dropped in an unfamiliar city with zero GPS.
  * The only way to find the train station is to walk around, physically hit dead ends, make wrong turns, and remember: *"Turning left here led to a dead end, but turning right led to a main road."*
  * You learn strictly through **real experience and memory**.

---

### The 5 Properties Comparison Table (Slide 7)

| Property | Model-Based RL | Model-Free RL |
| :--- | :--- | :--- |
| **1. Transition Model ($p$)** | **Known / Learned:** Agent has access to $P(s' \mid s, a)$ (knows where actions lead). | **Unknown:** Agent has no idea where an action leads until it actually takes it. |
| **2. Reward Model ($r$)** | **Known / Learned:** Agent knows $R(s, a, s')$ (knows the score of any hypothetical outcome). | **Unknown:** Agent only observes the reward scalar after landing in the state. |
| **3. Planning** | **Yes:** Can perform mental simulations, tree search, and one-step lookahead without acting. | **No:** Cannot plan ahead in memory; must physically sample trajectories in the environment. |
| **4. Interaction** | Can learn with zero or minimal real-world interaction (by computing over the model). | Requires continuous trial-and-error interaction with the actual environment. |
| **5. Representative Algorithms** | Dynamic Programming (Policy Iteration, Value Iteration), Dyna-Q, AlphaZero, MCTS. | Monte Carlo (MC), TD(0), SARSA, Q-Learning, DQN, REINFORCE, PPO. |

---

## Q20. [Bank Q42] Why Direct Matrix Inversion is Replaced by Iterative Policy Evaluation

### Prompt:
For a finite MDP with $|S|$ states and a fixed policy $\pi$, the Bellman Expectation Equation $V^\pi = R^\pi + \gamma P^\pi V^\pi$ is a linear system $(I - \gamma P^\pi)V^\pi = R^\pi$. What is the computational time complexity of solving this system directly via matrix inversion, why is it intractable for large state spaces, and how does Iterative Policy Evaluation overcome this bottleneck?

### Response:

**First, understand the mathematical problem:** For a fixed policy, the Bellman expectation equation across all states forms a system of $|S|$ linear equations with $|S|$ unknowns. Mathematically, we could just invert the matrix to get the exact answer in one shot:

$$(I - \gamma P^\pi) V^\pi = R^\pi \implies V^\pi = (I - \gamma P^\pi)^{-1} R^\pi$$

So why doesn't practical RL do this?

---

### 1. Computational Time Complexity of Direct Matrix Inversion
* Inverting an $N \times N$ matrix (where $N = |S|$) using standard Gaussian elimination or LU decomposition has a time complexity of:
  $$\boxed{\mathcal{O}(|S|^3)}$$
* (Even with advanced theoretical matrix algorithms like Strassen or Coppersmith-Winograd, complexity remains roughly $\mathcal{O}(|S|^{2.81})$ or $\mathcal{O}(|S|^{2.37})$).

---

### 2. Why is it intractable for large state spaces?
* If $|S| = 100$ states (small toy problem):
  $$|S|^3 = 10^6 \text{ operations} \implies \text{Milliseconds (Trivial)}$$
* If $|S| = 10,000$ states (small game like Backgammon or mini-robotics):
  $$|S|^3 = 10^{12} \text{ operations} \implies \text{Several minutes to hours}$$
* If $|S| = 1,000,000$ states (realistic robotics or video game):
  $$|S|^3 = 10^{18} \text{ FLOPs} \implies \text{Over 30 years on a modern supercomputer!}$$
* Furthermore, storing the matrix $(I - \gamma P^\pi)$ requires $\mathcal{O}(|S|^2)$ memory ($10^6 \times 10^6 = 10^{12}$ floats $\approx 4 \text{ Terabytes of RAM}$).

---

### 3. How Iterative Policy Evaluation Overcomes This Bottleneck
Instead of an expensive one-shot inversion, **Iterative Policy Evaluation** turns the equation into an iterative succession of sweeps:

$$V_{k+1}(s) = \sum_{a} \pi(a \mid s) \sum_{s', r} P(s', r \mid s, a)[r + \gamma V_k(s')]$$

#### 1. Low Computational Cost Per Sweep:
For sparse transition matrices (where each state only connects to a few neighbors, say $b$ branching factor), each sweep takes only:

$$
\mathcal{O}(|S| \cdot |A| \cdot b)
$$

#### 2. Rapid Geometric Convergence:
Because the Bellman operator is a contraction mapping with factor $\gamma < 1$, the error shrinks exponentially:

$$
\Vert V_k - V^\pi \Vert_\infty \le \gamma^k \Vert V_0 - V^\pi \Vert_\infty
$$

* After just a modest number of sweeps $k$ (e.g., $k \approx 20$ to $50$), the values are accurate to several decimal places!
* Total cost is $\mathcal{O}(k \cdot |S|)$, which scales linearly with the number of states rather than cubically.

---

### Summary Comparison Table

| Feature | Direct Matrix Inversion | Iterative Policy Evaluation |
| :--- | :---: | :---: |
| **Mathematical Method** | $V^\pi = (I - \gamma P^\pi)^{-1} R^\pi$ | $V_{k+1} = T^\pi V_k$ (Repeated sweeps) |
| **Time Complexity** | $\mathcal{O}(|S|^3)$ | $\mathcal{O}(k \cdot |S| \cdot |A|)$ |
| **Memory Complexity** | $\mathcal{O}(|S|^2)$ (Dense matrix) | $\mathcal{O}(|S|)$ (Just store current values) |
| **Feasibility for Large $|S|$** | **Completely Intractable** | **Highly Efficient & Scalable** |

---

## Q21. [Bank Q43] Completing Iteration 2 on the $2\times 2$ Gridworld

### Prompt:
Consider the $2\times 2$ Gridworld from Slide 12 ($S_0$ Top-Left, $S_1$ Top-Right, $S_2$ Bottom-Left, $S_3$ Bottom-Right Goal; deterministic dynamics where hitting a wall keeps the agent in place; $r = +1$ upon entering $S_3$ and 0 otherwise; $\gamma = 0.9$; equiprobable random policy $\pi(a \mid s) = 0.25$ for all 4 actions). Given Iteration 1 values $V_1(S_0) = 0, V_1(S_1) = 0.25, V_1(S_2) = 0.25$, and $V_1(S_3) = 0$, Slide 15 computes $V_2(S_1) = 0.3625$. Compute the remaining Iteration 2 state values $V_2(S_0)$ and $V_2(S_2)$ step by step.

### Response:

**First, understand the $2\times 2$ environment geometry:**
```
+---------------+---------------+
| S_0 (Top-L)   | S_1 (Top-R)   |
+---------------+---------------+
| S_2 (Bot-L)   | S_3 (GOAL)    |
+---------------+---------------+
```
* **Actions:** Up, Down, Left, Right (each selected with probability $\pi = 0.25$).
* **Rewards:** Entering $S_3$ (Goal) gives $+1$; all other moves give $0$.
* **Goal $S_3$ is terminal absorbing:** $V(S_3) = 0$ permanently.
* **Discount factor:** $\gamma = 0.9$.
* **Iteration 1 Values:**
  $$V_1(S_0) = 0.0, \quad V_1(S_1) = 0.25, \quad V_1(S_2) = 0.25, \quad V_1(S_3) = 0.0$$

---

### Step 1: Compute $V_2(S_0)$ (Top-Left Cell)

Evaluate all 4 actions from $S_0$:
1. **Up:** Bumps top wall $\implies$ stays in $S_0$ ($r = 0$). Payout $= 0 + 0.9 V_1(S_0) = 0.9(0) = 0$.
2. **Left:** Bumps left wall $\implies$ stays in $S_0$ ($r = 0$). Payout $= 0 + 0.9 V_1(S_0) = 0.9(0) = 0$.
3. **Right:** Moves to $S_1$ ($r = 0$). Payout $= 0 + 0.9 V_1(S_1) = 0.9(0.25) = 0.225$.
4. **Down:** Moves to $S_2$ ($r = 0$). Payout $= 0 + 0.9 V_1(S_2) = 0.9(0.25) = 0.225$.

Now apply the policy expectation ($\pi = 0.25$ for all 4 actions):
$$V_2(S_0) = 0.25[0] + 0.25[0] + 0.25[0.225] + 0.25[0.225]$$
$$V_2(S_0) = 0.25 \times (0 + 0 + 0.225 + 0.225)$$
$$V_2(S_0) = 0.25 \times 0.450$$
$$\boxed{V_2(S_0) = 0.1125}$$

---

### Step 2: Compute $V_2(S_2)$ (Bottom-Left Cell)

Evaluate all 4 actions from $S_2$:
1. **Up:** Moves to $S_0$ ($r = 0$). Payout $= 0 + 0.9 V_1(S_0) = 0.9(0) = 0$.
2. **Down:** Bumps bottom wall $\implies$ stays in $S_2$ ($r = 0$). Payout $= 0 + 0.9 V_1(S_2) = 0.9(0.25) = 0.225$.
3. **Left:** Bumps left wall $\implies$ stays in $S_2$ ($r = 0$). Payout $= 0 + 0.9 V_1(S_2) = 0.9(0.25) = 0.225$.
4. **Right:** Steps directly into **Goal $S_3$**! ($r = +1, V_1(S_3) = 0$). Payout $= 1 + 0.9(0) = 1.0$.

Now apply the policy expectation ($\pi = 0.25$ for all 4 actions):
$$V_2(S_2) = 0.25[0] + 0.25[0.225] + 0.25[0.225] + 0.25[1.0]$$
$$V_2(S_2) = 0.25 \times (0 + 0.225 + 0.225 + 1.0)$$
$$V_2(S_2) = 0.25 \times 1.450$$
$$\boxed{V_2(S_2) = 0.3625}$$

(Notice that $V_2(S_2) = 0.3625$ matches $V_2(S_1) = 0.3625$ exactly, confirming the perfect diagonal symmetry of the grid!)

---

### Complete Iteration 2 Table

| State | Formula Calculation | Exact Fraction | Decimal Value |
| :---: | :--- | :---: | :---: |
| **$S_0$** | $0.25(0 + 0 + 0.225 + 0.225)$ | $9/80$ | **$0.1125$** |
| **$S_1$** | $0.25(0 + 0.225 + 0.225 + 1.0)$ | $29/80$ | **$0.3625$** |
| **$S_2$** | $0.25(0 + 0.225 + 0.225 + 1.0)$ | $29/80$ | **$0.3625$** |
| **$S_3$** | Terminal Absorbing Goal | $0$ | **$0.0000$** |

---

## Q22. [Bank Q46] Bellman Operator $T^\pi$ Contraction & Number of Sweeps to Convergence

### Prompt:
Under standard discounted finite-MDP assumptions, the Bellman operator $T^\pi$ satisfies the contraction property:

$$
\Vert T^\pi V - T^\pi W \Vert_\infty \le \gamma \Vert V - W \Vert_\infty
$$

(a) State the theorem that guarantees a unique fixed point $V^\pi$ from this inequality.

(b) If the initial error satisfies:

$$
\Vert V_0 - V^\pi \Vert_\infty \le 1.0
$$

with $\gamma = 0.9$, what is the maximum error bound after $k = 5$ sweeps, and what is the minimum number of sweeps $k$ required to guarantee:

$$
\Vert V_k - V^\pi \Vert_\infty \le 0.01 \text{ ?}
$$

### Response:

**First, understand what a contraction mapping is:** A contraction mapping takes any two value vectors and squashes them closer together by a factor of at least $\gamma$. Because each sweep pulls vectors closer together, repeating sweeps is guaranteed to zero in on a single, unique solution.

---

### (a) The Governing Theorem
The theorem is the **Banach Fixed-Point Theorem** (also known as the **Contraction Mapping Theorem**).

#### Theorem Statement:
In a complete metric space (such as $\mathbb{R}^{|S|}$ equipped with the supremum norm $\Vert \cdot \Vert_\infty$), any contraction mapping $T$ with contraction factor $\gamma \in [0, 1)$ has a **unique fixed point** $V^*$ such that:

1. **Fixed-Point Identity:**
$$T V^* = V^*$$

2. **Guaranteed Linear Convergence:**
For any arbitrary starting vector $V_0$, the sequence $V_{k+1} = T V_k$ converges to $V^*$ at a linear rate:

$$
\lim_{k \to \infty} V_k = V^*
$$

---

### (b) Numerical Calculations ($\gamma = 0.9$, Initial Error Bound $\le 1.0$)

#### Contraction Error Bound Formula:

$$
\Vert V_k - V^\pi \Vert_\infty \le \gamma^k \Vert V_0 - V^\pi \Vert_\infty
$$

#### 1. Maximum Error Bound after $k = 5$ sweeps:

$$
\Vert V_5 - V^\pi \Vert_\infty \le (0.9)^5 \times 1.0
$$

$$(0.9)^5 = 0.59049$$

$$
\boxed{\Vert V_5 - V^\pi \Vert_\infty \le 0.5905}
$$

---

#### 2. Minimum Sweeps $k$ to Guarantee Error $\le 0.01$:
We need:

$$
\gamma^k \Vert V_0 - V^\pi \Vert_\infty \le 0.01
$$
$$(0.9)^k \times 1.0 \le 0.01$$
$$(0.9)^k \le 0.01$$

Take the natural logarithm ($\ln$) of both sides:
$$\ln\big((0.9)^k\big) \le \ln(0.01)$$
$$k \cdot \ln(0.9) \le \ln(0.01)$$

**Note:** Since $\ln(0.9)$ is negative, dividing by $\ln(0.9)$ flips the inequality sign:
$$k \ge \frac{\ln(0.01)}{\ln(0.9)}$$

Substitute numerical values:
* $\ln(0.01) \approx -4.60517$
* $\ln(0.9) \approx -0.10536$

$$k \ge \frac{-4.60517}{-0.10536} \approx 43.709$$

Since $k$ must be an integer number of full sweeps:
$$\boxed{k = 44 \text{ sweeps}}$$

---

### Summary Table

| Sweeps ($k$) | Error Formula ($\gamma^k$) | Numerical Error Bound | Status |
| :---: | :---: | :---: | :---: |
| $k = 0$ | $(0.9)^0$ | $1.0000$ | Starting Error |
| $k = 5$ | $(0.9)^5$ | **$0.5905$** | Bound after 5 sweeps |
| $k = 10$ | $(0.9)^{10}$ | $0.3487$ | Halfway |
| $k = 43$ | $(0.9)^{43}$ | $0.0107$ | $> 0.01$ (Not yet guaranteed) |
| **$k = 44$** | $(0.9)^{44}$ | **$0.0096$** | **$\le 0.01$ Guaranteed!** |

---

## Q23. [Bank Q47] Full Policy Improvement & Convergence to $\pi^*$ on the $2\times 2$ Gridworld

### Prompt:
Starting from the evaluated random policy values on Slide 23 ($V(S_0) \approx 0.05, V(S_1) = V(S_2) \approx 0.36, V(S_3) = 0$):
(a) Compute all four action-values $q^\pi(s, a)$ for $a \in \{\text{Up}, \text{Down}, \text{Left}, \text{Right}\}$ at both $S_0$ and $S_1$.
(b) Determine the greedy policy $\pi'(s) \in \arg\max_a q^\pi(s, a)$ for $S_0, S_1, S_2$.
(c) Evaluate this new deterministic policy $\pi'$ to find $V^\ast(S_0), V^\ast(S_1), V^\ast(S_2), V^\ast(S_3)$ and verify that Policy Iteration terminates on the next improvement step (`policy_stable = true`).

### Response:

**First, understand Policy Improvement:** Once we evaluate a policy, we ask: "At each state, if I could greedily choose the single best action based on one-step lookahead $q(s, a) = r + \gamma V(s')$, which action wins?" Switching to those winning actions creates an improved policy.

---

### (a) Compute all four action-values $q^\pi(s, a)$ at $S_0$ and $S_1$
Recall: $V(S_0) = 0.05, V(S_1) = 0.36, V(S_2) = 0.36, V(S_3) = 0, \gamma = 0.9$. Entering $S_3$ yields $r = +1$, else $r = 0$.

#### 1. At State $S_0$ (Top-Left):
* **Up:** Hits wall $\to S_0$. $q(S_0, \text{Up}) = 0 + 0.9 V(S_0) = 0.9(0.05) = \mathbf{0.045}$
* **Left:** Hits wall $\to S_0$. $q(S_0, \text{Left}) = 0 + 0.9 V(S_0) = 0.9(0.05) = \mathbf{0.045}$
* **Right:** Moves to $S_1$. $q(S_0, \text{Right}) = 0 + 0.9 V(S_1) = 0.9(0.36) = \mathbf{0.324}$
* **Down:** Moves to $S_2$. $q(S_0, \text{Down}) = 0 + 0.9 V(S_2) = 0.9(0.36) = \mathbf{0.324}$

#### 2. At State $S_1$ (Top-Right):
* **Up:** Hits wall $\to S_1$. $q(S_1, \text{Up}) = 0 + 0.9 V(S_1) = 0.9(0.36) = \mathbf{0.324}$
* **Right:** Hits wall $\to S_1$. $q(S_1, \text{Right}) = 0 + 0.9 V(S_1) = 0.9(0.36) = \mathbf{0.324}$
* **Left:** Moves to $S_0$. $q(S_1, \text{Left}) = 0 + 0.9 V(S_0) = 0.9(0.05) = \mathbf{0.045}$
* **Down:** Steps into **Goal $S_3$**! $q(S_1, \text{Down}) = +1 + 0.9 V(S_3) = 1 + 0 = \mathbf{1.000}$

---

### (b) Determine the greedy policy $\pi'(s) \in \arg\max_a q^\pi(s, a)$
* **At $S_1$:** $\max(0.324, 0.324, 0.045, \mathbf{1.000}) \implies \boxed{\pi'(S_1) = \text{Down}}$
* **At $S_2$:** By symmetry with $S_1$ (Right enters Goal $S_3$) $\implies \boxed{\pi'(S_2) = \text{Right}}$
* **At $S_0$:** $\max(0.045, 0.045, \mathbf{0.324}, \mathbf{0.324}) \implies$ Tie between Right and Down! Breaking tie systematically: $\boxed{\pi'(S_0) = \text{Right}}$ (or Down).

---

### (c) Evaluate the new deterministic policy $\pi^\ast$ and verify termination

Under the new policy $\pi'$:

* **From $S_1$ (Takes Down $\to S_3$ Goal):** $V^\ast(S_1) = 1 + \gamma V^\ast(S_3) = 1 + 0 = \mathbf{1.0}$
* **From $S_2$ (Takes Right $\to S_3$ Goal):** $V^\ast(S_2) = 1 + \gamma V^\ast(S_3) = 1 + 0 = \mathbf{1.0}$
* **From $S_0$ (Takes Right $\to S_1$):** $V^\ast(S_0) = 0 + \gamma V^\ast(S_1) = 0.9(1.0) = \mathbf{0.9}$
* **From $S_3$ (Terminal Goal):** $V^\ast(S_3) = \mathbf{0.0}$

#### Verify Policy Stability on the next iteration:
Recompute greedy actions under $V^\ast = [0.9, 1.0, 1.0, 0]$:
* At $S_1$: $q(S_1, \text{Down}) = 1.0 > q(S_1, \text{Up/Right}) = 0.9 \implies$ **Down wins (No change)**.
* At $S_2$: $q(S_2, \text{Right}) = 1.0 > q(S_2, \text{Down/Left}) = 0.9 \implies$ **Right wins (No change)**.
* At $S_0$: $q(S_0, \text{Right}) = 0.9(1.0) = 0.9 \implies$ **Right wins (No change)**.

Because the policy does not change at any state:

$$
\boxed{\text{policy\textunderscore stable} = \text{True}}
$$

Policy Iteration terminates successfully having found the provably optimal policy $\pi^\ast$.
