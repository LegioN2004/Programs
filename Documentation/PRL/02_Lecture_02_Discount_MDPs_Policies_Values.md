# Section 2: Lecture 02 — The Discount Factor, MDPs, Policies & Value Functions

---

## Q6. [Bank Q11] Numerical Discounted Return Calculation

### Prompt:
An agent in a 4-step episode observes the future reward sequence $R_{t+1} = 4, R_{t+2} = -2, R_{t+3} = 10$, and $R_{t+4} = 5$ (after which the episode terminates). Calculate the exact discounted return $G_t$ when the discount factor is $\gamma = 0.5$.

### Response:

**First, understand the concept:** The **discounted return** ($G_t$) is the total accumulated reward where future rewards are multiplied by powers of the discount factor $\gamma$. Rewards received sooner are worth more; rewards in the distant future are discounted (decayed) because a bird in the hand is worth two in the bush.

---

### The Formula:
$$G_t = \sum_{k=0}^{\infty} \gamma^k R_{t+k+1} = R_{t+1} + \gamma R_{t+2} + \gamma^2 R_{t+3} + \gamma^3 R_{t+4}$$

---

### Step-by-Step Calculation:
Given:
* $\gamma = 0.5$
* $R_{t+1} = 4$
* $R_{t+2} = -2$
* $R_{t+3} = 10$
* $R_{t+4} = 5$

Substitute the values into the formula:
$$G_t = 4 + (0.5)(-2) + (0.5)^2(10) + (0.5)^3(5)$$

Compute each term individually:
1. First step ($k=0$): $R_{t+1} = 4$
2. Second step ($k=1$): $\gamma R_{t+2} = 0.5 \times (-2) = -1.0$
3. Third step ($k=2$): $\gamma^2 R_{t+3} = 0.25 \times 10 = +2.5$
4. Fourth step ($k=3$): $\gamma^3 R_{t+4} = 0.125 \times 5 = +0.625$

Sum them up:
$$G_t = 4 - 1.0 + 2.5 + 0.625$$
$$G_t = 3.0 + 3.125$$
$$\boxed{G_t = 6.125 = \frac{49}{8}}$$

---

### Summary Table

| Step | Reward ($R_{t+k}$) | Weight ($\gamma^{k-1}$) | Discounted Contribution |
| :---: | :---: | :---: | :---: |
| Step 1 | $+4$ | $1.0$ | $+4.000$ |
| Step 2 | $-2$ | $0.5$ | $-1.000$ |
| Step 3 | $+10$ | $0.25$ | $+2.500$ |
| Step 4 | $+5$ | $0.125$ | $+0.625$ |
| **Total** | — | — | **$6.125$** |

---

## Q7. [Bank Q13] Myopic ($\gamma = 0$) vs. Far-Sighted ($\gamma \to 1$) Decision Threshold

### Prompt:
At state $S_0$, an agent must choose between two deterministic paths:
* **Path 1:** yields $R_1 = +10, R_2 = 0, R_3 = 0$, and then terminates.
* **Path 2:** yields $R_1 = 0, R_2 = 0, R_3 = +15$, and then terminates.

Determine which path a myopic agent ($\gamma = 0$) chooses, and solve for the exact threshold value of $\gamma \in (0, 1]$ above which a far-sighted agent strictly prefers Path 2 over Path 1.

### Response:

**First, understand the intuition:** 
* A **myopic agent** ($\gamma = 0$) has extreme "short-sightedness"—it only cares about what it gets right this second ($R_1$). Future rewards mean nothing to it.
* A **far-sighted agent** ($\gamma \to 1$) is patient—it is willing to wait through zeros today if a much bigger jackpot arrives later.

---

### 1. Which path does the myopic agent ($\gamma = 0$) choose?
When $\gamma = 0$, the return formula collapses to:
$$G = R_1 + 0 \cdot R_2 + 0 \cdot R_3 = R_1$$

