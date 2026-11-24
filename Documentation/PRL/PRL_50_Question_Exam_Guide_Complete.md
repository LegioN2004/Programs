# CSE-ELV-701: Practical Reinforcement Learning
## High-Yield 50-Question Problem Bank (Comprehensive Solutions Guide)

*Department of Computer Science & Engineering*  
*Curated from the 110-Question Master Problem Bank*  
*Theme: Direct, easy-to-understand explanations with intuitive breakdowns and step-by-step mathematical solutions.*

---

## 3-Day Study Schedule

| Study Day | Target Module Sections | Questions Covered | Workload |
| :--- | :--- | :---: | :---: |
| **Day 1 (Nov 22)** | Sections 1–4: RL Foundations, Discount Factor, MDPs, Bellman Equations & Numerical Backups | **Q1 – Q18** | 18 Questions |
| **Day 2 (Nov 23)** | Sections 5–8: Dynamic Programming, Monte Carlo Prediction/Control, TD(0), SARSA & Q-Learning | **Q19 – Q37** | 19 Questions |
| **Day 3 (Nov 24)** | Sections 9–11: SARSA vs. Q-Learning Traces, Deep Q-Networks (DQN), Policy Gradient & REINFORCE | **Q38 – Q50** | 13 Questions + Revision |

---

# Section 1: Lecture 01 — Introduction to Reinforcement Learning

---

## Q1. [Bank Q1] Supervised vs. Reinforcement Learning Paradigm

### Prompt:
Contrast the "Teacher Model" of supervised learning with the trial-and-error paradigm of reinforcement learning across three dimensions: (a) availability of a predefined answer key, (b) environmental reactivity to agent decisions, and (c) stability of the target mapping.

### Response:

**First, understand the core difference:** In supervised learning, the model is like a student learning from a teacher who provides an answer key for every question. In reinforcement learning (RL), there is no teacher or answer key; an agent interacts directly with an environment, takes actions, and discovers what works through rewards and penalties.

---

### (a) Availability of a predefined answer key

* **Supervised Learning (Teacher Model):**
  * The dataset contains input features ($X$) paired with explicit ground-truth labels ($Y$).
  * The learning algorithm compares its prediction $\hat{y}$ against the true label $y$ and computes a supervised loss (e.g., Cross-Entropy, Mean Squared Error).
  * *Example:* If we pass an image of a cat, the dataset explicitly tells the model: *"This is a Cat."*

* **Reinforcement Learning (Trial-and-Error):**
  * There is no predefined answer key telling the agent which action $A_t$ is best in state $S_t$.
  * Instead of an answer key, the environment provides only a scalar evaluative feedback signal: the reward $R_{t+1}$.
  * The reward only indicates how good or bad the outcome was, not whether an alternative action would have been better.
  * *Example:* A robotic vacuum navigating a room is not given the ideal steering angle at every second. It tries turning left, right, or moving forward, receiving $+1$ for vacuuming dirt and $-10$ for bumping into furniture.

---

### (b) Environmental reactivity to agent decisions

* **Supervised Learning:**
  * The environment is static and non-reactive.
  * The predictions made by the model do not change the future data points in the dataset.
  * *Example:* Classifying an email as spam today does not dynamically alter the text of the next email in the benchmark dataset.

* **Reinforcement Learning:**
  * The environment is dynamic and highly reactive.
  * The action $A_t$ selected by the agent directly changes the environment's state $S_{t+1}$, determining what situations the agent will face in the future.
  * *Example:* In autonomous driving, if the car chooses to steer right, it enters the right lane. All future states and traffic obstacles now depend on that steering decision.

---

### (c) Stability of the target mapping

* **Supervised Learning:**
  * The target mapping $f: X \to Y$ is stationary and stable.
  * The correct label for a given input remains constant throughout training.
  * *Example:* An image of a stop sign always corresponds to the label "Stop Sign", regardless of when it is sampled.

* **Reinforcement Learning:**
  * The target mapping is non-stationary and evolving.
  * The "value" or quality of an action in state $S$ depends on what the agent plans to do in future states (the policy $\pi$). As the policy improves, the expected future returns change, causing the learning targets to shift continuously.
  * *Example:* In chess, moving a knight to square c3 might look poor when the agent is a novice, but becomes a winning master move once the agent learns sophisticated follow-up tactical combinations.

---

### Comparison Table (Important for Exams)

| Dimension | Supervised Learning | Reinforcement Learning |
| :--- | :--- | :--- |
| **(a) Answer Key** | Explicit, predefined ground-truth labels ($Y$) provided for every input. | No answer key; agent receives only scalar evaluative reward feedback ($R_{t+1}$). |
| **(b) Environmental Reactivity** | Non-reactive; model predictions do not alter the training data distribution. | Reactive; agent actions directly alter the environment state ($S_{t+1}$) and future observations. |
| **(c) Target Mapping** | Stationary and fixed ($X \to Y$ mapping does not drift). | Non-stationary; targets shift as the agent's policy and future action choices improve. |

