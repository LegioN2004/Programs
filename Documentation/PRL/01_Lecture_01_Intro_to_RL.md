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
