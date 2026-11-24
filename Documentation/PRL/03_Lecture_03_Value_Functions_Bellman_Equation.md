# Section 3: Lecture 03 — Value Functions and the Bellman Equation

---

## Q11. [Bank Q21] State-Value Function as a Thermal Heatmap

### Prompt:
In Lecture 03, hypothetical state values under a reasonable policy on FrozenLake are given as $V(14) = 0.82, V(13) = 0.55, V(0) = 0.14$, and $V(11) = 0$. Explain why $V(11) = 0$ and why $V(14) > V(13) > V(0)$ even though the immediate reward on all frozen tiles (0, 13, 14) is identically zero.

### Response:

**First, understand what a state value means:** The value of a state $V(s)$ does **not** measure what you get right now on that tile. It measures the **expected discounted cumulative return from that state onward into the future until the episode ends**. Think of it as a "thermal heatmap" of proximity to the $+1$ goal.

---

### 1. Why is $V(11) = 0$?
* State $11$ is a **Hole (terminal absorbing state)**.
* When an agent steps into Hole 11, the episode terminates immediately.
* The reward for falling into a hole is $0$, and because the game is over, no further actions can be taken and no future rewards can ever be collected ($R_{t+k} = 0$ for all $k \ge 1$).
* By mathematical definition, the value of any terminal absorbing state is identically zero:
  $$\boxed{V(\text{Terminal}) = 0}$$

---

### 2. Why is $V(14) > V(13) > V(0)$ when immediate reward is 0 everywhere?
On FrozenLake, all frozen ice tiles ($0, 13, 14$) give an immediate reward of $r = 0$. The only positive reward in the entire grid is at **Goal 15 ($+1$)**.

* **State 14 ($V = 0.82$): Closest to Goal**
  * State 14 is directly adjacent to Goal 15.
  * With a single action (Right), the agent has a high chance of stepping into the goal in just 1 step.
  * That $+1$ reward is discounted by only one step ($\gamma^1 = 0.9^1$), yielding a very high value ($0.82$).

* **State 13 ($V = 0.55$): Further Away**
  * State 13 is located to the left of State 14.
  * To reach the goal, the agent must first transition through State 14, requiring at least 2 steps.
  * Future rewards are discounted more heavily ($\gamma^2 = 0.9^2 = 0.81$), plus there is risk of slipping into Hole 12 along the way. Hence $V(13) = 0.55 < V(14)$.

* **State 0 ($V = 0.14$): The Starting Line**
  * State 0 is at the top-left corner, at least 6 steps away from the Goal.
  * Reaching the goal requires surviving multiple slippery transitions past four deadly holes ($5, 7, 11, 12$).
  * The $+1$ reward is discounted by at least $\gamma^6 = (0.9)^6 \approx 0.53$, and the cumulative probability of not falling into any hole along the long path is low. Hence $V(0) = 0.14$ is the lowest.

---

### Heatmap Visualization

```
[State 0: V = 0.14]  --> Far from goal, high risk of holes
        |
        v
[State 13: V = 0.55] --> 2 steps away
        |
        v
[State 14: V = 0.82] --> 1 step away! (Hot tile)
        |
        v
[State 15: GOAL +1 ]
```

---

## Q12. [Bank Q24] Hand-Computing $Q(14, \text{Up})$

### Prompt:
Following the Lecture 03 Slide 11 convention (where $\gamma$ is already baked into the state values), suppose at State 14 the agent chooses Up (intended next state = 10, with $V(10) = 0.40, r = 0$). Because of slippery ice, there is an 80% chance of moving Up to State 10, a 10% chance of slipping Left to State 13 ($V(13) = 0.55, r = 0$), and a 10% chance of slipping Right into Goal 15 ($V(15) = 0, r = +1$). Compute $Q(14, \text{Up})$ and compare it against $Q(14, \text{Right}) = 0.88$ and $Q(14, \text{Left}) = 0.45$.

### Response:

**First, understand the formula:** The action-value $Q(s, a)$ is the expected payout of taking action $a$ in state $s$. We sum the product of transition probability times [immediate reward + successor state value] over all possible landing states:

