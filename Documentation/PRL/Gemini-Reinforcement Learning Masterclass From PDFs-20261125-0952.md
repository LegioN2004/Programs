# Reinforcement Learning Masterclass (From Lecture PDFs)

> **Source Notes:** `lecture2.2_MC_Model_Free_Control.pdf`, `lec3_TD.pdf`, `lec3_TD_example.pdf`, `lec3_TD_note.pdf`, `DQN_UG_Class_Notes.pdf`, and `DQNSlides.pdf`  
> **Style:** Easy-to-understand explanations, intuitive analogies, and step-by-step worked numerical examples.

---

## Table of Contents

1. [Monte Carlo Methods for Model-Free Control](#1-monte-carlo-methods-for-model-free-control)
2. [Temporal Difference (TD) Learning, SARSA & Q-Learning](#2-temporal-difference-td-learning-sarsa--q-learning)
3. [TD Step-by-Step Walkthrough & Study Notes](#3-td-step-by-step-walkthrough--study-notes)
4. [Deep Q-Networks (DQN)](#4-deep-q-networks-dqn)
5. [Markov Decision Processes (MDP) — Exam Q&A](#5-markov-decision-processes-mdp--exam-qa)

---

# 1. Monte Carlo Methods for Model-Free Control

*Source: `lecture2.2_MC_Model_Free_Control.pdf`*

## 1.1 Monte Carlo Policy Evaluation (Learning Without a Rulebook)

In Dynamic Programming (DP), the agent needs the complete rulebook of the environment—the exact transition probabilities $p(s', r \mid s, a)$. When you **don't** know those probabilities (the **model-free** setting), you cannot calculate expectations mathematically ahead of time.

Instead, **Monte Carlo (MC)** learns purely from experience:

* The agent plays complete games (episodic tasks) from start to finish, generating a trajectory: $S_0, A_0, R_1, S_1, A_1, R_2, \dots, S_T$.
* For each step $t$, it calculates the total discounted reward from that moment until the end of the episode, called the **return**:

$$G_t = \sum_{k=0}^{T-t-1} \gamma^k R_{t+k+1}$$

* It averages those observed returns across episodes to estimate the state value:

$$v_\pi(s) \doteq \mathbb{E}_\pi[G_t \mid S_t = s]$$

---

## 1.2 First-Visit vs. Every-Visit MC

Sometimes an agent loops around and visits the same state (like $S_1$) more than once in a single episode. There are two ways to handle repeated visits:

| Method | How It Works | Key Statistical Properties |
| :--- | :--- | :--- |
| **First-Visit MC** | Averages the return **only from the very first time** state $s$ is visited in each episode. | **Unbiased** ($\mathbb{E}[\hat{V}(s)] = v_\pi(s)$); variance drops at $\mathcal{O}(1/\sqrt{N})$. |
| **Every-Visit MC** | Averages the returns from **every single visit** to state $s$ in each episode. | Slightly **biased** on small sample sizes (because later visits are correlated suffixes of the same path), but becomes unbiased with enough episodes and often has lower Mean Squared Error (MSE). |

### Simple Numerical Example ($\gamma = 1.0$)

Suppose one episode follows this path:

$$S_1 \xrightarrow{+2} S_2 \xrightarrow{+1} S_1 \xrightarrow{+4} S_3 \xrightarrow{+10} T$$

1. **Calculate returns backwards from the end:**
   * $G_3 = 10$ (at $S_3$)
   * $G_2 = 4 + 10 = \mathbf{14}$ (2nd visit to $S_1$)
   * $G_1 = 1 + 14 = 15$ (at $S_2$)
   * $G_0 = 2 + 15 = \mathbf{17}$ (1st visit to $S_1$)
2. **Estimate $V(S_1)$:**
   * **First-Visit MC:** Uses only the 1st visit $\implies \hat{V}(S_1) = G_0 = \mathbf{17.0}$.
   * **Every-Visit MC:** Averages both visits $\implies \hat{V}(S_1) = \frac{17 + 14}{2} = \mathbf{15.5}$.

---

## 1.3 Why $V(s)$ Is Not Enough (The Control Bottleneck)

In DP, once you know the state values $V(s)$, you improve your policy by looking one step ahead using the environment model $p(s', r \mid s, a)$:

$$\pi'(s) \leftarrow \arg\max_{a \in \mathcal{A}} \sum_{s', r} p(s', r \mid s, a)\big[r + \gamma V(s')\big]$$

**Why this breaks in Model-Free RL:**

* Think of states as rooms and actions as unlabeled doors. Knowing how much treasure is inside every neighboring room ($V(s')$) is completely useless if you don't know which door (action $a$) leads to which room ($s'$).
* Without $p(s', r \mid s, a)$, a model-free agent cannot use $V(s)$ to pick the best action.

**The Solution — Estimate $Q(s, a)$ Instead:**

* Shift from scoring states to scoring **state-action pairs**:

$$q_\pi(s, a) \doteq \mathbb{E}_\pi[G_t \mid S_t = s, A_t = a]$$

* Now you don't need any environment model to improve your policy—just look at the row for your current state and pick the action with the highest number:

$$\pi'(s) \leftarrow \arg\max_{a \in \mathcal{A}} Q(s, a)$$

---

## 1.4 The Exploration Dilemma & $\epsilon$-Greedy

Imagine a simple **1D Chain World** (`Wall — A — B — C — Goal`) with actions `{Left, Right}`, $\gamma = 0.9$, and a $+1.0$ reward at the Goal.

If your agent follows a strict deterministic policy of always going **Right**:

* It learns scores for `(A, Right)`, `(B, Right)`, and `(C, Right)` (and maybe `(C, Left)` if it accidentally slips).
* It **never** tries `(A, Left)` or `(B, Left)`, leaving those entries blank forever.
* Without trying the alternative actions, the agent can never prove whether Right is truly better than Left.

To make sure every action gets tested, there are two main approaches:

### Option A: Exploring Starts (MC-ES)

* Force every single state-action pair $(S_0, A_0)$ to have a non-zero chance of being the starting point of an episode, then follow the greedy policy afterward.
* *Catch:* It keeps the policy purely greedy ($\arg\max$), but you almost never have the power to teleport a real-world robot or user into arbitrary starting states.

### Option B: $\epsilon$-Greedy (The Practical On-Policy Fix)

* At every step, toss a biased coin with probability $\epsilon \in (0, 1]$:
  * With probability **$1 - \epsilon$ (Exploit):** Pick the best known action $\arg\max_a Q(S_t, a)$.
  * With probability **$\epsilon$ (Explore):** Pick any of the $n$ available actions uniformly at random.
* Because the random roll can also accidentally pick the best action, the exact probabilities for $n$ actions are:

$$\pi(a \mid s) = \begin{cases} 1 - \epsilon + \dfrac{\epsilon}{n} & \text{for the greedy action } a^\ast \\ \dfrac{\epsilon}{n} & \text{for every other action} \end{cases}$$

* This works from any normal starting state and converges to the best $\epsilon$-soft policy.

### The Explore–Exploit Tradeoff

* **$\epsilon = 0$ (Purely Greedy):** Climbs fast at the beginning, then gets permanently stuck at a lower score because it never tries unvisited branches.
* **$\epsilon = 0.5$ (Over-Exploring):** Tests everything, but keeps making random bad moves so its average score stays low.
* **$\epsilon = 0.1$ (The Sweet Spot):** Learns a bit slower than greedy at first, but discovers the best actions and finishes with a much higher long-run return.

---

## 1.5 Generalized Policy Iteration (GPI) with Monte Carlo

You don't need to wait thousands of episodes for your $Q$-table to become 100% accurate before updating your strategy. MC Control uses **episode-by-episode GPI**:

1. Play **one** complete episode using your current policy $\pi_k$.
2. **Evaluate:** Compute the returns $G_t$ for the visited $(S_t, A_t)$ pairs and update $Q$.
3. **Improve:** Immediately update your policy to $\pi_{k+1}$ using $\arg\max_a Q(s, a)$ (for Exploring Starts) or $\epsilon$-greedy probabilities.
4. Repeat until you reach $\pi^\ast$.

---

## 1.6 Exploring Starts Walkthrough (1D Chain World)

**Setup:** $\gamma = 0.9$, Goal $= +1.0$, all other rewards $= 0$, all $Q(s, a)$ start at $0$, and the default policy is $\pi_0(s) = \text{Right}$ for $A, B, C$.

1. **Episode 1 — Start at `(B, Right)`:**
   * Path: $B \xrightarrow{R} C \xrightarrow{R} \text{Goal}$.
   * Updates: $Q(C, R) = 1.000$ and $Q(B, R) = 0.9 \times 1 = 0.900$.
   * Improvement: Right beats $0$ at both $C$ and $B$, so the policy stays Right.
2. **Episode 2 — Start at `(B, Left)`:**
   * Path: $B \xrightarrow{L} A \xrightarrow{R} B \xrightarrow{R} C \xrightarrow{R} \text{Goal}$.
   * Going Left adds a 2-step detour before the goal. New first-visit updates: $Q(A, R) = 0.9^2 = 0.810$ and $Q(B, L) = 0.9^3 = 0.729$.
   * Improvement: At $B$, Right ($0.900$) beats Left ($0.729$), so Left is rejected; at $A$, Right ($0.810$) beats $0$.
3. **Episode 3 — Start at `(A, Left)`:**
   * Path: $A \xrightarrow{L} A \text{ (hits wall)} \xrightarrow{R} B \xrightarrow{R} C \xrightarrow{R} \text{Goal}$.
   * Bouncing off the wall wastes 1 step, giving $Q(A, L) = 0.9^3 = 0.729$.
   * Improvement: At $A$, Right ($0.810$) beats Left ($0.729$), so the policy stays Right.

After these 3 episodes, 5 out of the 6 entries in the $Q$-table are filled and greedy improvement consistently selects **Right**—only `(C, Left)` remains unvisited, waiting for a future exploring start.

---

# 2. Temporal Difference (TD) Learning, SARSA & Q-Learning

*Source: `lec3_TD.pdf`*

## 2.1 From Monte Carlo to Temporal Difference (TD) Learning

In Monte Carlo (MC) learning, the agent has to wait until the entire episode finishes before it can calculate the full return $G_t$ and update its value table. Temporal Difference (TD) learning asks a simple question: *Why wait for the game to end when you can learn after every single step?*

When the agent takes just **one step** ($S_t \to R_{t+1} \to S_{t+1}$), TD builds a quick one-step guess of the return using the reward it just received plus its current estimate of the next state:

$$\text{TD Target} = R_{t+1} + \gamma V(S_{t+1})$$

This gives us the **TD(0) Update Rule**:

$$V(S_t) \leftarrow V(S_t) + \alpha \Big[\underbrace{R_{t+1} + \gamma V(S_{t+1})}_{\text{TD Target}} - V(S_t)\Big]$$

Think of it using one universal pattern: **New estimate = Old estimate + $\alpha \times (\text{Target} - \text{Old estimate})$**.

* **TD Error ($\delta_t$):** The difference between the new target and your old guess: $\delta_t = R_{t+1} + \gamma V(S_{t+1}) - V(S_t)$.
* **Bootstrapping:** Updating your current guess $V(S_t)$ using another guess $V(S_{t+1})$ instead of waiting for the true final outcome.

### Quick Numerical Example

Suppose $V(S_t) = 5$, $R_{t+1} = 2$, $V(S_{t+1}) = 8$, $\alpha = 0.1$, and $\gamma = 0.9$:

1. **TD Target:** $2 + (0.9)(8) = 9.2$
2. **TD Error:** $9.2 - 5 = 4.2$
3. **Update:** $V(S_t) = 5 + (0.1)(4.2) = \mathbf{5.42}$

| Feature | Monte Carlo (MC) | Temporal Difference (TD) |
| :--- | :--- | :--- |
| **When it updates** | End of the episode | After every single step (online) |
| **Target used** | Actual complete return $G_t$ | Reward + estimated future value: $R + \gamma V(S')$ |
| **Bootstraps?** | No | Yes |

---

## 2.2 Behaviour Policy ($\mu$) vs. Target Policy ($\pi$)

Just like in Monte Carlo, state values $V(S)$ aren't enough to choose actions—for control, we need action-values **$Q(S, A)$**. When learning $Q(S, A)$, there are two separate questions behind every algorithm:

1. **Behaviour Policy ($\mu$):** *How does the agent actually act?* This is the policy that chooses real moves and generates experience (often $\epsilon$-greedy so it can explore).
2. **Target Policy ($\pi$):** *What policy is the agent trying to learn about?* This is the strategy whose value we are evaluating or improving.

### The Driving Instructor Analogy

Imagine a student driver learning to drive. The student drives cautiously and occasionally tries exploratory moves—that is the **behaviour policy $\mu$**. Meanwhile, the driving instructor sitting next to them evaluates what the best-known driving strategy would do—that is the **target policy $\pi$**.

This creates two categories of learning:

* **On-Policy ($\mu = \pi$):** You learn about the exact same policy you are currently following (*"I learn about the way I am actually behaving"*). Example: **SARSA**.
* **Off-Policy ($\mu \neq \pi$):** You behave using one policy (e.g., exploring with $\epsilon$-greedy) while learning about a different policy (e.g., a purely greedy policy). Example: **Q-Learning**. *(Note: Off-policy does NOT mean following a bad policy—it just means exploring while learning the optimal strategy.)*

---

## 2.3 SARSA (On-Policy TD Control)

**SARSA** gets its name from the 5-step sequence it needs before it can make an update: **$(S_t, A_t, R_{t+1}, S_{t+1}, A_{t+1})$**.

$$Q(S_t, A_t) \leftarrow Q(S_t, A_t) + \alpha \big[R_{t+1} + \gamma Q(S_{t+1}, A_{t+1}) - Q(S_t, A_t)\big]$$

* **Memory Aid:** *"What action will I **actually** take next?"*
* **How it works:** After moving from $S$ to $S'$, SARSA cannot update $Q(S, A)$ right away. It first has to look at $S'$ and pick its actual next action $A'$ using its $\epsilon$-greedy policy.
* **Why SARSA is conservative:** Because SARSA uses the action $A'$ that it *actually* picks, if its $\epsilon$-greedy policy rolls a random exploratory mistake (like stepping into a low-value tile or near a cliff), SARSA directly includes that bad outcome in its update. It mathematically absorbs the risk of its own exploration.

---

## 2.4 Q-Learning (Off-Policy TD Control)

**Q-Learning** doesn't care what exploratory move the agent actually takes next—it always looks at the **highest possible Q-value** available at the next state.

$$Q(S_t, A_t) \leftarrow Q(S_t, A_t) + \alpha \big[R_{t+1} + \gamma \max_{a} Q(S_{t+1}, a) - Q(S_t, A_t)\big]$$

* **Memory Aid:** *"What is the **best** action I **could** take next?"*
* **How it works:** The agent still acts using an $\epsilon$-greedy behaviour policy ($\mu$) to explore the map, but its update equation always assumes it will act greedily ($\pi$) from the next state onward via $\max_a Q(S', a)$.
* **Common Question:** *If the $\epsilon$-greedy behaviour policy changes as $Q$ updates, is it still off-policy Q-Learning?* **Yes!** Both algorithms update their behaviour policy over time; what makes it Q-Learning is that the learning target uses $\max_a Q(S', a)$ rather than the sampled next action.

---

## 2.5 SARSA vs. Q-Learning Side-by-Side

| Property | SARSA | Q-Learning |
| :--- | :--- | :--- |
| **Policy Type** | On-policy ($\mu = \pi$) | Off-policy ($\mu \neq \pi$) |
| **TD Target** | $R + \gamma Q(S', A')$ | $R + \gamma \max_a Q(S', a)$ |
| **Next Action Used** | Actual selected action | Best (greedy) action value |
| **Exploration Effect** | Directly enters the target | Only affects which states are visited |
| **Intuition** | Conservative / policy-aware | Optimistic about future moves |

### Same Transition, Different Updates (Worked Example)

Suppose $Q(S_t, A_t) = 4$, reward $R_{t+1} = 2$, $\alpha = 0.5$, $\gamma = 0.9$, and at the next state $S'$ we have $Q(S', A_1) = 6$ and $Q(S', A_2) = 10$. Because of exploration, the agent **actually chooses $A_1$**.

**SARSA (uses actual choice $A_1 \to 6$):**

$$\text{Target} = 2 + (0.9)(6) = 7.4 \implies Q_{\text{new}} = 4 + 0.5(7.4 - 4) = \mathbf{5.7}$$

**Q-Learning (uses $\max(6, 10) = 10$):**

$$\text{Target} = 2 + (0.9)(10) = 11.0 \implies Q_{\text{new}} = 4 + 0.5(11.0 - 4) = \mathbf{7.5}$$

*(Note: Both give the exact same number whenever the agent happens to pick the greedy action.)*

### Cliff-Walking Intuition

Imagine walking from Start ($S$) to Goal ($G$) with a deadly cliff right next to the shortest path:

* **SARSA** knows it might randomly slip off the cliff while exploring, so it learns a **safer route** further away from the edge.
* **Q-Learning** assumes perfect greedy play in the future ($\max_a$), so it learns the **shortest, riskier path** right along the cliff edge.

---

## 2.6 Special Rules & Top Exam Traps to Avoid

* **Terminal States:** When the next state $S'$ is a terminal state (like a Goal or Hole), there are no future rewards, so $Q(S_{\text{terminal}}, a) = 0$. The target simplifies to just **$R_{t+1}$**: $Q(S, A) \leftarrow Q(S, A) + \alpha [R - Q(S, A)]$.
* **Learning Rate ($\alpha$):** Controls how aggressively you overwrite old knowledge—if $\alpha = 0.1$, you nudge the old value slightly; if $\alpha = 1.0$, you completely replace the old value with the new target.
* **Discount Factor ($\gamma$):** If $\gamma = 0$, the agent ignores the future completely and only cares about immediate reward ($\text{Target} = R$).
* **3 Classic Mistakes to Watch Out For:**
  1. Accidentally using $\max_a Q(S', a)$ in SARSA instead of $Q(S', A')$.
  2. Accidentally using the actual next action $Q(S', A')$ in Q-Learning instead of $\max_a Q(S', a)$.
  3. Forgetting to subtract the old $Q(S, A)$ inside the brackets ($Q \leftarrow Q + \alpha[\text{Target} - Q]$).

---

# 3. TD Step-by-Step Walkthrough & Study Notes

*Sources: `lec3_TD_example.pdf` and `lec3_TD_note.pdf`*

## 3.1 Tracing SARSA vs. Q-Learning Step by Step (`lec3_TD_example.pdf`)

This example walks through a tiny 3-room hallway (`A → B → C → Goal`) to show how **SARSA** and **Q-Learning** update their numbers and policies episode by episode.

### The Setup

* **Parameters:** Learning rate $\alpha = 0.5$, discount factor $\gamma = 0.9$, exploration rate $\epsilon = 0.2$.
* **Starting State:** Before training starts, every $Q$-value is `0.0`.
* **Policy Rules:**
  * **Tie Rule:** If Left and Right have the same $Q$-value (like `0.0` vs. `0.0`), flip a coin: **50% Left / 50% Right**.
  * **Greedy Split Rule ($\epsilon = 0.2$):** As soon as one action has a higher $Q$-value, the $\epsilon$-greedy behavior policy snaps to **90% Greedy / 10% Explore**.
* **Trace Assumption:** To keep the math easy to follow, the slides assume the agent happens to roll **Right** at every single step.

### How the Reward Travels Backward (Episodes 1 to 3)

Because TD learning only looks **one step ahead**, the $+1$ reward at the Goal can only travel backward **one room per episode**:

* **Episode 1 (Only C Learns):**
  * At **A** and **B**, moving Right gives reward $0$ and lands in a room whose values are still $0.0$, so $Q(A, R)$ and $Q(B, R)$ stay at **`0.0`**.
  * At **C**, moving Right hits the Goal ($R = 1$, terminal), so $Q(C, R)$ jumps to $0 + 0.5[1 + 0 - 0] = \mathbf{0.5}$.
  * **Instant Shift:** State C immediately snaps from 50/50 to **90% Right / 10% Left**.
* **Episode 2 (B Learns from C):**
  * **A** still sees `0.0` at B, so $Q(A, R)$ stays **`0.0`**.
  * **B** moves to C and now sees C's `0.5` value, so $Q(B, R)$ updates to $0 + 0.5[0 + 0.9(0.5) - 0] = \mathbf{0.225}$. State B snaps to **90% Right / 10% Left**.
  * **C** hits the Goal again and climbs to $0.5 + 0.5[1 - 0.5] = \mathbf{0.75}$.
* **Episode 3 (A Finally Learns from B):**
  * **A** moves to B and finally sees B's `0.225` value, updating $Q(A, R)$ to $0 + 0.5[0 + 0.9(0.225) - 0] = \mathbf{0.10125}$. State A snaps to **90% Right / 10% Left**.
  * **B** climbs to **`0.45`**, and **C** climbs to **`0.875`**.

| State | Initial | End of Ep 1 | End of Ep 2 | End of Ep 3 |
| :---: | :---: | :---: | :---: | :---: |
| **$Q(A, \text{Right})$** | $0.0$ | $0.0$ | $0.0$ | **$0.10125$** |
| **$Q(B, \text{Right})$** | $0.0$ | $0.0$ | **$0.225$** | **$0.45$** |
| **$Q(C, \text{Right})$** | $0.0$ | **$0.5$** | **$0.75$** | **$0.875$** |

### The Crucial Difference Between SARSA and Q-Learning Here

* **SARSA** has only **one policy** (the 90/10 behavior policy). Before updating State B, it *must* look at State C and roll the dice to see what action it will actually take next.
* **Q-Learning** separates **two policies**:
  * **Behavior Policy (for moving):** $\epsilon$-greedy (**90% Right / 10% Left**).
  * **Target Policy (for the math):** Strictly greedy (**100% Right / 0% Left**) via $\max_a Q(S', a)$.
* **Why did both produce the exact same numbers in Episodes 1–3?** Only because we assumed the agent rolled the 90% greedy Right move every single time. If the agent had rolled the **10% exploratory Left blunder**, SARSA would have used that bad move in its math and dragged the values down, whereas Q-Learning's Target Policy would completely ignore the blunder and still use $\max$.

### Formula Breakdown: How $B \to 0.45$, $C \to 0.875$, and Gradual Updates Happen

Every update uses the same TD formula with fixed parameters **$\alpha = 0.5$** (learning rate) and **$\gamma = 0.9$** (discount factor):

$$Q_{\text{new}} = \underbrace{Q_{\text{old}}}_{\text{current value}} + \underbrace{\alpha}_{0.5} \Big[ \underbrace{R}_{\text{immediate reward}} + \underbrace{\gamma}_{0.9} \cdot \underbrace{Q_{\text{next}}}_{\text{next state's } Q} - \underbrace{Q_{\text{old}}}_{\text{current value}} \Big]$$

#### Episode 3 Calculation ($B \to 0.45$ and $C \to 0.875$)

Entering Episode 3, the saved values from Episode 2 are $Q(A, R) = 0$, $Q(B, R) = 0.225$, and $Q(C, R) = 0.75$.

* **State $B \to C$:** $Q_{\text{old}} = 0.225$, $\alpha = 0.5$, $R = 0$, $\gamma = 0.9$, $Q_{\text{next}} = Q(C, R) = 0.75$

$$Q(B, R) = 0.225 + 0.5 \big[ 0 + 0.9(0.75) - 0.225 \big] = 0.225 + 0.5(0.45) = \mathbf{0.45}$$

* **State $C \to \text{Goal}$ (Terminal):** $Q_{\text{old}} = 0.75$, $\alpha = 0.5$, $R = 1$, $\gamma = 0.9$, $Q_{\text{next}} = 0$ *(Goal is terminal)*

$$Q(C, R) = 0.75 + 0.5 \big[ 1 + 0.9(0) - 0.75 \big] = 0.75 + 0.5(0.25) = \mathbf{0.875}$$

#### How $Q(C, R)$ and $Q(A, R)$ Change Gradually

* **State $C$ (Direct Goal Access):** Because $C$ touches the Goal directly, its target is always $R + 0 = 1.0$. With $\alpha = 0.5$, each episode closes **half the remaining gap** between $Q_{\text{old}}$ and $1.0$:
  * **Ep 1:** $0.0 + 0.5[1 - 0.0] = \mathbf{0.5}$
  * **Ep 2:** $0.5 + 0.5[1 - 0.5] = \mathbf{0.75}$
  * **Ep 3:** $0.75 + 0.5[1 - 0.75] = \mathbf{0.875}$ *(gradually approaching $1.0$)*
* **State $A$ (Delayed 2-Step Propagation):** $A$ only looks one step ahead at $B$ ($R = 0$, so its target is just $0.9 \times Q(B, R)$). It stays stuck at $0$ until $B$ finally learns something from $C$:
  * **Ep 1:** $Q_{\text{next}} = Q(B, R) = 0.0 \implies 0 + 0.5[0 + 0.9(0.0) - 0] = \mathbf{0.0}$
  * **Ep 2:** When the agent leaves $A$, $B$ still hasn't been updated yet ($Q_{\text{next}} = 0.0$) $\implies \mathbf{0.0}$
  * **Ep 3:** $B$ now holds $0.225$ from the end of Ep 2 ($Q_{\text{next}} = 0.225$) $\implies 0 + 0.5[0 + 0.9(0.225) - 0] = \mathbf{0.10125}$

---

## 3.2 Complete TD Study Notes (`lec3_TD_note.pdf`)

### 1. The Core Idea & Universal Formula

* **Monte Carlo** waits until the whole episode ends to update using the complete return $G_t$.
* **Temporal Difference (TD)** updates **after every single step** ($S_t \to R_{t+1} \to S_{t+1}$) using **bootstrapping**—updating one guess using another guess ($R_{t+1} + \gamma V(S_{t+1})$).
* Every TD equation follows one master template:

$$\text{New Estimate} = \text{Old Estimate} + \alpha \big(\text{Target} - \text{Old Estimate}\big)$$

*(Here, $\text{Target} - \text{Old Estimate}$ is the **TD Error $\delta_t$**, which measures prediction error.)*

### 2. The Three Equations Side by Side

1. **TD(0):** $V(S) \leftarrow V(S) + \alpha \big[R + \gamma V(S') - V(S)\big]$
2. **SARSA (On-Policy):** $Q(S, A) \leftarrow Q(S, A) + \alpha \big[R + \gamma Q(S', A') - Q(S, A)\big]$
3. **Q-Learning (Off-Policy):** $Q(S, A) \leftarrow Q(S, A) + \alpha \big[R + \gamma \max_a Q(S', a) - Q(S, A)\big]$

### 3. The 4 Common Student Mistakes

1. Using $\max_a Q(S', a)$ inside SARSA (SARSA must use the actual next action $Q(S', A')$).
2. Using the actual next action inside Q-Learning (Q-Learning must use $\max_a Q(S', a)$).
3. Forgetting to subtract the old estimate inside the brackets ($Q \leftarrow Q + \alpha[\text{Target} - Q]$).
4. **Including future value after a terminal state:** When $S'$ is terminal, $Q(S_{\text{terminal}}, a) = 0$, so the target is just $R_{t+1}$.

### 4. Extra Practice Problem

Suppose $Q(S, A) = 5$, $R = 0$, $\alpha = 0.5$, $\gamma = 1$, and at the next state $Q(S', A_1) = 4$ and $Q(S', A_2) = 9$. The behavior policy selects $A_1$:

**SARSA** uses the actual action $A_1$ (`4`):

$$\text{Target} = 0 + 1(4) = 4 \implies Q_{\text{new}} = 5 + 0.5(4 - 5) = \mathbf{4.5}$$

**Q-Learning** uses the greedy max (`9`):

$$\text{Target} = 0 + 1(9) = 9 \implies Q_{\text{new}} = 5 + 0.5(9 - 5) = \mathbf{7.0}$$

### 5. The 4 Take-Home Questions

* **Monte Carlo asks:** *"What complete return did I eventually receive?"*
* **TD Learning asks:** *"Given what happened now and what I currently expect next, how should I change my estimate?"*
* **SARSA asks:** *"What action will I **actually** take next?"*
* **Q-Learning asks:** *"What is the **best** action I **could** take next?"*

---

# 4. Deep Q-Networks (DQN)

*Sources: `DQN_UG_Class_Notes.pdf` and `DQNSlides.pdf`*

Both `DQN_UG_Class_Notes.pdf` and `DQNSlides.pdf` cover **Deep Q-Networks (DQN)** as a direct upgrade to tabular Q-Learning—the notes provide detailed explanations while the slides give the visual summary.

## 4.1 Why Q-Tables Break Down

In small gridworlds (like 20 states and 4 actions), a Q-table only needs $20 \times 4 = 80$ cells, which is easy to store and update. In real-world problems, tables fall apart for three simple reasons:

* **Too many states:** A problem with $10^6$ states and 4 actions needs $4 \times 10^6$ table entries, and image-based games have an astronomical number of possible screens.
* **Continuous numbers:** In CartPole, the state is 4 continuous real numbers (cart position, cart velocity, pole angle, pole angular velocity), so you almost never see the exact same decimal state twice.
* **Zero generalization:** A table treats every cell as an isolated island; learning what to do in one state teaches the table nothing about a nearly identical neighboring state.

**The Solution:** Replace the giant lookup table $Q(s, a)$ with a **neural network** $Q_\theta(s, a)$ whose weights and biases ($\theta$) act as a smooth function that can estimate Q-values and share knowledge across similar states.

---

## 4.2 How a DQN Looks and Picks Actions

Instead of feeding both the state and one action into the network, a standard DQN takes **only the state $s$** as input and outputs **one Q-value for every possible discrete action at the same time**:

* **CartPole Example:** The network is `Input (4 numbers) -> Dense(64) + ReLU -> Dense(64) + ReLU -> Output (2 numbers)`.
* **The 2 Outputs:** Output 1 is $Q_\theta(s, \text{Left})$ and Output 2 is $Q_\theta(s, \text{Right})$.
* **Crucial Exam Point (Not Probabilities!):** These outputs are **NOT probabilities** (so there is no Softmax layer). They are estimated discounted returns and can be any positive or negative number (e.g., `2.3` and `4.7`).
* **Exploration still works the same way:** DQN still uses an **$\epsilon$-greedy policy**—pick a random action with probability $\epsilon$ to explore, and pick $\arg\max_a Q_\theta(s, a)$ with probability $1 - \epsilon$ to exploit, gradually shrinking $\epsilon$ over time.

---

## 4.3 Turning Q-Learning Into Neural Network Training

In tabular Q-Learning, you nudge one cell in a table. In DQN, you treat Q-Learning like a **mini supervised regression problem** where the Bellman backup creates the "target" number $y$, and backpropagation adjusts the network's weights $\theta$ to reduce the squared error.

For any transition $(s, a, r, s', d_{\text{term}})$:

* **Prediction ($\hat{q}$):** Take the online network's output **only for the action $a$ that was actually taken**: $\hat{q} = Q_\theta(s, a)$. *(If the network outputs `4` for Left and `7` for Right, and the agent chose Left, you only train the `4`.)*
* **Bellman Target ($y$):** Compute the target using the **target network** ($\bar{\theta}$) and treat $y$ as a fixed constant (no gradients flow through it):

$$y = r + \gamma (1 - d_{\text{term}}) \max_{a'} Q_{\bar{\theta}}(s', a')$$

* **Squared Loss:**

$$L(\theta) = \big(y - Q_\theta(s, a)\big)^2$$

*(In practice, we average this loss over a random minibatch $B$, or use Huber/Smooth L1 loss to dampen huge errors.)*

* **Key Difference from Tables:** Because neural network weights $\theta$ are shared, one gradient update ($\theta \leftarrow \theta - \eta \nabla_\theta L_B(\theta)$) changes predictions for other states too, not just the single state-action pair you trained on.

### Worked Board Example

Suppose $r = 2$, $\gamma = 0.9$, $d_{\text{term}} = 0$ (not terminal), the online network predicts $Q_\theta(s, a) = 4$ for the action taken, and the target network outputs $(3, 5)$ for the next state $s'$:

1. **Best next-state value:** $\max(3, 5) = 5$
2. **Target ($y$):** $2 + 0.9(5) = \mathbf{6.5}$
3. **TD Error ($\delta$):** $6.5 - 4 = \mathbf{2.5}$
4. **Squared Loss ($L$):** $(2.5)^2 = \mathbf{6.25}$
5. **What if the transition were terminal ($d_{\text{term}} = 1$)?** The $(1 - 1)$ zeroes out the future, so $y = r = \mathbf{2}$.

---

## 4.4 Why Naive Neural Q-Learning Fails (And DQN's 2 Big Fixes)

If you simply plug a neural network into Q-Learning and train on steps one by one, training becomes wildly unstable. DQN introduces two stabilizing tricks to fix this:

| Problem in Naive Neural Q-Learning | Why It Hurts Training | DQN's Fix | How the Fix Works |
| :--- | :--- | :--- | :--- |
| **1. Correlated Experiences** | Consecutive steps (like pole angles 0.02 seconds apart) look nearly identical, violating the independent data assumption of SGD. | **Experience Replay Buffer ($D$)** | Store every transition $(s, a, r, s', d_{\text{term}})$ in a memory buffer and train on **uniformly random minibatches**—breaking time correlations and letting old transitions be reused multiple times. |
| **2. Moving Targets** | If one network computes both the prediction and the target, every weight update shifts the goalposts while you're trying to hit them. | **Separate Target Network ($Q_{\bar{\theta}}$)** | Keep a frozen copy of the weights ($\bar{\theta}$) to compute stable targets $y$, and periodically copy $\theta \to \bar{\theta}$ after many steps. |

* **Easy Analogy for the Target Network:** Think of the **online network ($Q_\theta$)** as a student improving their answers, and the **target network ($Q_{\bar{\theta}}$)** as a temporarily fixed reference sheet. After the student studies for a while, you refresh the reference sheet from the improved student—remembering that it's still an *estimated* answer key, not ground truth.
* **Important Coding Detail (`terminated` vs. `truncated`):** In Gymnasium (like `CartPole-v1`), an episode can end because the pole actually fell (`terminated = True`) or simply because the 500-step timer ran out (`truncated = True`). You should store **`terminated`** (not `terminated or truncated`) as $d_{\text{term}}$ because hitting a time limit does not mean future value is zero—you still want to bootstrap!

---

## 4.5 The Complete DQN Cycle & Key Exam Takeaways

A single DQN training loop repeats these steps:

1. Pick action $a$ using $\epsilon$-greedy on the online network $Q_\theta$.
2. Act in the environment, observe $(r, s', d_{\text{term}})$, and save $(s, a, r, s', d_{\text{term}})$ into the replay buffer $D$.
3. Sample a random minibatch from $D$.
4. Compute targets $y_i$ with the frozen target network $Q_{\bar{\theta}}$ (no gradients) and predictions with the online network $Q_\theta$.
5. Compute the mean squared loss, backpropagate to update **only** $\theta$, and periodically copy $\theta \to \bar{\theta}$.

### Three Exam Warnings to Remember

* **Lower Loss $\neq$ Better Policy:** DQN loss only measures how closely predictions match *current moving targets*—it can be tiny when the agent is terrible, so always judge performance by **episode return** (and its moving average), not loss.
* **Deadly Triad & Limits:** Even with replay and target networks, DQN isn't guaranteed to converge because it combines **function approximation + bootstrapping + off-policy learning** (the Deadly Triad), and it only works naturally for **discrete** action spaces.
* **What Comes Next:** Standard DQN is improved by **Double DQN** (reduces overestimation bias), **Dueling DQN** (splits state value and advantage), and **Prioritized Experience Replay** (samples important transitions more often).

---

# 5. Markov Decision Processes (MDP) — Exam Q&A

## 5.1 Define an MDP and Its Key Components `[M: 3]`

A **Markov Decision Process (MDP)** is the standard mathematical framework used in Reinforcement Learning to model sequential decision-making problems, where an agent interacts with an environment step by step to achieve a goal. An MDP follows the **Markov Property**, which simply means the future depends *only* on the current state and action—not on how the agent got there (the past history does not matter).

Mathematically, an MDP is defined by a 5-tuple:

$$(S, A, P, R, \gamma)$$

**Key Components of an MDP:**

1. **State Space ($S$):** The set of all possible situations or positions the agent can be in. A state $s \in S$ is a snapshot of everything the agent can observe at a given moment (for example, the agent's current tile on a gridworld).
2. **Action Space ($A$):** The set of all possible moves or decisions the agent can take to affect the environment (for example, moving Left, Right, Up, or Down).
3. **Transition Probability Function ($P$):** The "rules" or physics of the environment. Written as $P(s' \mid s, a) = \Pr(S_{t+1} = s' \mid S_t = s, A_t = a)$, it tells us the probability of landing in a new state $s'$ after taking action $a$ in state $s$. This captures any randomness in the environment (such as slipping on ice).
4. **Reward Function ($R$):** A numerical feedback signal given by the environment after each action, written as $R(s, a, s')$. It assigns a positive score for good outcomes (like reaching a goal) and a negative score for mistakes or delays.
5. **Discount Factor ($\gamma$):** A number in the range $[0, 1]$ (typically $\gamma \in [0, 1)$) that controls how much the agent values future rewards compared to immediate ones. A value near $0$ makes the agent short-sighted (only caring about instant reward), while a value near $1$ makes it far-sighted and ensures that total rewards in long or continuing tasks stay finite.

Using these five components, the ultimate objective of solving an MDP is to find a policy $\pi$ (a strategy for choosing actions) that maximizes the agent's total expected discounted reward over time.

---

## 5.2 Formal 5-Tuple Description of an MDP $(S, A, P, R, \gamma)$ `[M: 3]`

A **Markov Decision Process (MDP)** is formally defined by the 5-tuple **$(S, A, P, R, \gamma)$**, which provides the complete mathematical blueprint of a Reinforcement Learning problem. Each component describes a specific part of how the agent interacts with the environment:

1. **$S$ — State Space:**  
   The set of all possible situations, positions, or configurations the agent can be in. A state $s \in S$ acts as a snapshot of everything the agent observes at a given moment (for example, the 16 tiles on a $4 \times 4$ FrozenLake grid or the sensor readings of a drone).

2. **$A$ — Action Space:**  
   The set of all valid moves or decisions the agent can choose to influence the environment. Depending on the problem, actions can be discrete (such as Left, Down, Right, Up) or continuous (such as steering angles).

3. **$P$ — Transition Probability Function:**  
   The "physics" or rules of the environment, written as:

   $$P(s' \mid s, a) = \Pr(S_{t+1} = s' \mid S_t = s, A_t = a)$$

   It specifies the probability of landing in the next state $s'$ when the agent takes action $a$ from state $s$. This accounts for uncertainty or randomness in the world (for instance, slipping sideways on icy tiles instead of moving straight ahead).

4. **$R$ — Reward Function:**  
   A scalar numerical score issued by the environment after each transition, written as $R(s, a, s')$. It tells the agent how good or bad an outcome was—giving positive rewards for reaching goals and negative penalties for crashes, mistakes, or wasting time.

5. **$\gamma$ — Discount Factor:**  
   A scalar value in the range $\gamma \in [0, 1]$ (usually $[0, 1)$) that controls how much the agent values future rewards compared to immediate rewards. A value close to $0$ makes the agent short-sighted (caring only about instant reward), while a value close to $1$ makes it far-sighted and ensures that the total return stays finite in long or continuing tasks.

Together, these five components define the entire decision-making problem, allowing the agent to learn a policy $\pi$ that maximizes its expected cumulative discounted reward over time.
