#include <iostream>
using std::cout;

int main() {
    for (int row{1}; row<=4; row++) {
        for (int space{1}; space<=4-(row); space++) {
            cout << " ";
        }
        for (int hash{1}; hash<=row*2; hash++) {
            cout << "#";
        }
        cout << "\n";
    }
    
    for (int row{4}; row>0; row--) {
        for (int space{1}; space<=4-(row); space++) {
            cout << " ";
        }
        for (int hash{1}; hash<=row*2; hash++) {
            cout << "#";
        }
        cout << "\n";
    }
}