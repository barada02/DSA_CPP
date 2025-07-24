# Comparison of Two Approaches for Decimal to Binary Conversion in C++

## Approach1 (binary = char(...) + binary;):

* Advantage: Builds the string in the correct order from the start by prepending characters, avoiding the need for a final reverse operation.

* Potential Performance (minor): Prepending to a std::string can sometimes be slightly less efficient than appending, especially for very long strings, as it might involve reallocating and copying the entire string. However, for typical integer sizes, this difference is negligible.

## Approach2 (bin.push_back(...) and reverse):

* Advantage: push_back() is generally very efficient for std::string as it usually just adds to the end of allocated memory.

* Disadvantage: Requires an extra step (reverse) at the end to get the correct order.

Readability: Some might find this approach slightly more intuitive (add digits as they are found, then fix the order).

## Approach3 recursive.
```cpp
void decimalToBinaryRec(int n, string &bin) {
    // 1. Base Case: When 'n' becomes 0
    // This is the termination condition for the recursion.
    // When n is 0, there are no more bits to process for the current path.
    if (n == 0) {
        return; 
    }

    // 2. Recursive Step: Process the "next" set of bits (higher place values)
    // This line is crucial for the order of operations in recursion.
    // It calls the function again with n / 2. This effectively means:
    // "First, figure out the binary representation for the number n / 2,
    // and then come back to process the current 'n'."
    decimalToBinaryRec(n / 2, bin); 

    // 3. Work after the recursive call returns: Process the current bit
    // This part of the code executes only AFTER the recursive call above it has finished.
    // It takes the remainder of n divided by 2 (n % 2), which is the current binary digit (0 or 1).
    // '0' + (n % 2) converts this integer (0 or 1) into its character equivalent ('0' or '1').
    // bin.push_back(...) appends this character to the end of the 'bin' string.
    // Because of the order of the recursive call and this line, the digits are appended
    // in the correct order (Most Significant Bit first).
    bin.push_back(n % 2 + '0'); 
}
```
This recursive approach cleverly leverages the call stack to build the binary string in the correct order without needing an explicit reverse operation at the end (unlike the push_back iterative method).

### The core idea is:

* To get the binary of N:

* First, get the binary of N / 2.

Then, append N % 2 (the remainder).

### With example explanation:

#### Trace for decimalToBinaryRec(13, bin):
##### decimalToBinaryRec(13, bin) called:

* n is 13 (not 0).

* Call decimalToBinaryRec(13 / 2, bin) -> decimalToBinaryRec(6, bin)

  * n is 6 (not 0).

  * Call decimalToBinaryRec(6 / 2, bin) -> decimalToBinaryRec(3, bin)

    * n is 3 (not 0).

    * Call decimalToBinaryRec(3 / 2, bin) -> decimalToBinaryRec(1, bin)

      * n is 1 (not 0).

      * Call decimalToBinaryRec(1 / 2, bin) -> decimalToBinaryRec(0, bin)

          * n is 0.

          * Base Case hit! return; (This call returns)

       * Back in 'decimalToBinaryRec(1, bin)':

         * bin.push_back(1 % 2 + '0'); // 1 % 2 is 1. bin becomes "1".

       * Return.

    * Back in 'decimalToBinaryRec(3, bin)':

       * bin.push_back(3 % 2 + '0'); // 3 % 2 is 1. bin becomes "11".

    * Return.

  * Back in 'decimalToBinaryRec(6, bin)':

    * bin.push_back(6 % 2 + '0'); // 6 % 2 is 0. bin becomes "110".

  * Return.

* Back in 'decimalToBinaryRec(13, bin)':

  * bin.push_back(13 % 2 + '0'); // 13 % 2 is 1. bin becomes "1101".

* Return.

After the initial call completes, the bin string will contain "1101".

### Approach4 (Using Bitwise Operators):



