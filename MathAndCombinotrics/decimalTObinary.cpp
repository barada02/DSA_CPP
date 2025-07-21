#include <iostream>
#include <string>
#include <algorithm>
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
//[Approach - 2] Bit Manipulation - O(log₂(n)) Time and O(1) Space
/*To convert a decimal number to binary using bit manipulation, repeatedly shift the number right and check the least significant bit.
*/
string decToBinary(int n) {
    
    string bin = "";
    while (n > 0) {
        // checking the mod 
		int bit = n%2;
      	bin.push_back('0' + bit);
        n /= 2;
    }
    
    // reverse the string 
	reverse(bin.begin(), bin.end());
    return bin;
}

/*Using Head Recursion - O(log₂(n)) Time and O(log₂(n)) Space */

void decimalToBinaryRec(int n) {
    if (n == 0) {
        return;
    }

    // Recur for smaller bits.
    decimalToBinaryRec(n / 2);
    cout << (n % 2);

    // Add MSB of current number to the binary string
  	bin.push_back(n%2 + '0');
}

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;
    decimalToBinary(n);
    cout << endl;
    cout << "Binary representation using bit manipulation: " << decToBinary(n) << endl;
    return 0;
}