#include <iostream>
using std::cout;

int main() {
    for (int j{1}; j<=7; j++) {
        for (int i{1}; i<=4-abs(4-j); i++) {
            cout << "#";
        }
        cout << "\n";
    }
    
}