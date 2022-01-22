#include <iostream>
#include <iomanip>

#define RAND_LIMIT 100
#define MAX_VALUE 1000

using namespace std;


// exercise 3:
// objective: implement minimum, maximum and average functions.

double min(const double*);
double max(const double*);
double avg(const double*);


int main () {
    double arr[1000] = {0};
    // assigning the random values to array 
    for (int i = 0; i < MAX_VALUE; i++) {
        arr[i] = rand() % RAND_LIMIT;
    }

    // min function
    double res = min(arr);
    cout << "Minimum value in the array is: " << res << endl;

    // max function
    res = max(arr);
    cout << "Maximum value in the array is: " << res << endl;

    // avg function
    res = avg(arr);
    cout << "Average value in the array is: " << res << endl;

    return 0;
}


double min(const double* nums) {
    double min = *nums;
    for (int i = 1; i < MAX_VALUE; i++) {
        if (min > *(nums + i)) {
            min = *(nums + i);
        }
    }
    return min;
}

double max(const double* nums) {
    double max = *nums;
    for (int i = 1; i < MAX_VALUE; i++) {
        if (max < *(nums + i)) {
            max = *(nums + i);
        }
    }
    return max;
}

double avg(const double* nums) {
    double sum = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        sum += *(nums + i);
    }
    return sum / MAX_VALUE;
}