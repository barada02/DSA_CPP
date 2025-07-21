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