---

## Q2. [Bank Q4] Numerical Trajectory Scoring on the Delivery Drone

### Prompt:
Using the Lecture 01 reward function for the autonomous delivery drone (+1000 for successful delivery, −1000 for a crash, and −1 per second of flight time), compute the undiscounted cumulative return $G_0$ for:
* **Episode A:** The drone navigates strong headwinds and successfully drops the package on the customer's porch at $t = 145$ seconds (receiving −1 at each of the 145 seconds plus the terminal delivery bonus).
* **Episode B:** The drone's rotor stalls in a gust of wind and crashes into a tree at $t = 60$ seconds (receiving −1 at each of the 60 seconds plus the crash penalty).

### Response:

**First, understand the concept:** The **cumulative return** ($G_0$) is the total reward an agent accumulates over the entire duration of an episode, starting from time step $t = 0$. Because the problem specifies the *undiscounted* return, the discount factor is $\gamma = 1$, which means we simply sum up every single reward received step by step without decaying them:

$$G_0 = \sum_{t=1}^{T} R_t = R_{\text{flight time}} + R_{\text{terminal}}$$

---

### Step-by-Step Numerical Calculation

#### Episode A: Successful Delivery at $t = 145$ seconds
1. **Flight time penalty:** The drone flies for $145$ seconds, receiving $-1$ point per second:
   $$R_{\text{flight}} = 145 \times (-1) = -145$$
2. **Terminal delivery bonus:** The drone drops the package successfully on the porch:
   $$R_{\text{terminal}} = +1000$$
3. **Cumulative Return $G_0$:**
   $$G_0 = -145 + 1000$$
   $$\boxed{G_0 = +855}$$

#### Episode B: Rotor Stall and Crash at $t = 60$ seconds
1. **Flight time penalty:** The drone flies for $60$ seconds, receiving $-1$ point per second:
   $$R_{\text{flight}} = 60 \times (-1) = -60$$
2. **Terminal crash penalty:** The drone crashes into a tree:
   $$R_{\text{terminal}} = -1000$$
3. **Cumulative Return $G_0$:**
   $$G_0 = -60 + (-1000)$$
   $$\boxed{G_0 = -1060}$$

---

### Trajectory Comparison Table

| Episode | Duration | Flight Time Penalty | Terminal Event | Terminal Reward | Undiscounted Return ($G_0$) |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Episode A** | 145 s | $-145$ | Successful Delivery | $+1000$ | **$+855$** |
| **Episode B** | 60 s | $-60$ | Tree Crash | $-1000$ | **$-1060$** |

---

## Q3. [Bank Q5] Reward Shaping Pitfalls in Autonomous Driving

### Prompt:
In the Lecture 01 self-driving example, the agent receives +1 for every time step it stays in its lane and −100 when it crashes.
(a) Calculate the undiscounted total return $G_0$ for an episode in which the car stays in its lane for 84 time steps and crashes on step 85.
(b) If the task is episodic (ending when the car reaches its destination) and the agent receives +1 per time step in the lane with 0 reward upon reaching the destination, what perverse behavior will an optimal agent learn, and how must the per-step reward sign be modified?

### Response:

**First, understand the concept:** In RL, an agent does not do what you *hope* it will do; it does whatever mathematically maximizes its cumulative return. If the reward function gives points for simply existing, the agent may discover loopholes (called **reward hacking** or **perverse instantiation**) rather than achieving your actual objective.

---

### (a) Undiscounted total return $G_0$
* **Steps 1 to 84:** The car stays safely in its lane, earning $+1$ per step:
  $$\sum_{t=1}^{84} R_t = 84 \times (+1) = +84$$
* **Step 85:** The car crashes, incurring the collision penalty:
  $$R_{85} = -100$$
* **Total Return Calculation:**
  $$G_0 = 84 + (-100) = 84 - 100$$
  $$\boxed{G_0 = -16}$$

---

### (b) Perverse behavior analysis and mathematical fix

#### 1. What perverse behavior will the agent learn?
If the agent receives $+1$ for every step it remains in its lane and $0$ upon reaching its destination, **an optimal agent will deliberately refuse to reach its destination!**
* **Why?** 
  * If it reaches the destination at step $T$, the episode terminates, and it receives no further rewards ($G_0 = T$).
  * If it instead drives around the block, loops in circles, or sits idling inside its lane forever, it accumulates $+1$ at every single time step indefinitely ($G_0 \to \infty$).
  * Therefore, the destination acts as an *unwanted penalty* that cuts off its infinite stream of free points!

#### 2. How must the per-step reward sign be modified?
To make the agent reach the destination efficiently, we must **change the sign of the per-step reward from positive to negative**:
* **Assign $-1$ per time step** spent driving.
* **Assign $0$ (or a large positive bonus like $+100$)** upon successfully reaching the destination.
* **Mathematical effect:** With a per-step cost of $-1$, staying on the road for $T$ steps produces a negative return $-T$. The agent is now strictly incentivized to minimize travel time and reach the destination as fast as possible to prevent its score from decreasing.

