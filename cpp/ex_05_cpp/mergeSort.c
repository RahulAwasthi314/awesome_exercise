// Merge Sort definition

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

    while (i < l && j < m) {
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

void mergeSort(double* arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}