# Comparison of Two Approaches for Decimal to Binary Conversion in C++

## Approach1 (binary = char(...) + binary;):

* Advantage: Builds the string in the correct order from the start by prepending characters, avoiding the need for a final reverse operation.

* Potential Performance (minor): Prepending to a std::string can sometimes be slightly less efficient than appending, especially for very long strings, as it might involve reallocating and copying the entire string. However, for typical integer sizes, this difference is negligible.

## Approach2 (bin.push_back(...) and reverse):

* Advantage: push_back() is generally very efficient for std::string as it usually just adds to the end of allocated memory.

* Disadvantage: Requires an extra step (reverse) at the end to get the correct order.

Readability: Some might find this approach slightly more intuitive (add digits as they are found, then fix the order).