```cpp
string dectobinary4(int n){
    // 1. Base Case: Handle the input of 0
    // If the input number is 0, its binary representation is "0".
    // This handles the edge case explicitly and prevents the loop from running for 0.
    if(n == 0){
        return "0";
    }

    // 2. Initialize an empty string to build the binary number
    string bin = "";

    // 3. Main Loop: Continues as long as 'n' is greater than 0
    // The loop extracts bits from 'n' one by one, starting from the LSB.
    while (n > 0){
        // 4. Finding (n % 2) using bitwise AND operator
        // int bit = n & 1;
        // This is a clever and often more efficient way to get the least significant bit (LSB).
        // - Any number ANDed with 1 (`... & 1`) will result in:
        //   - 1 if the number is odd (its LSB is 1)
        //   - 0 if the number is even (its LSB is 0)
        // This is equivalent to `n % 2`.
        int bit = n & 1; // Get the least significant bit (LSB)

        // 5. Append the character representation of the bit to the 'bin' string.
        // '0' + bit converts integer 0 to character '0' and integer 1 to character '1'.
        // push_back() adds the character to the end of the string.
        // Similar to the previous iterative example, this builds the string in reverse order (LSB first).
        bin.push_back('0' + bit); // Append the bit to the string

        // 6. Right shift the number to process the next bit
        // n >>= 1;
        // This is the bitwise right shift operator. It effectively divides 'n' by 2
        // and discards any fractional part (which is exactly what integer division `n /= 2` does).
        // For example, if n = 13 (binary 1101), n >>= 1 makes n = 6 (binary 0110).
        // It shifts all bits one position to the right, effectively dropping the LSB and
        // moving the next bit into the LSB position for the next iteration.
        n >>= 1;
    }

    // 7. Reverse the string to get the correct order
    // Because push_back() appends bits from LSB to MSB, the string is built in reverse.
    // This step corrects the order to MSB to LSB.
    reverse(bin.begin(), bin.end()); // Reverse the string to get the correct order

    // 8. Return the final binary string
    return bin;
}
```

-----

### How it Works (Bitwise Approach)

This function employs the same underlying algorithm of **repeated division by 2** but implements the division and remainder calculation using **bitwise operators**, which can sometimes be more efficient at a low level (though modern compilers often optimize `n % 2` and `n /= 2` to use bitwise operations anyway).

### Key Bitwise Operators Used:

  * **`&` (Bitwise AND):**

      * `n & 1`: Performs a bitwise AND operation between `n` and `1`.
      * Since `1` in binary is `...0001`, this operation effectively isolates the rightmost bit (Least Significant Bit or LSB) of `n`. All other bits, when ANDed with `0` (from `1`), become `0`.
      * If `n`'s LSB is `1`, `n & 1` will be `1`.
      * If `n`'s LSB is `0`, `n & 1` will be `0`.
      * This is a highly optimized way to check if a number is odd or even, and to get its LSB.

  * **`>>=` (Right Shift Assignment):**

      * `n >>= 1`: This is equivalent to `n = n >> 1`.
      * The `>>` operator performs a **right bit shift**. It moves all bits in `n` one position to the right.
      * When you right-shift by `1`, the LSB is discarded, and the second LSB becomes the new LSB, and so on.
      * This effectively performs integer division by 2. For example, `13 (1101_2) >> 1` results in `6 (0110_2)`.

### Example Walkthrough (for `n = 13`)

| Iteration | `n` (start) | Binary of `n` | `bit` (`n & 1`) | `bin` (before `push_back`) | `bin` (after `push_back`) | `n` (`n >>= 1`) | Binary of `new n` |
| :-------- | :---------- | :------------ | :-------------- | :------------------------- | :------------------------ | :-------------- | :---------------- |
| Initial   | 13          | `...1101`     |                 | ""                         | ""                        |                 |                   |
| 1         | 13          | `...1101`     | 1               | ""                         | "1"                       | 6               | `...0110`         |
| 2         | 6           | `...0110`     | 0               | "1"                        | "10"                      | 3               | `...0011`         |
| 3         | 3           | `...0011`     | 1               | "10"                       | "101"                     | 1               | `...0001`         |
| 4         | 1           | `...0001`     | 1               | "101"                      | "1011"                    | 0               | `...0000`         |

Loop terminates because `n` is now `0`.

The `bin` string is currently `"1011"`.

`reverse(bin.begin(), bin.end());` will reverse `"1011"` to `"1101"`.

Finally, `return bin;` returns `"1101"`.

-----

### Advantages of Bitwise Operations:

  * **Performance:** Bitwise operations (`&`, `>>`) are often faster than arithmetic operations (`%`, `/`) at the machine code level, as they directly manipulate bits. Modern compilers are very good at optimizing, so the practical difference might be small for simple integer conversions, but it's a fundamental optimization technique.
  * **Conciseness:** They provide a compact way to express common bit manipulations.

This `dectobinary4` function is a well-implemented and efficient way to convert decimal to binary, particularly highlighting the use of bitwise operators.
