#include <iostream>
#include <iomanip>
#include <ctime>

#define RAND_LIMIT 100
#define MAX_VALUE 1000

using namespace std;


// exercise 4:
// objective: implement sorting algorithms.

double min(const double*);
double max(const double*);
double avg(const double*);

void mergeSort(double*, int, int);
void merge(double*, int, int, int);

void swap(double*, int, int);
int partition(double*, int, int);
void quickSort(double*, int, int);


void maxHeapify(double*, int, int);
void heapSort(double*, int);


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
    // quickSort(arr, 0, MAX_VALUE);
    // mergeSort(arr, 0, MAX_VALUE);

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

/**
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

/**
 * Quick Sort
// Time Complexity: O(n log n) {avg case}
 */

void swap(double* arr, int i, int j) {
    double t = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = t;
}

// partition logic
// Time Complexity : O(n)
int partition(double* arr, int p, int r) {
    int i = p - 1;
    double x = arr[r];
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) swap(arr, ++i, j);
    }
    swap(arr, i+1, r);
    return i+1;
}

// quickSort 
// Time Complexity: O(log n)
void quickSort(double* arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

/**
 * Heap Sort
 * Time Complexity: O(n log n)
 */

// maxHeapify
//  Time Complexity: O(log n)
void maxHeapify(double* arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);

		maxHeapify(arr, n, largest);
	}
}

// Time Complexity : O(n/2) * O(log n) + O(n) * O(log n) = O(n log n)
void heapSort(double* arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		maxHeapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		maxHeapify(arr, i, 0);
	}
}