---

### Summary Table

| Reward Setup | Per-Step Reward | Goal Reward | Learned Behavior | Evaluation |
| :--- | :---: | :---: | :--- | :--- |
| **Flawed Setup** | $+1$ | $0$ | Car drives in infinite circles inside the lane; never terminates. | **Reward Hacking** (Catastrophic) |
| **Corrected Setup** | $-1$ | $+100$ (or $0$) | Car takes the shortest, safest route to destination to avoid time penalties. | **Optimal Driving** |

---

## Q4. [Bank Q6] The Agent–Environment Boundary (Robotic Chess Arm)

### Prompt:
A physical robotic arm uses a deep reinforcement learning algorithm to play over-the-board chess. Intuitively, engineers often refer to the metal arm, servo motors, and camera as "the Agent." Explain rigorously why, in the formal RL framework, the metal arm, gears, and camera belong strictly to the Environment rather than the Agent.

### Response:

**First, understand the concept:** In common everyday language, people call the whole physical robot "the agent." But in the rigorous mathematical framework of Sutton & Barto, the **Agent** is strictly the software decision-making entity (the policy/algorithm), while the **Environment** encompasses everything else.

---

### The "100% Mathematical Certainty of Control" Criterion

According to Sutton & Barto (Chapter 3):
> *"Anything that cannot be changed arbitrarily and with 100% mathematical certainty by the decision-maker belongs to the Environment."*

Applying this formal criterion to the chess-playing robot:

1. **The Metal Arm, Gears, and Motors belong to the Environment:**
   * The software algorithm can only send electrical voltage or digital command signals (the *Action* $A_t$).
   * It cannot control with 100% physical certainty whether the servo motor stalls, a gear slips, a joint overheats, or physical friction causes the gripper to drop the chess piece.
   * Because physical mechanics obey external laws of physics, mechanical wear, and electrical fluctuations, they are external to the decision-maker and thus form part of the Environment.

2. **The Camera belongs to the Environment:**
   * The camera is a physical sensor subject to lens distortion, varying room illumination, shadow changes, and sensor noise.
   * The algorithm does not construct the visual reality; it only receives the camera's digitized readings as sensory input (the *State observation* $S_t$).
   * Therefore, the camera acts as the environmental interface reporting the state of the world.

3. **The Agent is strictly the Decision-Making Code:**
   * The Agent is purely the policy $\pi(a|s)$ and the learning update rule.
   * It takes in the processed board state $S_t$, evaluates action values, and outputs the decision $A_t$ (e.g., "move bishop from c4 to f7").

---

### The Interaction Diagram

```
+-------------------------------------------------------------+
| AGENT (Pure Decision-Making Software / Policy Network)      |
+-------------------------------------------------------------+
       |                                              ^
       | Action A_t (Command: Move to square e4)     | State S_t (Observed Board)
       v                                              | Reward R_t (+1 for Win)
+-------------------------------------------------------------+
| ENVIRONMENT                                                 |
|  - Physical Motors & Servos (Can overheat, slip, or stall)  |
|  - Metal Gripper & Joints   (Subject to physics/friction)   |
|  - Camera & Lighting        (Noisy sensory readings)        |
|  - Opponent & Chessboard    (Physical external reality)     |
+-------------------------------------------------------------+
```

---

## Q5. [Bank Q8] Discrete-Time Trajectory Indexing & Timing Convention

### Prompt:
In the standard RL loop, at discrete time step $t$, the agent observes $S_t$ and selects $A_t$, after which the environment emits $R_{t+1}$ and $S_{t+1}$.
(a) Why is the reward resulting from action $A_t$ in state $S_t$ indexed as $R_{t+1}$ rather than $R_t$?
(b) Given a 4-step episodic trajectory $S_0, A_0, R_1, S_1, A_1, R_2, S_2, A_2, R_3, S_3, A_3, R_4, S_4 (\text{Terminal})$ with rewards $R_1 = 2, R_2 = -1, R_3 = 4$, and $R_4 = 10$, compute the undiscounted returns $G_0, G_1, G_2$, and $G_3$.

### Response:

**First, understand the timing rule:** At time step $t$, the world is sitting at state $S_t$. The agent picks action $A_t$. The world takes that action, transitions, and only *after* that step finishes does the environment reveal what happened: the new state $S_{t+1}$ and the reward $R_{t+1}$.

---

### (a) Why is the reward indexed as $R_{t+1}$ instead of $R_t$?
* **Causal and temporal ordering:** At discrete time $t$, the state is $S_t$. The agent selects action $A_t$. The reward does not exist before the action is taken; it is generated by the environment **as a consequence** of action $A_t$.
* **Arrival time:** Because the transition requires a step in time, the reward arrives at the agent's sensors at the very same instant the new state $S_{t+1}$ arrives—namely, at time $t+1$.
* **Indexing consistency:** Under the Sutton & Barto convention, all quantities generated by the environment during the transition from $t$ to $t+1$ share the subscript $t+1$ ($S_{t+1}$ and $R_{t+1}$). This eliminates ambiguity in Bellman backup equations.

