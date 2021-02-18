#include <iostream>
using std::cin;
using std::cout;

int doubleDigitValue(int digit) {
    int doubledDigit = digit * 2;
    int sum{0};
    if (doubledDigit >= 10) 
        sum = 1 + doubledDigit%10;
    else
        sum = doubledDigit;
    return sum;
}

int main() {
    char c_digit;
    int oddLengthChecksum{0};
    int evenLengthChecksum{0};
    int checksum{0};
    int position{1};
    cout << "Enter a number: ";
    c_digit = cin.get();
    while (c_digit != 10) {
        if (position%2 == 0) {
            oddLengthChecksum += doubleDigitValue(c_digit - '0');
            evenLengthChecksum += c_digit - '0';
        }
        else {
            oddLengthChecksum += c_digit - '0';
            evenLengthChecksum += doubleDigitValue(c_digit - '0');
        }
        c_digit = cin.get();
        position++;
    }
    if ((position-1)%2 == 0) checksum = evenLengthChecksum;
    else checksum = oddLengthChecksum;
    
    cout << "Checksum: " << checksum << ". \n";
    if (checksum%10 == 0)
        cout << "Checksum is divisible by 10. VALID\n";
    else
        cout << "Checksum is NOT divisible by 10. INVALID\n";
}