* **Path 1 return:** $G^{(\text{Path 1})} = R_1 = +10$
* **Path 2 return:** $G^{(\text{Path 2})} = R_1 = 0$

Since $10 > 0$, the **myopic agent strictly chooses Path 1**.

---

### 2. Solve for the exact threshold $\gamma$ where Path 2 is preferred
Let us write the general discounted return for both paths as a function of $\gamma$:
* **Path 1:** $G_1(\gamma) = 10 + \gamma(0) + \gamma^2(0) = 10$
* **Path 2:** $G_2(\gamma) = 0 + \gamma(0) + \gamma^2(15) = 15\gamma^2$

The agent strictly prefers Path 2 over Path 1 when:
$$G_2(\gamma) > G_1(\gamma)$$
$$15\gamma^2 > 10$$
$$\gamma^2 > \frac{10}{15} = \frac{2}{3}$$
$$\gamma > \sqrt{\frac{2}{3}} = \frac{\sqrt{6}}{3} \approx 0.8165$$

---

### Decision Boundary Summary Table

| Discount Factor Range | Preference | Physical Meaning |
| :--- | :--- | :--- |
| $\gamma = 0$ | **Path 1** ($10$ vs $0$) | Completely myopic; takes immediate $+10$. |
| $0 \le \gamma < \sqrt{2/3} \approx 0.8165$ | **Path 1** ($10 > 15\gamma^2$) | Impatient; future $+15$ is discounted too heavily. |
| $\gamma = \sqrt{2/3} \approx 0.8165$ | **Indifferent** ($10 = 10$) | Both paths yield identical present discounted value. |
| $\sqrt{2/3} < \gamma \le 1.0$ | **Path 2** ($15\gamma^2 > 10$) | Patient / Far-sighted; willing to wait for the $+15$ jackpot. |

---

## Q8. [Bank Q14] Formalizing the $4\times 4$ FrozenLake MDP Tuple

### Prompt:
Write out the five components of the MDP tuple $(S, A, P, R, \gamma)$ for the standard $4\times 4$ slippery FrozenLake environment from Lecture 02, explicitly listing all hole state indices, the start and goal state indices, the numerical encoding of the four actions (0, 1, 2, 3), the reward rule for holes vs. the goal, and the slippery transition rule.

### Response:

**First, understand the setup:** FrozenLake is a classic gridworld where an agent navigates a frozen lake. Some tiles are safe frozen ice, some are deadly water holes, and one is the goal. Because the ice is slippery, the agent does not always move in the intended direction.

---

### The 5 Components of the MDP Tuple $(S, A, P, R, \gamma)$:

#### 1. State Space ($S$):
A discrete grid of $16$ cells indexed from $0$ to $15$ in row-major order:
$$S = \{0, 1, 2, \dots, 15\}$$
* **Start State:** State $0$ (Top-Left)
* **Goal State:** State $15$ (Bottom-Right, Terminal Absorbing)
* **Hole States:** Four terminal absorbing water holes:
  $$\text{Holes} = \{5, 7, 11, 12\}$$
* **Frozen Safe States:** $\{0, 1, 2, 3, 4, 6, 8, 9, 10, 13, 14\}$

Grid Layout:
```
[ 0: S ]  [ 1: F ]  [ 2: F ]  [ 3: F ]
[ 4: F ]  [ 5: H ]  [ 6: F ]  [ 7: H ]
[ 8: F ]  [ 9: F ]  [10: F ]  [11: H ]
[12: H ]  [13: F ]  [14: F ]  [15: G ]
```

#### 2. Action Space ($A$):
Four discrete directions encoded as integers:
$$A = \{0, 1, 2, 3\}$$
* $0 = \text{Left}$
* $1 = \text{Down}$
* $2 = \text{Right}$
* $3 = \text{Up}$

