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

int floor2(int a, int b){
    int q = a/b;

    if ((a^b)<0 && a%b !=0){
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
    int a, b;
    cout << "Enter two integers (a and b): ";
    cin >> a >> b;

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