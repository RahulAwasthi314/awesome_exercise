#include <iostream>
#include <iomanip>
#include <ctime>

#define RAND_LIMIT 100
#define MAX_VALUE 10

using namespace std;


// exercise 4:
// objective: implement sorting algorithms.

double min(const double*);
double max(const double*);
double avg(const double*);

void mergeSort(double*, int, int);
void merge(double*, int, int, int);


int main () {
    srand(time(NULL));
    double arr[10] = {0};
    // assigning the random values to array 
    for (int i = 0; i < MAX_VALUE; i++) {
        arr[i] = rand() % RAND_LIMIT;
    }

    cout << "Random array is: ";
    for (int i = 0; i < MAX_VALUE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // min function
    double res = min(arr);
    cout << "Minimum value in the array is: " << res << endl;

    // max function
    res = max(arr);
    cout << "Maximum value in the array is: " << res << endl;

    // avg function
    res = avg(arr);
    cout << "Average value in the array is: " << res << endl;


    mergeSort(arr, 0, MAX_VALUE - 1);

    cout << "Sorted array is: ";
    for (int i = 0; i < MAX_VALUE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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

/*
 * mergeSort algorithm Implementation
 * Time Complexity : O(n log n) Space: O(log n)
 */

void mergeSort(double* arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

void merge(double* arr, int p, int q, int r) {
    int l = q - p + 1, m = r - q;
    double a[l], b[m];

    int i = 0, j = 0;
    while (i < l) {
        a[i] = arr[p + i];
        i++;
    }
    while (j < m) {
        b[j] = arr[q + 1 + j];
        j++;
    }

    i = 0; j = 0;
    // it must be initialized to first index of the array
    int k = p;

    while (i < l and j < m) {
        if (a[i] < b[j]) arr[k++] = a[i++];
        // do not forget else after if, it can cause hrs of debugging.
        else arr[k++] = b[j++];
    }
    while (i < l) {
        arr[k++] = a[i++];
    }
    while (j < m) {
        arr[k++] = b[j++];
    }
}
