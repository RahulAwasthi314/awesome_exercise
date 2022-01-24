// heap sort
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
		swap(arr, i, largest);

		maxHeapify(arr, n, largest);
	}
}

void heapSort(double* arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		maxHeapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr, 0, i);
		maxHeapify(arr, i, 0);
	}
}