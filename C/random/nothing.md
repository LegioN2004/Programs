Sure! Below is the text with the correct LaTeX code surrounded by dollar symbols for your use in Notion.

---

In a number system, the **maximum number representable** with a given number of digits depends on two key factors:  

### 1. **The Base (or Radix) of the Number System**  
   - The base determines the range of symbols (digits) used in the number system. For example:
     - **Base 2 (Binary)**: Uses two digits, $0$ and $1$.
     - **Base 10 (Decimal)**: Uses ten digits, $0$ to $9$.
     - **Base 16 (Hexadecimal)**: Uses sixteen symbols, $0, 1, 2, \dots, 9, A, B, \dots, F$.  

### 2. **The Number of Digits (n)**  
   - The maximum number depends on how many digits ($n$) are available in the representation.  

---

### Formula for the Maximum Number Representable:
$$
\text{Maximum Number} = \text{Base}^n - 1
$$

- This formula works because the largest possible number uses the maximum symbol for each digit (e.g., $1$ in binary, $9$ in decimal, $F$ in hexadecimal) in all positions.

---

### Examples:

1. **Binary (Base 2)**:  
   - With 4 digits: $$2^4 - 1 = 16 - 1 = 15$$ ($1111_2$ in binary).  

2. **Decimal (Base 10)**:  
   - With 3 digits: $$10^3 - 1 = 1000 - 1 = 999$$.  

3. **Hexadecimal (Base 16)**:  
   - With 2 digits: $$16^2 - 1 = 256 - 1 = 255$$ ($FF_{16}$ in hexadecimal).  

---

### Special Case: Signed Numbers  
- For **signed number systems** (e.g., 2's complement):  
   - The range is divided into positive and negative numbers.  
   - The maximum positive number is slightly less than the maximum in an unsigned system because the MSB is used to represent the sign.  

For $n$-bit signed 2's complement:  
$$
\text{Range: } -2^{n-1} \text{ to } 2^{n-1} - 1
$$  

Let me know if you'd like this expanded further!