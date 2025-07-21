#include <iostream>

using namespace std;

 // Naieve approach to check if a number is even or odd

bool isEven(int n){
    if (n%2 == 0){
        return true;
    }
    return false;
}

/*
   Optimized approach to check if a number is even or odd
   using bitwise operator
*/
/*
The last bit of all odd numbers is always 1, while for even numbers it’s 0. 
So, when performing bitwise AND operation with 1, odd numbers give 1, and even numbers give 0.

Note: Bitwise operators are extremely fast and efficient because they operate directly at the binary level, 
making them significantly faster than arithmetic or logical operations.
*/
bool isEven2(int n){
    if((n&1)==0){
        return true;
    }
    return false;
}


int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isEven(n)) {
        cout << n << " is even." << endl;
    } else {
        cout << n << " is odd." << endl;
    }

    return 0;
}   