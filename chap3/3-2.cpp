#include <iostream>
using std::cout;

double find_average(int array[], int ARRAY_SIZE) {
    double sum = 0;
    for (int i=0; i<ARRAY_SIZE; i++)
        sum += array[i];
    return sum/ARRAY_SIZE;
}

double find_median(int array[], int ARRAY_SIZE) {
    if (ARRAY_SIZE%2 == 0) {
        int mid_right = ARRAY_SIZE/2;
        int mid_left = mid_right-1;
        return ((array[mid_left]+array[mid_right])/2);
    } else {
        int mid = ARRAY_SIZE/2;
        return array[mid];
    }
}

int compare(const void* A, const void* B) {
    int* pA = (int*) A;
    int* pB = (int*) B;
    return *pA - *pB;
}

template<typename T, int ROWS, int COLUMNS>
void printMultiArray(T (&the_array)[ROWS][COLUMNS]) {
    for (int agent=0; agent<ROWS; agent++) {
        cout << "Agent " << agent+1 << ": ";
        for (int month=0; month<COLUMNS; month++) {
            cout << the_array[agent][month] << ' ';
        }
        cout << "\n";
    }
}

int main() {
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32}, 
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    int highest_sales = sales[0][0];
    for (int agent=0; agent<NUM_AGENTS; agent++) {
        for (int month=0; month<NUM_MONTHS; month++) {
            if (sales[agent][month] > highest_sales)
                highest_sales = sales[agent][month];
        }
    }
    cout << "highest sales: " << highest_sales << "\n";

    double highest_average = find_average(sales[0], NUM_MONTHS);
    for (int i=1; i<NUM_AGENTS; i++) {
        double average_agent = find_average(sales[i], NUM_MONTHS);
        if (average_agent > highest_average) {
            highest_average = average_agent;
        } 
    }
    cout << "highest average sales: " << highest_average << "\n";

    cout << "Sales\n";
    printMultiArray(sales);

    for (int agent=0; agent<NUM_AGENTS; agent++) {
        qsort(sales[agent], NUM_MONTHS, sizeof(int), compare);
    }
    cout << "sorted Sales\n";
    printMultiArray(sales);

    double highest_median = find_median(sales[0], NUM_MONTHS);
    for (int agent=1; agent<NUM_AGENTS; agent++) {
        double median_agent = find_median(sales[agent], NUM_MONTHS);
        if (median_agent > highest_median) {
            highest_median = median_agent;
        }
    }
    cout << "highest median: " << highest_median << "\n";
}