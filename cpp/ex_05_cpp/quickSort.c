/*
 * Quick Sort
// Time Complexity: O(n log n) {avg case}
 */

// partition logic
// Time Complexity : O(n)
int partition(double* arr, int p, int r) {
    int i = p - 1;
    double x = arr[r];
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            swap(arr, ++i, j);
        }
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