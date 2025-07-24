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