---

### (b) Compute the undiscounted returns $G_0, G_1, G_2$, and $G_3$

#### Formula:
For undiscounted return ($\gamma = 1$), the return from time step $t$ is the sum of all future rewards until termination:
$$G_t = \sum_{k=t+1}^{T} R_k = R_{t+1} + R_{t+2} + \dots + R_T$$

We compute these most efficiently by **backward accumulation**:
$$G_t = R_{t+1} + G_{t+1}$$

Given: $R_1 = 2,\; R_2 = -1,\; R_3 = 4,\; R_4 = 10$, with terminal state at $t = 4$ ($G_4 = 0$):

1. **Calculate $G_3$:**
   $$G_3 = R_4 = 10$$
   $$\boxed{G_3 = 10}$$

2. **Calculate $G_2$:**
   $$G_2 = R_3 + G_3 = 4 + 10 = 14$$
   $$\boxed{G_2 = 14}$$

3. **Calculate $G_1$:**
   $$G_1 = R_2 + G_2 = -1 + 14 = 13$$
   $$\boxed{G_1 = 13}$$

4. **Calculate $G_0$:**
   $$G_0 = R_1 + G_1 = 2 + 13 = 15$$
   $$\boxed{G_0 = 15}$$

---

### Step-by-Step Summary Table

| Time Step $t$ | Future Rewards Remaining | Calculation | Undiscounted Return ($G_t$) |
| :---: | :--- | :--- | :---: |
| **$t = 3$** | $R_4$ | $10$ | **$10$** |
| **$t = 2$** | $R_3 + R_4$ | $4 + 10$ | **$14$** |
| **$t = 1$** | $R_2 + R_3 + R_4$ | $-1 + 4 + 10$ | **$13$** |
| **$t = 0$** | $R_1 + R_2 + R_3 + R_4$ | $2 + (-1) + 4 + 10$ | **$15$** |



