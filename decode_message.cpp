#include <iostream>
using std::cout;
using std::cin;

int main() {
    char c_output;
    enum modeType {UPPER,LOWER,PUNC};
    modeType mode = UPPER;

    char c_digit;
    do {
        c_digit = cin.get();
        int number = (c_digit - '0');
        c_digit = cin.get();
        while ((c_digit != 10) && (c_digit != ',')) {
            number = number * 10 + (c_digit - '0');
            c_digit = cin.get();
        }
        switch (mode) {
            case UPPER:
                number = number % 27;
                c_output = number + 'A' - 1;
                if (number == 0) {
                    mode = LOWER;
                    continue;
                }
                break;

            case LOWER:
                number = number % 27;
                c_output = number + 'a' - 1;
                if (number == 0) {
                    mode = PUNC;
                    continue;
                }
                break;

            case PUNC:
                number = number % 9;
                switch (number) {
                    case 1: c_output = '!'; break;
                    case 2: c_output = '?'; break;
                    case 3: c_output = ','; break;
                    case 4: c_output = '.'; break;
                    case 5: c_output = ' '; break;
                    case 6: c_output = ';'; break;
                    case 7: c_output = '"'; break;
                    case 8: c_output = '\\'; break;
                }
                if (number == 0) {
                    mode = UPPER;
                    continue;
                }
                break;
        }
        cout << c_output;
    } while (c_digit != 10);
    cout << "\n";
}