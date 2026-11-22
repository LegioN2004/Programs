# Practical Reinforcement Learning (CSE-ELV-701)
## High-Yield 50-Question Exam Guide & Complete Solution Bank

Welcome to the comprehensive, exam-ready solution guide for **CSE-ELV-701: Practical Reinforcement Learning**. 

This repository contains fully worked, student-friendly, and mathematically rigorous answers for all **50 anchor questions** curated from the 110-question master problem bank across all 11 lecture modules.

---

### Key Features of this Guide:
* **Intuitive Explanations:** Every problem begins with a *"First, understand the concept"* section explaining the physical intuition in plain English with everyday analogies.
* **Step-by-Step Math:** Every derivation, Bellman backup, expectation, and matrix equation is laid out step-by-step with boxed answers.
* **Exam-Ready Format:** Ready-to-write summaries, comparison tables, and quick *"Remember it in one line"* mnemonics designed for rapid exam revision.

---

### Complete Document Options:
* **All-in-One Master Guide:** [PRL_50_Question_Exam_Guide_Complete.md](PRL_50_Question_Exam_Guide_Complete.md) (Single consolidated document with all 50 questions).
* **Section-by-Section Modules:** Listed below for focused, module-wise study according to the 3-day exam schedule.

---

## 3-Day Study Schedule & Module Directory

### Day 1: Foundations, MDPs & Bellman Equations (Q1 – Q18)
* [01_Lecture_01_Intro_to_RL.md](01_Lecture_01_Intro_to_RL.md)  
  * **Q1:** Supervised vs. Reinforcement Learning Paradigm
  * **Q2:** Numerical Trajectory Scoring on the Delivery Drone
  * **Q3:** Reward Shaping Pitfalls in Autonomous Driving
  * **Q4:** The Agent–Environment Boundary (Robotic Chess Arm)
  * **Q5:** Discrete-Time Trajectory Indexing & Timing Convention
* [02_Lecture_02_Discount_MDPs_Policies_Values.md](02_Lecture_02_Discount_MDPs_Policies_Values.md)  
  * **Q6:** Numerical Discounted Return Calculation
  * **Q7:** Myopic ($\gamma = 0$) vs. Far-Sighted ($\gamma \to 1$) Decision Threshold
  * **Q8:** Formalizing the $4\times 4$ FrozenLake MDP Tuple
  * **Q9:** Boundary Reflection & Hole Avoidance on Frozen Lake
  * **Q10:** Deterministic vs. Stochastic Policies
* [03_Lecture_03_Value_Functions_Bellman_Equation.md](03_Lecture_03_Value_Functions_Bellman_Equation.md)  
  * **Q11:** State-Value Function as a Thermal Heatmap
  * **Q12:** Hand-Computing $Q(14, \text{Up})$
  * **Q13:** Deconstructing the Bellman Expectation Equation Right-to-Left
  * **Q14:** Interactive Checkpoint — Deterministic Ice & Deterministic Policy
* [04_Lecture_04_Numerical_Bellman_Equation.md](04_Lecture_04_Numerical_Bellman_Equation.md)  
  * **Q15:** Complete Reproduction & Exact Precision Check of State 14 Backup
  * **Q16:** Diagnosing the "Swapped Probability" Student Error
  * **Q17:** Full Numerical Bellman Backup at State 13
  * **Q18:** Why $V_{\text{old}}(14) = 0.70$ Does Not Appear in Synchronous Math

---

### Day 2: Dynamic Programming, Monte Carlo & TD Learning (Q19 – Q37)
* [05_Module_2_Lecture_1_Tabular_Dynamic_Programming.md](05_Module_2_Lecture_1_Tabular_Dynamic_Programming.md)  
  * **Q19:** Model-Based vs. Model-Free RL & the City-Map Analogy
  * **Q20:** Why Direct Matrix Inversion is Replaced by Iterative Policy Evaluation
  * **Q21:** Completing Iteration 2 on the $2\times 2$ Gridworld
  * **Q22:** Bellman Operator $T^\pi$ Contraction & Number of Sweeps to Convergence
  * **Q23:** Full Policy Improvement & Convergence to $\pi^*$ on the $2\times 2$ Gridworld
