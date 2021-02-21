#include <iostream>
using std::cout;

int main() {
    int arr[10]{1,3,5,2,8,9,6,4,7,0};
    int start{0};
    for (int i{start+1}; i<=9; i++) {
        for (int j{i}; j>start && arr[j-1]>arr[j]; j--) {
            int tmp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = tmp;
        }
    }
    for (auto i : arr) cout << i << " ";
}