$$Q(s, a) = \sum_{s', r} P(s', r \mid s, a) [r + V(s')]$$

---

### Step-by-Step Numerical Calculation

At State 14 with action $a = \text{Up}$, there are 3 possible outcomes:
1. **Move Up to State 10 (80% probability = 0.80):**
   * $r = 0$, $V(10) = 0.40$
   * Contribution $= 0.80 \times [0 + 0.40] = 0.320$

2. **Slip Left to State 13 (10% probability = 0.10):**
   * $r = 0$, $V(13) = 0.55$
   * Contribution $= 0.10 \times [0 + 0.55] = 0.055$

3. **Slip Right into Goal 15 (10% probability = 0.10):**
   * $r = +1$, $V(15) = 0$ (Terminal)
   * Contribution $= 0.10 \times [1 + 0] = 0.100$

Sum the three branches:
$$Q(14, \text{Up}) = 0.320 + 0.055 + 0.100$$
$$\boxed{Q(14, \text{Up}) = 0.475}$$

---

### Comparison with Other Actions at State 14

| Action | Successor Distribution | Action-Value $Q(14, a)$ | Ranking |
| :--- | :--- | :---: | :---: |
| **Right** | 80% Goal ($r=1$), 20% State 10 ($r=0$) | **$0.880$** | **1st (Greedy Best)** |
| **Up** | 80% State 10, 10% State 13, 10% Goal | **$0.475$** | **2nd** |
| **Left** | Slides towards State 13 | **$0.450$** | **3rd** |

### Analysis:
* $Q(14, \text{Right}) = 0.88$ is by far the best action because it directly targets Goal 15.
* Notice that **$Q(14, \text{Up}) = 0.475$ is strictly higher than $Q(14, \text{Left}) = 0.45$**. 
* **Why?** Because even though Up intends to go to State 10, the slippery ice gives a "lucky" 10% chance of slipping sideways directly into Goal 15, adding a solid $+0.10$ bonus to its expectation!

---

## Q13. [Bank Q26] Deconstructing the Bellman Expectation Equation Right-to-Left

### Prompt:
Write the complete Bellman Expectation Equation for $V_\pi(s)$:

$$
V_\pi(s) = \sum_{a \in \mathcal{A}} \pi(a \mid s) \sum_{s', r} P(s', r \mid s, a)[r + \gamma V_\pi(s')]
$$

Explain the physical and probabilistic meaning of each of the three nested components when read from right to left: (1) The Payout $[r + \gamma V_\pi(s')]$, (2) The Environment's Chaos $\sum_{s', r} P(s', r \mid s, a)[\dots]$, and (3) The Agent's Choice $\sum_{a \in \mathcal{A}} \pi(a \mid s)[\dots]$.

### Response:

**First, understand the beauty of Bellman:** The Bellman equation is simply an accounting identity for expected value. Reading it **from inside out (right to left)** reveals exactly how a single step of time unfolds in the universe.

---

### Visual Decomposition (Right-to-Left)

$$
V_\pi(s) = \underbrace{\sum_{a \in \mathcal{A}} \pi(a \mid s)}_{\text{(3) Agent's Choice}} \; \underbrace{\sum_{s', r} P(s', r \mid s, a)}_{\text{(2) Environment's Chaos}} \; \underbrace{\big[r + \gamma V_\pi(s')\big]}_{\text{(1) The Payout}}
$$

---

### 1. Component 1 (Rightmost): The Payout $[r + \gamma V_\pi(s')]$
* **Physical Meaning:** This is the total value of landing on a specific tile $s'$ after receiving immediate reward $r$.
* It decomposes the future into two parts:
  * $r$: Immediate reward received upon entering tile $s'$.
  * $\gamma V_\pi(s')$: Discounted future value of continuing from tile $s'$ onward.
* **Probabilistic Meaning:** A single deterministic realization of the return, conditioned on reaching state $s'$ with reward $r$.
* **FrozenLake Example (Landing at State 14 $\to$ Goal 15 vs. State 10):**
  * If the agent lands on **Goal 15** ($s'=15$): The immediate reward is $r = +1.0$. Because Goal 15 is terminal, its future value is $V_\pi(15) = 0$. The payout is: $1.0 + \gamma(0) = \mathbf{1.0}$.
  * If the agent slips into **State 10** ($s'=10$): The immediate reward is $r = 0$, but State 10 has remaining worth $V_\pi(10) = 0.40$. With discount $\gamma = 0.9$, the payout is: $0 + 0.9(0.40) = \mathbf{0.36}$.

---

### 2. Component 2 (Middle): The Environment's Chaos $\sum_{s', r} P(s', r \mid s, a)[\dots]$
* **Physical Meaning:** Once the agent commits to an action $a$, the environment's physics take over. On slippery ice, the agent cannot guarantee where it lands!
* This component takes the **expected value over nature's transition randomness**: it multiplies every possible landing payout by the environment's transition probability $P(s', r \mid s, a)$.
* **Result:** This inner expectation computes the action-value $Q_\pi(s, a)$:
  $$Q_\pi(s, a) = \sum_{s', r} P(s', r \mid s, a)[r + \gamma V_\pi(s')]$$
* **FrozenLake Example (Choosing Action $a = \text{Right}$ at State 14):**
  * Even though the agent chose to move **Right** toward Goal 15, the ice is slippery:
    * 80% chance of reaching Goal 15 ($r=1, V=0 \implies \text{Payout} = 1.0$)
    * 20% chance of slipping into State 10 ($r=0, V=0.40 \implies \text{Payout} = 0.36$)
  * Averaging over nature's ice physics computes the expected action-value: $Q_\pi(14, \text{Right}) = 0.8(1.0) + 0.2(0.36) = 0.80 + 0.072 = \mathbf{0.872} \approx 0.88$.

---

### 3. Component 3 (Leftmost): The Agent's Choice $\sum_{a \in \mathcal{A}} \pi(a \mid s)[\dots]$
* **Physical Meaning:** The agent may not pick the same action every time; it might follow a stochastic policy $\pi(a \mid s)$ (e.g., exploring or choosing between directions).
* This component takes the **expected value over the agent's decision randomness**: it weights the quality of each action $Q_\pi(s, a)$ by the probability $\pi(a \mid s)$ that the agent actually selects that action.
* **Result:** Averaging over all available actions yields the overall state value $V_\pi(s)$.
* **FrozenLake Example (Agent deciding what action to take at State 14):**
  * Suppose the agent follows a stochastic policy at State 14:
    * $\pi(\text{Right} \mid 14) = 0.8$ (80% confidence aiming for Goal, where $Q_\pi(14, \text{Right}) \approx 0.88$)
    * $\pi(\text{Left} \mid 14) = 0.2$ (20% cautious safety exploration, where $Q_\pi(14, \text{Left}) \approx 0.45$)
  * Averaging over the agent's policy choices gives the final state value: $V_\pi(14) = 0.8 \times Q_\pi(14, \text{Right}) + 0.2 \times Q_\pi(14, \text{Left}) = 0.8(0.88) + 0.2(0.45) = 0.704 + 0.090 = \mathbf{0.794}$.

---

### Summary Table (Right-to-Left Decomposition)

| Layer (Right to Left) | Mathematical Term | What it Represents | FrozenLake Example (at State 14) |
| :--- | :--- | :--- | :--- |
| **(1) The Payout** | $r + \gamma V_\pi(s')$ | Immediate tile reward + future discounted worth. | Landing on Goal 15 yields $1.0 + 0 = 1.0$; landing on State 10 yields $0 + 0.9(0.40) = 0.36$. |
| **(2) Environment's Chaos** | $\sum_{s', r} P(s', r \mid s, a)[\dots]$ | Action-Value $Q_\pi(s, a)$ (resolves nature's ice slipping). | Choosing Right: $0.8(\text{Goal 15}) + 0.2(\text{State 10}) \implies Q_\pi(14, \text{Right}) \approx 0.88$. |
| **(3) Agent's Choice** | $\sum_{a \in \mathcal{A}} \pi(a \mid s)[\dots]$ | Overall State-Value $V_\pi(s)$ (resolves agent's policy randomness). | Policy weights: $0.8 \times Q(\text{Right}) + 0.2 \times Q(\text{Left}) \implies V_\pi(14) \approx 0.794$. |

---

## Q14. [Bank Q28] Interactive Checkpoint — Deterministic Ice & Deterministic Policy

### Prompt:
Answer the two theoretical questions from Lecture 03 Slide 19:
(a) In the Slide 11 example ($Q(14, \text{Right}) = 0.8(1 + \gamma \cdot 0) + 0.2(0 + \gamma \cdot 0.40) \approx 0.88$), how would $Q(14, \text{Right})$ change if the ice became perfectly deterministic (no slipping)?
(b) In the full Bellman Expectation Equation for $V_\pi(s)$, which summation(s) and probability distributions collapse if both the environment $P$ and the policy $\pi$ are deterministic? Write the simplified equation.

### Response:

**First, understand what "deterministic" means:** Deterministic means zero randomness. Probability distributions become delta functions (probability 1 for one outcome, 0 for all others), and summations disappear.

---

### (a) How does $Q(14, \text{Right})$ change with deterministic ice?
* In the Slide 11 example on slippery ice, choosing Right had an 80% chance of reaching Goal 15 ($r=1$) and a 20% chance of slipping to State 10 ($r=0, V=0.40$):
  $$Q(14, \text{Right}) = 0.8(1) + 0.2(0.40) = 0.88$$
* **If the ice is perfectly deterministic (no slipping):**
  * The transition probability to Goal 15 becomes $1.0$ (100%).
  * The slip probability to State 10 becomes $0.0$.
  * Therefore: $Q(14, \text{Right}) = 1.0 \times [1 + \gamma V(15)] = 1.0 \times [1 + 0] = \mathbf{1.0}$.

---

### (b) Collapsing the full Bellman Expectation Equation

Recall the full stochastic equation:
$$V_\pi(s) = \sum_{a \in A} \pi(a \mid s) \sum_{s', r} P(s', r \mid s, a) [r + \gamma V_\pi(s')]$$

If both the policy $\pi$ and environment $P$ are deterministic:
1. **The Policy collapses:** The agent chooses a single deterministic action $a = \pi(s)$ with probability 1. The outer sum $\sum_a \pi(a \mid s)$ vanishes.
2. **The Environment collapses:** Choosing action $a$ leads to a single unique next state $s' = f(s, a)$ and reward $r = R(s, a)$ with probability 1. The inner sum $\sum_{s', r} P(s', r \mid s, a)$ vanishes.

#### The Simplified Deterministic Bellman Equation:
$$\boxed{V(s) = R(s, \pi(s)) + \gamma V\big(f(s, \pi(s))\big)}$$
or simply:
$$\boxed{V(s) = R_{t+1} + \gamma V(S_{t+1})}$$
