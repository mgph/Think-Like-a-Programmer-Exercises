#include <iostream>
using std::cout;

int main() {
    for (int j{5}; j>0; j--) {
        for (int i{j}; i>0; i--) {
            cout << "#";
        }
        cout << "\n";
    }
    
}