* [06_Module_3_Part_1_Monte_Carlo_Methods.md](06_Module_3_Part_1_Monte_Carlo_Methods.md)  
  * **Q24:** The Windy Bridge — Analytic Expectation vs. Monte Carlo Sample Mean
  * **Q25:** Ground-Truth Bellman Solution on Spear World ($\gamma = 0.8$)
  * **Q26:** Looped Episode Notebook Comparison ($\gamma = 1$)
  * **Q27:** Why $V(C)$ Alone Cannot Choose Left vs. Right Without $P$
  * **Q28:** The Coward Policy Coverage Hole
* [07_Module_3_Part_2_Monte_Carlo_Model_Free_Control.md](07_Module_3_Part_2_Monte_Carlo_Model_Free_Control.md)  
  * **Q29:** Discounted Backward Return & Estimator Comparison on $\{S_1, S_2, S_3\}$
  * **Q30:** Statistical Properties of First-Visit vs. Every-Visit MC
  * **Q31:** Deriving the $\varepsilon$-Soft Action Probability Formula
  * **Q32:** Exploring Starts vs. On-Policy $\varepsilon$-Greedy Control
* [08_Module_3_Part_3_TD_SARSA_QLearning.md](08_Module_3_Part_3_TD_SARSA_QLearning.md)  
  * **Q33:** Two-Step Sequential TD(0) Update Trace
  * **Q34:** Bootstrapping — Monte Carlo vs. Temporal Difference
  * **Q35:** Divergent Updates on the Same Transition (SARSA vs. Q-Learning)
  * **Q36:** If the Behaviour Policy Changes Over Time, Is It Still Q-Learning?
  * **Q37:** Cliff-Walking Gridworld — Conservative SARSA vs. Optimistic Q-Learning

---

### Day 3: Walkthroughs, DQN & Policy Gradients (Q38 – Q50)
* [09_Module_3_Part_4_SARSA_vs_QLearning_Walkthrough.md](09_Module_3_Part_4_SARSA_vs_QLearning_Walkthrough.md)  
  * **Q38:** Deriving the 50/50 Tie Rule and 90/10 Split Rule
  * **Q39:** Backward Wave Propagation Across Episodes
  * **Q40:** Breaking the Symmetry When Agent Rolls 10% Exploratory Action at State C in Episode 2
  * **Q41:** Asymptotic Fixed-Point Values $Q^*(s, a)$ on the 3-State Chain
* [10_Module_4_Part_1_Deep_Q_Networks_DQN.md](10_Module_4_Part_1_Deep_Q_Networks_DQN.md)  
  * **Q42:** Why Tabular Q-Learning Fails in Large & Continuous State Spaces
  * **Q43:** CartPole-v1 DQN Architecture & Exact Parameter Count
  * **Q44:** Single-Transition DQN Target, Error, and Squared Loss Calculation
  * **Q45:** Why Naive Sequential Neural Q-Learning Fails (The Three Instabilities)
  * **Q46:** Gymnasium Practical Detail — `terminated` vs. `truncated`
* [11_Module_4_Part_2_Policy_Gradient_REINFORCE.md](11_Module_4_Part_2_Policy_Gradient_REINFORCE.md)  
  * **Q47:** Architectural Comparison — Value-Based (DQN) vs. Policy-Based (REINFORCE)
  * **Q48:** Policy Gradient Theorem & Model-Free Dynamics Proof
  * **Q49:** Verifying the REINFORCE Execution Trace & Surrogate Loss
  * **Q50:** Unbiasedness of State-Dependent Baselines & PyTorch Sign Bug
