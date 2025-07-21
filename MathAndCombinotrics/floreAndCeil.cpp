#include <iostream>

using namespace std;

/*

Given two integers a and b (where b ≠ 0). The objective is to find:
• The floor of the division a / b, denoted as ⌊a / b⌋ — the greatest integer less than or equal to a / b. which always rounds towards negative infinity.(-∞)
• The ceil of the division a / b, denoted as ⌈a / b⌉ — the smallest integer greater than or equal to a / b. which always rounds towards positive infinity.(+∞)
The floor and ceil functions are commonly used in mathematics and computer science to round numbers down or up, respectively.
*/

/* Integer Division (/): For integral operands, the / operator performs division and truncates towards zero. This means it discards any fractional part, effectively rounding towards zero.

7 / 3 = 2

-7 / 3 = -2

7 / -3 = -2

-7 / -3 = 2
*/

int floor(int a, int b){
    if (b == 0) {
        throw invalid_argument("Division by zero is not allowed.");
    }
    return a / b - (a % b < 0 ? 1 : 0); 
}
/*

The function floor tries to implement a correction:

a / b: This gives the integer division result.

(a % b < 0 ? 1 : 0): This is the correction term. It checks if the remainder (a % b) is negative.

If a % b is negative, it subtracts 1 from a / b.

If a % b is non-negative, it subtracts 0 (does nothing).
*/ 

/*
he core concept flaw is that it only considers the sign of the remainder (a % b) to decide if a correction is needed. Because a % b always takes the sign of a, this logic:

Fails to apply a needed correction when a is positive and b is negative (e.g., 7 / -3), because a % b will be positive, and 1 is not subtracted.

Applies an unneeded correction when a is negative and b is negative (e.g., -7 / -3), because a % b will be negative, and 1 is incorrectly subtracted.

The correct approach (as seen in floor2) needs to consider the signs of both a and b to determine when C++'s a/b deviates from mathematical floor division.
*/

int floor2(int a, int b){
    int q = a/b;

    if ((a^b)<0 && a%b !=0){     //a^b < 0: This expression uses the bitwise XOR operator. a^b will be negative if and only if a and b have different signs. This is a clever way to check if one is positive and the other is negative.
        q--;
    }
    return q;
}

int ceil(int a, int b){
    if (b == 0) {
        throw invalid_argument("Division by zero is not allowed.");
    }
    return a / b + (a % b > 0 ? 1 : 0);
}

int ceil2(int a, int b){
    int q = a/b;

    if ((a^b)>0 && a%b !=0){
        q++;
    }
    return q;
}


int main() {
    int a = 7, b = -3;;
    

    try {
        cout << "Floor of " << a << " / " << b << " is: " << floor(a, b) << endl;
        cout << "Ceil of " << a << " / " << b << " is: " << ceil(a, b) << endl;

        // Using alternative methods
        cout << "Floor2 of " << a << " / " << b << " is: " << floor2(a, b) << endl;
        cout << "Ceil2 of " << a << " / " << b << " is: " << ceil2(a, b) << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

// Output:
// Floor of 7 / -3 is: -2
// Ceil of 7 / -3 is: -1
// Floor2 of 7 / -3 is: -3
// Ceil2 of 7 / -3 is: -2