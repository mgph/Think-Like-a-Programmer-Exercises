#include <iostream>
using std::cout;

int main() {
    for (int row{1}; row<=4; row++) {
        for (int outer_space{1}; outer_space<row; outer_space++) {
            cout << " ";
        }
        for (int hash{1}; hash<=row; hash++) {
            cout << "#";
        }
        for (int inner_space{1}; inner_space<=12-(4*(row-1)); inner_space++) {
                cout << ' ';
            }
        for (int hash{1}; hash<=row; hash++) {
            cout << "#";
        }
        cout << "\n";
    }

    for (int row{4}; row>0; row--) {
        for (int outer_space{1}; outer_space<row; outer_space++) {
            cout << " ";
        }
        for (int hash{1}; hash<=row; hash++) {
            cout << "#";
        }
        for (int inner_space{1}; inner_space<=12-(4*(row-1)); inner_space++) {
                cout << ' ';
            }
        for (int hash{1}; hash<=row; hash++) {
            cout << "#";
        }
        cout << "\n";
    }
}