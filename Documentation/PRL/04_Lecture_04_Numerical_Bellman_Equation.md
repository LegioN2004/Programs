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
| Bellman Residual $\Delta$ | $\|0.7373 - 0.70\|$ | $0.0373$ | **$0.037$** |

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

$$\text{Error in } Q(\text{Right}) = 0.8720 - 0.8080 = +0.0640 \text{ (+7.9\%)}$$
$$\text{Error in } Q(\text{Left}) = 0.4680 - 0.4545 = +0.0135 \text{ (+3.0\%)}$$
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
