#include <iostream>
using std::cout;

int compareFunc(const void* fA, const void* fB) {
    int* a = (int*)fA;
    int* b = (int*)fB;
    return *a - *b;
}

int main() {
    const int ARRAY_SIZE = 12;
    int data[ARRAY_SIZE] = {4,7,3,8,9,7,3,9,9,3,3,10};

    /* sorted array */
    // qsort(data, ARRAY_SIZE, sizeof(int), compareFunc);
    // for (auto i : data) cout << i << " ";

    // int most_freq{0};
    // int highest_freq{0};
    // int current_freq{0};
    // for (int i=0; i<ARRAY_SIZE; i++) {
    //     current_freq++;
    //     if (i == ARRAY_SIZE-1 || data[i] != data[i+1]) {
    //         if (current_freq > highest_freq) {
    //             highest_freq = current_freq;
    //             most_freq = data[i];
    //         }
    //         current_freq = 0;
    //     }
    // }
    // cout << "\nHighest Frequency: " << highest_freq << "\n";
    // cout << "Most Frequency: " << most_freq;

    /* HISTOGRAM */
    const int MAX_RESPONSE = 10;
    int histogram[10] {0};

    for (int i=0; i<ARRAY_SIZE; i++) {
        histogram[data[i]-1]++;
    }

    int most_freq = 0;
    for (int i=0; i<MAX_RESPONSE; i++) {
        if (histogram[i] > histogram[most_freq]) most_freq = i;
    }
    most_freq++;
}