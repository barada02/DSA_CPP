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

## 🔍 What Counts as an Operation?

### Basic Operations (Each = 1 operation)

#### 1. **Arithmetic Operations**
```cpp
int a = 5 + 3;      // 1 operation (addition)
int b = x * y;      // 1 operation (multiplication)
int c = a / b;      // 1 operation (division)
int d = x % 2;      // 1 operation (modulo)
```

#### 2. **Comparison Operations**
```cpp
if(a < b)           // 1 operation (comparison)
if(x == y)          // 1 operation (equality check)
if(n >= 0)          // 1 operation (comparison)
```

#### 3. **Assignment Operations**
```cpp
int x = 5;          // 1 operation (assignment)
total += value;     // 2 operations (addition + assignment)
count++;            // 2 operations (increment + assignment)
```

#### 4. **Array/Memory Access**
```cpp
int val = arr[i];   // 1 operation (array access)
arr[i] = 10;        // 1 operation (array write)
```

#### 5. **Return Statements**
```cpp
return x;           // 1 operation
return arr[0];      // 1 operation
```

#### 6. **Function Calls**
```cpp
int result = max(a, b);  // 1 operation (if we're not analyzing the function)
```

### What We DON'T Count
- Variable declarations (without initialization)
- Comments
- Whitespace
- Curly braces

---

## 💻 Detailed Examples with Step-by-Step Analysis

### Example 1: Constant Operations

```cpp
int getFirst(int arr[], int n) {
    return arr[0];
}
```

**Operation Count:**
1. Array access `arr[0]`: 1 operation
2. Return: 1 operation

**Total: 2 operations**

**Important:** This is **constant** - doesn't depend on n!
- n = 10 → 2 operations
- n = 1,000,000 → 2 operations

**Time Complexity:** f(n) = 1 (we express constants as 1)

---

### Example 2: Simple Linear Loop

```cpp
int findMax(int arr[], int n) {
    int max = arr[0];              // 1 operation
    
    for(int i = 1; i < n; i++) {  // Loop analysis below
        if(arr[i] > max) {         // 1 comparison per iteration
            max = arr[i];          // 1 assignment (sometimes)
        }
    }
    
    return max;                    // 1 operation
}
```
