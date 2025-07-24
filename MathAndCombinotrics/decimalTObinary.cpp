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
    while(n>0){
        binary = char('0' + (n % 2)) + binary; // Prepend the remainder
        
        n /= 2; // Divide by 2
    }

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

/* Approach - 3
Using Head Recursion - O(log₂(n)) Time and O(log₂(n)) Space */

void decimalToBinaryRec(int n, string &bin) {
    if (n == 0) {
        return;
    }

    // Recur for smaller bits.
    decimalToBinaryRec(n / 2, bin);

    // Add MSB of current number to the binary string
    bin.push_back(n % 2 + '0');
}


/* Approach - 4
 Using Bitwise Operators - O(log₂(n)) Time and O(log₂(n)) Space
Using bitwise operators, we can extract binary digits by checking the least significant bit (n & 1) and then right-shifting the number (n >> 1) to process the next bit.
This method is faster than arithmetic division and modulo, as bitwise operations are more efficient at the hardware level.
*/

string dectobinary4(int n){
    if(n == 0){
        return "0";
    }

    string bin = "";
    
    while (n>0){

        // Finding (n % 2) using bitwise AND operator

        int bit = n & 1; // Get the least significant bit (LSB)

        bin.push_back('0'+ bit); // Append the bit to the string

        n >>= 1; // Right shift the number to process the next bit
    }
    reverse(bin.begin(), bin.end()); // Reverse the string to get the correct order
    return bin;
}



int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    // Using iterative approach
    decimalToBinary(n);
    cout << endl;

    // Using recursive approach
    string bin = "";
    decimalToBinaryRec(n, bin);
    cout << "Binary representation using recursion: " << bin << endl;

    return 0;
}