#### 3. Transition Probability Function ($P$):
Because the ice is slippery (`is_slippery=True`), when the agent selects action $a$:
* It moves in the **intended direction** with probability $\frac{1}{3}$.
* It slips into the **perpendicular direction to the left** with probability $\frac{1}{3}$.
* It slips into the **perpendicular direction to the right** with probability $\frac{1}{3}$.
* **Boundary condition:** If any transition leads into a boundary wall, the agent bounces off the wall and remains in its current state.
* **Terminal absorbing condition:** Once the agent enters any Hole ($5, 7, 11, 12$) or the Goal ($15$), the episode terminates ($P(s|s, a) = 1$ with $r = 0$).

#### 4. Reward Function ($R$):
$$R(s, a, s') = \begin{cases} +1, & \text{if } s' = 15 \text{ (Goal reached)} \\ 0, & \text{for all other transitions (including falling into Holes)} \end{cases}$$

#### 5. Discount Factor ($\gamma$):
A scalar parameter $\gamma \in [0, 1)$ (typically $\gamma = 0.9$ or $0.99$) that ensures finite convergence and penalizes prolonged wandering.

---

## Q9. [Bank Q16] Boundary Reflection & Hole Avoidance on Frozen Lake

### Prompt:
Consider an agent standing on State 1 (top row, second column; bounded above by the top wall, left by State 0, right by State 2, and below by Hole 5) on slippery Frozen Lake.
(a) Write the complete transition probability distribution $P(s' \mid s = 1, a = \text{Right})$, and state the probability of falling into Hole 5 in one step.
(b) Suppose instead the agent chooses $a = \text{Up}$ at State 1. Write $P(s' \mid s = 1, a = \text{Up})$ and explain why choosing Up guarantees 0% probability of falling into Hole 5 on that step while still giving a 1/3 chance of advancing to State 2.

### Response:

**First, understand the geometry of State 1:**
* Above State 1 is the **Top Wall** (bounce back to 1).
* To the left is **State 0**.
* To the right is **State 2**.
* Below is **Hole 5** (DANGER!).

Under slippery physics, any chosen action results in $\frac{1}{3}$ intended direction, and $\frac{1}{3}$ to each of the two perpendicular directions.

---

### (a) Action $a = \text{Right}$ at State 1

When the agent chooses $a = \text{Right}$:
1. **Intended direction (Right, prob 1/3):** Moves to **State 2**.
2. **Perpendicular 1 (Up, prob 1/3):** Bumps into the top wall $\implies$ bounces back and **remains in State 1**.
3. **Perpendicular 2 (Down, prob 1/3):** Slides down into **Hole 5**!

#### Transition Probability Distribution:
$$P(s' \mid s = 1, a = \text{Right}) = \begin{cases} 1/3, & s' = 2 \text{ (Right)} \\ 1/3, & s' = 1 \text{ (Up: wall bounce)} \\ 1/3, & s' = 5 \text{ (Down: Hole!)} \\ 0, & \text{otherwise} \end{cases}$$

$$\boxed{\text{Probability of falling into Hole 5} = \frac{1}{3} \approx 33.33\%}$$

---

### (b) Action $a = \text{Up}$ at State 1

When the agent chooses $a = \text{Up}$:
1. **Intended direction (Up, prob 1/3):** Hits the top wall $\implies$ bounces back and **remains in State 1**.
2. **Perpendicular 1 (Left, prob 1/3):** Slides left to **State 0**.
3. **Perpendicular 2 (Right, prob 1/3):** Slides right to **State 2**.

#### Transition Probability Distribution:
$$P(s' \mid s = 1, a = \text{Up}) = \begin{cases} 1/3, & s' = 0 \text{ (Left)} \\ 1/3, & s' = 1 \text{ (Up: wall bounce)} \\ 1/3, & s' = 2 \text{ (Right)} \\ 0, & s' = 5 \text{ (Down)} \end{cases}$$

#### Why does $a = \text{Up}$ guarantee 0% chance of falling into Hole 5?
* Down (where Hole 5 sits) is the **opposite** (reverse) direction to Up ($180^\circ$ away), **not a perpendicular direction** ($90^\circ$).
* The FrozenLake slippery physics engine *only* slips perpendicular to the chosen action ($\pm 90^\circ$). It never slips backwards ($180^\circ$).
* Therefore, by aiming straight into the top wall ($a = \text{Up}$):
  * $P(\text{Hole 5} \mid 1, \text{Up}) = 0\%$.
  * There is still a $\frac{1}{3}$ (33.33%) chance of sliding sideways into **State 2**, making progress towards the goal without risking death!

---

### Summary Table

| Action Chosen | Intended (1/3) | Slip 1 (1/3) | Slip 2 (1/3) | Probability of Hole 5 |
| :---: | :---: | :---: | :---: | :---: |
| **Right** | State 2 | State 1 (Wall bounce) | **Hole 5** | **33.33% (Dangerous)** |
| **Up** | State 1 (Wall bounce) | State 0 | **State 2** | **0% (100% Safe!)** |

---

## Q10. [Bank Q18] Deterministic vs. Stochastic Policies

### Prompt:
Define a policy mathematically. What is the difference between a deterministic policy $\pi : S \to A$ and a stochastic policy $\pi(a \mid s) = \Pr(A_t = a \mid S_t = s)$? How many distinct deterministic policies exist on the 11 non-terminal states of the $4\times 4$ Frozen Lake grid with 4 actions per state?

### Response:

**First, understand what a policy is:** In simple terms, a **policy** is the agent's brain or rulebook. It tells the agent: *"Whenever you find yourself in state $s$, here is the action you should take."*

---

### 1. Mathematical Definitions and Differences

* **Deterministic Policy ($\pi : S \to A$):**
  * A direct functional mapping from each state to a single, definite action:
    $$a = \pi(s)$$
  * Given state $s$, there is no randomness; the agent always executes action $a$ with 100% probability.
  * *Example:* "If in State 14, always pick action Right."

* **Stochastic Policy ($\pi(a \mid s) = \Pr(A_t = a \mid S_t = s)$):**
  * A conditional probability distribution over the set of actions given state $s$:
    $$\pi(a \mid s) \ge 0, \quad \sum_{a \in A} \pi(a \mid s) = 1 \quad \forall s \in S$$
  * Given state $s$, the agent rolls dice according to the assigned probabilities.
  * *Example:* "If in State 14, choose Right with 80% probability, and Left with 20% probability."

---

### 2. How many distinct deterministic policies exist on the 11 non-terminal states?

#### Combinatorial Rule:
For any finite MDP with $|S_{\text{non-term}}|$ non-terminal states and $|A|$ discrete actions available at each state, each state can independently choose any of the $|A|$ actions.
$$\text{Total Deterministic Policies} = |A|^{|S_{\text{non-term}}|}$$

#### Substituting FrozenLake Values:
* Number of non-terminal states: $|S_{\text{non-term}}| = 11$ (16 total cells minus 4 holes minus 1 goal).
* Number of actions per state: $|A| = 4$ (Left, Down, Right, Up).

$$\text{Total Policies} = 4^{11}$$
$$4^{11} = (2^2)^{11} = 2^{22}$$
$$\boxed{4^{11} = 4,194,304 \text{ distinct policies}}$$

---

### Comparison Table

| Attribute | Deterministic Policy | Stochastic Policy |
| :--- | :--- | :--- |
| **Mathematical Form** | Function $\pi(s) = a$ | Distribution $\pi(a \mid s) = \Pr(A_t = a \mid S_t = s)$ |
| **Exploration** | Cannot explore without external noise ($\varepsilon$-greedy). | Naturally explores via randomized sampling. |
| **Game Theory** | Inadequate for bluffing or Rock-Paper-Scissors. | Essential for mixed Nash equilibria. |
| **Total on 11 States** | $4^{11} = 4,194,304$ | Infinitely many (continuous probability simplex). |
