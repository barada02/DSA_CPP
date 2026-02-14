# Session 2: Time Complexity
## Understanding How Algorithms Scale

---

## 🎯 What is Time Complexity?

**Time Complexity** is a computational concept that describes the amount of time an algorithm takes to complete as a function of the input size.

### It's NOT:
- ❌ The actual time in seconds/milliseconds
- ❌ The exact number of operations
- ❌ Dependent on the machine or language

### It IS:
- ✅ A function describing growth relative to input size
- ✅ The **pattern** of how runtime scales
- ✅ The **order of magnitude** of operations
- ✅ Machine-independent and language-independent

---

## 📐 Formal Definition

> **Time Complexity = f(n)**
> 
> Where:
> - **f(n)** is a mathematical function
> - **n** is the size of the input
> - The function describes the number of basic operations

**Example:**
- If an algorithm performs 5n + 3 operations, then f(n) = 5n + 3
- As n grows large, this behaves like f(n) = n

---
