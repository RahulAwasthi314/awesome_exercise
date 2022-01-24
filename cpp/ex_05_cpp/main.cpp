#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

#define RAND_LIMIT 100
#define MAX_VALUE 1000

#include "helper.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "heapSort.h"

// exercise 5:
// objective: separate functions into header files

int main () {
    srand(time(NULL));
    double arr[MAX_VALUE] = {0};
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

    heapSort(arr, MAX_VALUE);
    // quickSort(arr, 0, MAX_VALUE-1);
    // mergeSort(arr, 0, MAX_VALUE-1);


    for (int i = 0; i < 1000; i++) {
        if (i % 10 == 0) {
            cout << endl;
            cout << setw(4) << i + 10 << setfill(' ') << "   ";
        }
        cout << setw(2) << arr[i] << setfill(' ') << " ";
    }
    cout << endl;
    return 0;
}