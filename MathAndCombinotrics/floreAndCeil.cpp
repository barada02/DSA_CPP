#include <iostream>

using namespace std;

/*

Given two integers a and b (where b ≠ 0). The objective is to find:
• The floor of the division a / b, denoted as ⌊a / b⌋ — the greatest integer less than or equal to a / b.
• The ceil of the division a / b, denoted as ⌈a / b⌉ — the smallest integer greater than or equal to a / b.
The floor and ceil functions are commonly used in mathematics and computer science to round numbers down or up, respectively.
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

    if ((a^b)<0 && a%b !=0){
        q++;
    }
    return q;
}