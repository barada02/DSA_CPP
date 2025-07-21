#include <iostream>
#include <string>
using namespace std;


//Given a non negative number n, the task is to convert the given number into an equivalent binary representation.

//[Approach - 1] Division by 2 - O(log₂(n)) Time and O(log₂(n)) Space
/*To convert a decimal number to binary, repeatedly divide it by 2 and record the remainders. 
Reading these remainders in reverse gives the binary representation. 
*/

void decimalToBinary(int n) {
    if (n == 0) {
        cout << "0";
        return;
    }
    
    string binary = "";
        binary = char('0' + (n % 2)) + binary; // Prepend the remainder
        binary = to_string(n % 2) + binary; // Prepend the remainder
        n /= 2; // Divide by 2
    

    cout << binary;
}
int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;
    decimalToBinary(n);
    return 0;
}