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

**Detailed Count:**

| Statement | Count | Explanation |
|-----------|-------|-------------|
| `int max = arr[0]` | 1 | One-time initialization |
| `int i = 1` | 1 | Loop initialization |
| `i < n` | n | Comparison happens n times |
| `i++` | n-1 | Increment happens n-1 times |
| `arr[i] > max` | n-1 | Comparison in each iteration |
| `max = arr[i]` | 0 to n-1 | Worst case: n-1 times |
| `return max` | 1 | Final return |

**Total (worst case):** 1 + 1 + n + (n-1) + (n-1) + (n-1) + 1 = **4n - 1**

**Time Complexity:** f(n) = 4n - 1 ≈ **n** (linear)

---

### Example 3: Sum of Array

```cpp
int sumArray(int arr[], int n) {
    int sum = 0;                    // 1 operation
    
    for(int i = 0; i < n; i++) {   // Loop: n iterations
        sum += arr[i];              // 2 operations: access + add
    }
    
    return sum;                     // 1 operation
}
```

**Operation Count:**
- Initialization: 1
- Loop runs n times
- Inside loop: 2 operations per iteration → 2n
- Return: 1

**Total:** 1 + 2n + 1 = **2n + 2**

**Time Complexity:** f(n) = 2n + 2 ≈ **n**

---

### Example 4: Nested Loops

```cpp
void printAllPairs(int arr[], int n) {
    for(int i = 0; i < n; i++) {           // Outer loop: n times
        for(int j = 0; j < n; j++) {       // Inner loop: n times
            cout << arr[i] << ", " << arr[j] << endl;  // Constant work
        }
    }
}
```

**Operation Count:**
- Outer loop runs: n times
- For each outer iteration, inner loop runs: n times
- Total iterations: n × n = n²
- Operations per iteration: ~5 (2 array accesses, 2 outputs, 1 newline)

**Total:** 5n²

**Time Complexity:** f(n) = 5n² ≈ **n²** (quadratic)

---

### Example 5: Three Sequential Loops

```cpp
void threeLoops(int arr[], int n) {
    // First loop
    for(int i = 0; i < n; i++) {
        cout << arr[i];             // n operations
    }
    
    // Second loop
    for(int i = 0; i < n; i++) {
        cout << arr[i] * 2;         // n operations
    }
    
    // Third loop
    for(int i = 0; i < n; i++) {
        cout << arr[i] + 1;         // n operations
    }
}
```

**Operation Count:**
- First loop: n operations
- Second loop: n operations  
- Third loop: n operations

**Total:** n + n + n = **3n**

**Time Complexity:** f(n) = 3n ≈ **n** (still linear!)

**Key Insight:** Sequential loops ADD, they don't multiply!

---

## 🎨 The Art of Simplification

### Rule 1: Drop Constants

Constants become insignificant for large n.

```cpp
// f(n) = 5n + 3
n = 10:     5(10) + 3 = 53
n = 1000:   5(1000) + 3 = 5,003      (constant is 0.06%)
n = 1M:     5(1M) + 3 = 5,000,003    (constant is 0.00006%)
```

**Simplification:** 5n + 3 → 5n → **n**

### Rule 2: Drop Lower-Order Terms

Higher-order terms dominate as n grows.

```cpp
// f(n) = n² + 100n + 50
n = 10:     100 + 1000 + 50 = 1,150      (n² is 8.7%)
n = 100:    10,000 + 10,000 + 50 = 20,050    (n² is 50%)
n = 1000:   1,000,000 + 100,000 + 50 = 1,100,050  (n² is 91%)
n = 10000:  100M + 1M + 50 ≈ 101M     (n² is 99%)
```

**Simplification:** n² + 100n + 50 → n² + 100n → **n²**

### Rule 3: Keep Different Input Variables

```cpp
void processTwoArrays(int arr1[], int n, int arr2[], int m) {
    for(int i = 0; i < n; i++) {
        cout << arr1[i];    // n operations
    }
    
    for(int i = 0; i < m; i++) {
        cout << arr2[i];    // m operations
    }
}
```

**Time Complexity:** f(n, m) = **n + m**

**Cannot simplify further** because n and m are independent!

---

## 📊 Common Time Complexity Patterns

### Pattern 1: Constant Time - O(1)
```cpp
void constantTime(int arr[], int n) {
    cout << arr[0];           // Operation 1
    cout << arr[n/2];         // Operation 2
    cout << arr[n-1];         // Operation 3
    int sum = arr[0] + arr[5]; // Operation 4
}
```
**Fixed number of operations, regardless of n**  
**Time Complexity:** f(n) = 1

---

### Pattern 2: Linear Time - O(n)
```cpp
void linearTime(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i];
    }
}
```
**Operations scale linearly with input**  
**Time Complexity:** f(n) = n

---

### Pattern 3: Quadratic Time - O(n²)
```cpp
void quadraticTime(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i] + arr[j];
        }
    }
}
```
**Nested loops, operations = n × n**  
**Time Complexity:** f(n) = n²

---

### Pattern 4: Logarithmic Time - O(log n)
```cpp
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == target) return mid;
        if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```
**Input space halved each iteration**  
**Time Complexity:** f(n) = log n

---

### Pattern 5: Linearithmic Time - O(n log n)
```cpp
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);       // Divide
        mergeSort(arr, mid + 1, right);  // Divide
        merge(arr, left, mid, right);    // Conquer (O(n))
    }
}
```
**Divide and conquer with linear merging**  
**Time Complexity:** f(n) = n log n

---
