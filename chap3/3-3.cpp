#include <iostream>

bool is_sorted(int array[], int ARRAY_SIZE) {
    for (int i=0; i<ARRAY_SIZE-1; i++) {
        if (array[i+1] < array[i])
            return false;
    }
    return true;
}

int main() {
    int a[] {1,2,1,4,5};
    std::cout << is_sorted(a, 5);
}