---


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
$$
R(s, a, s') = \begin{cases}
+1, & \text{if } s' = 15 \text{ (Goal reached)} \\
0, & \text{for all other transitions (including falling into Holes)}
\end{cases}
$$

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
$$
P(s' \mid s = 1, a = \text{Right}) = \begin{cases}
\frac{1}{3}, & s' = 2 \text{ (Right)} \\
\frac{1}{3}, & s' = 1 \text{ (Up: wall bounce)} \\
\frac{1}{3}, & s' = 5 \text{ (Down: Hole)} \\
0, & \text{otherwise}
\end{cases}
$$

$$\boxed{\text{Probability of falling into Hole 5} = \frac{1}{3} \approx 0.3333} \quad (33.33\%)$$

---

### (b) Action $a = \text{Up}$ at State 1

When the agent chooses $a = \text{Up}$:
1. **Intended direction (Up, prob 1/3):** Hits the top wall $\implies$ bounces back and **remains in State 1**.
2. **Perpendicular 1 (Left, prob 1/3):** Slides left to **State 0**.
3. **Perpendicular 2 (Right, prob 1/3):** Slides right to **State 2**.

#### Transition Probability Distribution:
$$
P(s' \mid s = 1, a = \text{Up}) = \begin{cases}
\frac{1}{3}, & s' = 0 \text{ (Left)} \\
\frac{1}{3}, & s' = 1 \text{ (Up: wall bounce)} \\
\frac{1}{3}, & s' = 2 \text{ (Right)} \\
0, & s' = 5 \text{ (Down: Hole)}
\end{cases}
$$

#### Why does $a = \text{Up}$ guarantee 0% chance of falling into Hole 5?
* Down (where Hole 5 sits) is the **opposite** (reverse) direction to Up ($180^\circ$ away), **not a perpendicular direction** ($90^\circ$).
* The FrozenLake slippery physics engine *only* slips perpendicular to the chosen action ($\pm 90^\circ$). It never slips backwards ($180^\circ$).
* Therefore, by aiming straight into the top wall ($a = \text{Up}$):
  * $P(\text{Hole 5} \mid 1, \text{Up}) = 0$ (0%).
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

**First, understand what a policy is:** In simple terms, a **policy** is the agent's brain or rulebook. It tells the agent: "Whenever you find yourself in state $s$, here is the action you should take."

---

### 1. Mathematical Definitions and Differences

* **Deterministic Policy** ($\pi : S \to A$):
  * A direct functional mapping from each state to a single, definite action: $a = \pi(s)$.
  * Given state $s$, there is no randomness; the agent always executes action $a$ with 100% probability.
  * *Example:* "If in State 14, always pick action Right."

* **Stochastic Policy** ($\pi(a \mid s) = \Pr(A_t = a \mid S_t = s)$):
  * A conditional probability distribution over the set of actions given state $s$: $\pi(a \mid s) \ge 0, \quad \sum_{a \in A} \pi(a \mid s) = 1 \quad \forall s \in S$.
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



---


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



---


# Section 4: Lecture 04 — Numerical Calculation of the Bellman Expectation Equation

---

## Q15. [Bank Q31] Complete Reproduction & Exact Precision Check of State 14 Backup

### Prompt:
Using the exact parameters from Lecture 04 ($V(15) = 0, V(10) = 0.40, V(13) = 0.55, V_{\text{old}}(14) = 0.70, \gamma = 0.9$, environment success probability 0.7, perpendicular slip probability 0.3 to a state of value 0.40, and policy $\pi(\text{Right} \mid 14) = 0.8, \pi(\text{Left} \mid 14) = 0.2$), compute:
(a) $Q(14, \text{Right})$ to 3 decimal places,
(b) $Q(14, \text{Left})$ both unrounded (4 decimal places) and rounded to 3 decimal places (0.455), and
(c) the updated $V_{\text{new}}(14)$ and the Bellman residual $\Delta = |V_{\text{new}}(14) - V_{\text{old}}(14)|$.

### Response:

**First, understand the workflow:** A Bellman backup at a state follows a strict 3-step sequence:
1. Compute $Q(s, a)$ for every action by summing over environmental slip branches.
2. Multiply each $Q(s, a)$ by policy probability $\pi(a \mid s)$ to get $V_{\text{new}}(s)$.
3. Compute the Bellman residual $|V_{\text{new}} - V_{\text{old}}|$ to measure convergence.

---

### (a) Compute $Q(14, \text{Right})$
* **Success branch (prob 0.7):** Reaches Goal 15 ($r = +1, V(15) = 0$).
* **Slip branch (prob 0.3):** Slips Up to State 10 ($r = 0, V(10) = 0.40$).
* Discount factor $\gamma = 0.9$.

$$Q(14, \text{Right}) = 0.7 \times [1 + 0.9(0)] + 0.3 \times [0 + 0.9(0.40)]$$
$$Q(14, \text{Right}) = 0.7 \times 1.0 + 0.3 \times 0.36$$
$$Q(14, \text{Right}) = 0.700 + 0.108$$
$$\boxed{Q(14, \text{Right}) = 0.808}$$

---

### (b) Compute $Q(14, \text{Left})$
* **Success branch (prob 0.7):** Moves Left to State 13 ($r = 0, V(13) = 0.55$).
* **Slip branch (prob 0.3):** Slips Up to State 10 ($r = 0, V(10) = 0.40$).

$$Q(14, \text{Left}) = 0.7 \times [0 + 0.9(0.55)] + 0.3 \times [0 + 0.9(0.40)]$$
$$Q(14, \text{Left}) = 0.7 \times [0.495] + 0.3 \times [0.36]$$
$$Q(14, \text{Left}) = 0.3465 + 0.1080$$

* **Unrounded (4 decimal places):**
  $$\boxed{Q(14, \text{Left}) = 0.4545}$$
* **Rounded (3 decimal places):**
  $$\boxed{Q(14, \text{Left}) \approx 0.455}$$

---

### (c) Compute updated $V_{\text{new}}(14)$ and Bellman residual $\Delta$

#### Updated State Value:
$$V_{\text{new}}(14) = \pi(\text{Right} \mid 14) \cdot Q(14, \text{Right}) + \pi(\text{Left} \mid 14) \cdot Q(14, \text{Left})$$
$$V_{\text{new}}(14) = 0.8 \times (0.808) + 0.2 \times (0.4545)$$
$$V_{\text{new}}(14) = 0.6464 + 0.0909$$
$$\boxed{V_{\text{new}}(14) = 0.7373 \approx 0.737}$$

> [!NOTE]
> **Slide Rounding Precision Note:** Lecture 04 Slide 8 plugs in the rounded 3-decimal value $Q(14, \text{Left}) = 0.455$, yielding $V_{\text{new}}(14) = 0.8(0.808) + 0.2(0.455) = 0.6464 + 0.0910 = 0.7374 \approx 0.737$. Both the unrounded exact calculation ($0.7373$) and intermediate-rounded calculation ($0.7374$) round to the identical final value of **$0.737$**.

#### Bellman Residual $\Delta$:
Given $V_{\text{old}}(14) = 0.70$:
$$\Delta = |V_{\text{new}}(14) - V_{\text{old}}(14)| = |0.7373 - 0.7000|$$
$$\boxed{\Delta = 0.0373}$$

---

### Summary of Results Table

| Quantity | Formula | Exact Value | Rounded (3 Decimals) |
| :--- | :--- | :---: | :---: |
| $Q(14, \text{Right})$ | $0.7(1) + 0.3(0.9 \times 0.40)$ | $0.8080$ | **$0.808$** |
| $Q(14, \text{Left})$ | $0.7(0.9 \times 0.55) + 0.3(0.9 \times 0.40)$ | $0.4545$ | **$0.455$** |
| $V_{\text{new}}(14)$ | $0.8(0.808) + 0.2(0.4545)$ | $0.7373$ | **$0.737$** |
| Bellman Residual $\Delta$ | $|0.7373 - 0.70|$ | $0.0373$ | **$0.037$** |

---

## Q16. [Bank Q33] Diagnosing the "Swapped Probability" Student Error

### Prompt:
Lecture 04 Slide 4 emphasizes never confusing $\pi(a \mid s) = (0.8, 0.2)$ with $P(s' \mid s, a) = (0.7, 0.3)$. Suppose a student accidentally swaps them, using 0.8/0.2 as the environment success/slip probabilities and 0.7/0.3 as the policy probabilities for Right/Left. Calculate the resulting erroneous $Q_{\text{wrong}}(14, \text{Right})$, $Q_{\text{wrong}}(14, \text{Left})$, and $V_{\text{wrong}}(14)$, and quantify the numerical error introduced.

### Response:

**First, understand the classic student trap:** 
* $\pi(a \mid s)$ belongs to the **Agent** (how often it chooses actions).
* $P(s' \mid s, a)$ belongs to the **Environment** (how often the ice slips).
Mixing them up completely distorts the math.

---

### 1. Compute Erroneous $Q_{\text{wrong}}$ using $P_{\text{wrong}} = (0.8, 0.2)$

#### Erroneous $Q_{\text{wrong}}(14, \text{Right})$:
$$Q_{\text{wrong}}(14, \text{Right}) = 0.8 \times [1 + 0] + 0.2 \times [0 + 0.9(0.40)]$$
$$Q_{\text{wrong}}(14, \text{Right}) = 0.8 + 0.2 \times 0.36 = 0.8 + 0.072$$
$$\boxed{Q_{\text{wrong}}(14, \text{Right}) = 0.8720} \quad (\text{Correct was } 0.8080)$$

#### Erroneous $Q_{\text{wrong}}(14, \text{Left})$:
$$Q_{\text{wrong}}(14, \text{Left}) = 0.8 \times [0 + 0.9(0.55)] + 0.2 \times [0 + 0.9(0.40)]$$
$$Q_{\text{wrong}}(14, \text{Left}) = 0.8 \times 0.495 + 0.2 \times 0.36 = 0.396 + 0.072$$
$$\boxed{Q_{\text{wrong}}(14, \text{Left}) = 0.4680} \quad (\text{Correct was } 0.4545)$$

---

### 2. Compute Erroneous $V_{\text{wrong}}(14)$ using $\pi_{\text{wrong}} = (0.7, 0.3)$

$$V_{\text{wrong}}(14) = 0.7 \times Q_{\text{wrong}}(14, \text{Right}) + 0.3 \times Q_{\text{wrong}}(14, \text{Left})$$
$$V_{\text{wrong}}(14) = 0.7 \times (0.8720) + 0.3 \times (0.4680)$$
$$V_{\text{wrong}}(14) = 0.6104 + 0.1404$$
$$\boxed{V_{\text{wrong}}(14) = 0.7508} \quad (\text{Correct was } 0.7373)$$

---

### 3. Quantify Numerical Error Introduced

$$\text{Error in } Q(\text{Right}) = 0.8720 - 0.8080 = +0.0640$$ (+7.9%)
$$\text{Error in } Q(\text{Left}) = 0.4680 - 0.4545 = +0.0135$$ (+3.0%)
$$\text{Error in } V(14) = 0.7508 - 0.7373 = \mathbf{+0.0135}$$

---

### Error Diagnostic Table

| Quantity | Correct Value | Student's Swapped Value | Exact Numerical Error |
| :--- | :---: | :---: | :---: |
| $Q(14, \text{Right})$ | $0.8080$ | $0.8720$ | **$+0.0640$** |
| $Q(14, \text{Left})$ | $0.4545$ | $0.4680$ | **$+0.0135$** |
| $V(14)$ | $0.7373$ | $0.7508$ | **$+0.0135$** |

---

## Q17. [Bank Q35] Full Numerical Bellman Backup at State 13

### Prompt:
Apply the 4-step template from Lecture 04 Slide 11 to State 13 (located immediately left of State 14, right of Hole 12, and below State 9). Assume current estimates $V(14) = 0.70, V(9) = 0.30, V(12) = 0$ (Hole), and $\gamma = 0.9$. At State 13:
* Action Right succeeds to State 14 with probability 0.7 ($r = 0$) and slips Up to State 9 with probability 0.3 ($r = 0$).
* Action Up succeeds to State 9 with probability 0.7 ($r = 0$), slips Right to State 14 with probability 0.15 ($r = 0$), and slips Left into Hole 12 with probability 0.15 ($r = 0$).
Given policy $\pi(\text{Right} \mid 13) = 0.9$ and $\pi(\text{Up} \mid 13) = 0.1$, compute $Q(13, \text{Right}), Q(13, \text{Up})$, and $V_{\text{new}}(13)$.

### Response:

**First, understand the geography of State 13:**
* Right leads toward safe State 14 ($V=0.70$).
* Up leads toward State 9 ($V=0.30$).
* Left leads into deadly Hole 12 ($V=0$).

---

### Step 1: Compute $Q(13, \text{Right})$
* 70% chance of reaching State 14 ($r = 0, V(14) = 0.70$).
* 30% chance of slipping Up to State 9 ($r = 0, V(9) = 0.30$).

$$Q(13, \text{Right}) = 0.7 \times [0 + 0.9(0.70)] + 0.3 \times [0 + 0.9(0.30)]$$
$$Q(13, \text{Right}) = 0.7 \times [0.63] + 0.3 \times [0.27]$$
$$Q(13, \text{Right}) = 0.4410 + 0.0810$$
$$\boxed{Q(13, \text{Right}) = 0.5220}$$

---

### Step 2: Compute $Q(13, \text{Up})$
* 70% chance of reaching State 9 ($r = 0, V(9) = 0.30$).
* 15% chance of slipping Right to State 14 ($r = 0, V(14) = 0.70$).
* 15% chance of slipping Left into Hole 12 ($r = 0, V(12) = 0$).

$$Q(13, \text{Up}) = 0.7 \times [0 + 0.9(0.30)] + 0.15 \times [0 + 0.9(0.70)] + 0.15 \times [0 + 0.9(0)]$$
$$Q(13, \text{Up}) = 0.7 \times 0.27 + 0.15 \times 0.63 + 0$$
$$Q(13, \text{Up}) = 0.1890 + 0.0945 + 0$$
$$\boxed{Q(13, \text{Up}) = 0.2835}$$

---

### Step 3: Compute updated $V_{\text{new}}(13)$ using Policy $\pi = (0.9, 0.1)$

$$V_{\text{new}}(13) = \pi(\text{Right} \mid 13) \cdot Q(13, \text{Right}) + \pi(\text{Up} \mid 13) \cdot Q(13, \text{Up})$$
$$V_{\text{new}}(13) = 0.9 \times (0.5220) + 0.1 \times (0.2835)$$
$$V_{\text{new}}(13) = 0.4698 + 0.02835$$
$$\boxed{V_{\text{new}}(13) = 0.49815 \approx 0.498}$$

---

### Step-by-Step Summary Table

| Calculation Step | Mathematical Operation | Numerical Result |
| :--- | :--- | :---: |
| **$Q(13, \text{Right})$** | $0.7(0.9 \times 0.70) + 0.3(0.9 \times 0.30)$ | **$0.5220$** |
| **$Q(13, \text{Up})$** | $0.7(0.9 \times 0.30) + 0.15(0.9 \times 0.70) + 0.15(0)$ | **$0.2835$** |
| **$V_{\text{new}}(13)$** | $0.9(0.5220) + 0.1(0.2835)$ | **$0.49815 \approx 0.498$** |

---

## Q18. [Bank Q37] Why $V_{\text{old}}(14) = 0.70$ Does Not Appear in Synchronous Slide 6–8 Math

### Prompt:
On Slide 3 of Lecture 04, the setup lists $V(14) = 0.70$ (old estimate), yet 0.70 is never multiplied anywhere in Steps 2, 3, or 4 on Slides 6–8. Explain why $V_{\text{old}}(14)$ was not used in that specific calculation, and under what boundary-slip condition $V_{\text{old}}(14)$ would appear on the right-hand side of the update.

### Response:

**First, understand how Bellman updates work:** When updating the value of state $s$, the Bellman equation looks forward into the **successor states $s'$** where the agent lands next. It does not look at the current state $s$ unless the agent can transition back into $s$ itself!

---

### 1. Why was $V_{\text{old}}(14) = 0.70$ not used?
In the Bellman expectation equation:
$$V_{\text{new}}(14) = \sum_a \pi(a \mid 14) \sum_{s'} P(s' \mid 14, a)[r + \gamma V_{\text{old}}(s')]$$
Notice that the old state estimates appear exclusively as **$V_{\text{old}}(s')$**—the values of the **landing states**.

In the Lecture 04 calculation for State 14:
* Action Right transitions to **Goal 15** or slips to **State 10**.
* Action Left transitions to **State 13** or slips to **State 10**.

Notice that the set of possible successor states is:
$$s' \in \{15, 10, 13\}$$
Because $s'$ is **never equal to 14** in any of these transitions, $V_{\text{old}}(14)$ never appears on the right-hand side. $V_{\text{old}}(14) = 0.70$ is only used at the very end to compute the residual:
$$\Delta = |V_{\text{new}}(14) - V_{\text{old}}(14)|$$

---

### 2. Under what boundary-slip condition WOULD $V_{\text{old}}(14)$ appear on the RHS?
$V_{\text{old}}(14)$ will appear on the right-hand side **if and only if there is a non-zero probability of transitioning back into State 14 ($s' = 14$)**.

This occurs under **boundary wall reflection**:
* State 14 is located in the bottom row of the grid. Directly below State 14 is the **bottom outer wall**.
* If the agent takes action **Down**, it hits the bottom wall and bounces back into State 14 ($s' = 14$).
* If the agent takes action **Right** or **Left** and the environment physics includes a perpendicular slip **Down**, that slip hits the bottom wall, keeping the agent in State 14!
* Whenever $s' = 14$, the Bellman equation must evaluate:
  $$P(s'=14 \mid 14, a)[r + \gamma V_{\text{old}}(14)]$$
* In that scenario, $V_{\text{old}}(14) = 0.70$ would be multiplied by $\gamma = 0.9$ and the wall-bounce probability.



---


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
(c) Evaluate this new deterministic policy $\pi'$ to find $V^*(S_0), V^*(S_1), V^*(S_2), V^*(S_3)$ and verify that Policy Iteration terminates on the next improvement step (`policy_stable = true`).

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

### (c) Evaluate the new deterministic policy $\pi^*$ and verify termination

Under the new policy $\pi'$:
* From $S_1$: Takes Down $\to S_3$ (Goal):
  $$V^*(S_1) = 1 + \gamma V^*(S_3) = 1 + 0 = \mathbf{1.0}$$
* From $S_2$: Takes Right $\to S_3$ (Goal):
  $$V^*(S_2) = 1 + \gamma V^*(S_3) = 1 + 0 = \mathbf{1.0}$$
* From $S_0$: Takes Right $\to S_1$:
  $$V^*(S_0) = 0 + \gamma V^*(S_1) = 0.9(1.0) = \mathbf{0.9}$$
* From $S_3$: Terminal Goal:
  $$V^*(S_3) = \mathbf{0.0}$$

#### Verify Policy Stability on the next iteration:
Recompute greedy actions under $V^* = [0.9, 1.0, 1.0, 0]$:
* At $S_1$: $q(S_1, \text{Down}) = 1.0 > q(S_1, \text{Up/Right}) = 0.9 \implies$ **Down wins (No change)**.
* At $S_2$: $q(S_2, \text{Right}) = 1.0 > q(S_2, \text{Down/Left}) = 0.9 \implies$ **Right wins (No change)**.
* At $S_0$: $q(S_0, \text{Right}) = 0.9(1.0) = 0.9 \implies$ **Right wins (No change)**.

Because the policy does not change at any state:
$$\boxed{\text{policy\_stable = True}}$$
Policy Iteration terminates successfully having found the provably optimal policy $\pi^*$.



---


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



---


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



---


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



---


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
* **Transitions along the chain** ($S_i \to S_{i+1}$):
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
* Therefore, in a **single episode** ($N = 1$) that reaches the Goal, Monte Carlo immediately updates **every single state along the trajectory** ($S_1, S_2, \dots, S_N$) **simultaneously** with positive non-zero returns:
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



---


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
| **Memory Requirement** | $\mathcal{O}(|S| \cdot |A|)$ (Explodes to gigabytes/terabytes). | Fixed neural weights $\mathcal{O}(|\theta|)$ (Few megabytes). |
| **Continuous Inputs** | Requires fragile, lossy discretization. | Directly ingests continuous vectors $\mathbf{s} \in \mathbb{R}^d$. |
| **Generalization** | **Zero:** Each table entry is isolated. | **High:** Similar inputs share neural activations. |

---

## Q43. [Bank Q92] CartPole-v1 DQN Architecture & Exact Parameter Count

### Prompt:
For CartPole-v1 (4 continuous state features, 2 discrete actions), the architecture is:
$$\text{Input } \mathbb{R}^4 \to \text{Dense}(64) + \text{ReLU} \to \text{Dense}(64) + \text{ReLU} \to \mathbb{R}^2$$
(a) Calculate the exact number of trainable parameters (weights and biases) in each of the three linear layers and the total parameter count $|\theta|$ of the network.
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

#### Total Trainable Parameters $|\theta|$:
$$|\theta| = \text{Params}_1 + \text{Params}_2 + \text{Params}_3$$
$$|\theta| = 320 + 4160 + 130$$
$$\boxed{|\theta| = 4610 \text{ trainable parameters}}$$

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
$$
y = \begin{cases}
r, & \text{if terminated = True (Crashed)} \\
r + \gamma \max_{a'} Q(s', a'), & \text{if truncated = True (Healthy, clock ran out)}
\end{cases}
$$

---

### Summary Table

| Flag | Meaning | Future Potential | Should Bootstrap Term be Zeroed Out? |
| :--- | :--- | :---: | :---: |
| **`terminated = True`** | Cart crashed / pole fell. | Exactly $0$ | **YES: $(1 - 1) = 0$** |
| **`truncated = True`** | Hit 500-step clock timeout. | High ($V(s') \approx 10.0$) | **NO: Keep bootstrap $\gamma Q(s', a')$!** |



---


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
  * The unique Nash Equilibrium is a stochastic mixed strategy: $\pi(\text{Rock}) = \frac{1}{3}, \; \pi(\text{Paper}) = \frac{1}{3}, \; \pi(\text{Scissors}) = \frac{1}{3}$.
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



---
