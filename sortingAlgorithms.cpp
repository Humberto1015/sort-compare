#include "sortingAlgorithms.h"

// [done]
void SortComp::initData(int dataSize) {
    random_device rd;
    default_random_engine gen = default_random_engine(rd());
    uniform_int_distribution<int> dis(-5000,5000);

    data.resize(dataSize);
    for (int i = 0; i < dataSize; ++i)
        data[i] = dis(gen);
}
// [done]
void SortComp::swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// [done]
double SortComp::runBubbleSort() {
    vector<int> array(data.begin(), data.end());
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < array.size() - 1; ++i) {
		bool changed = false;
		for (int j = 0; j < array.size() - 1 - i; ++j) {
            if (array[j] > array[j + 1]) {
				swap(array, j, j + 1);
				changed = true;
			}
		}
		if (!changed) break;
	}
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    return elapsed.count();
}
// [done]
double SortComp::runInsertionSort() {
    vector<int> array(data.begin(), data.end());
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < array.size(); ++i) {
		for (int j = i; j > 0; --j) {
			if (array[j] < array[j - 1])
				swap(array, j, j - 1);
		}
	}
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    return elapsed.count();
}
// [done]
double SortComp::runSelectionSort() {
    vector<int> array(data.begin(), data.end());
    auto start = std::chrono::high_resolution_clock::now();
    int sorted = -1;
	for (int i = 0; i < array.size(); ++i) {
        // choose the min value and place it to the sorted area
		int minVal = INT_MAX;
		int minIndex;
		for (int j = sorted + 1; j < array.size(); ++j) {
			if (array[j] < minVal) {
				minVal = array[j];
				minIndex = j;
			}
		}
		swap(array, ++sorted, minIndex);
	}
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    return elapsed.count();
}
// [done]
int SortComp::partition(vector<int>& arr, int l, int r, int pivot) {
    int pivotVal = arr[pivot];
    swap(arr, pivot, r);
    int sorted = l;
    for (int i = l; i < r; ++i)
        if (arr[i] < pivotVal) swap(arr, i, sorted++);
    swap(arr, sorted, r);
    return sorted;
}
// [done]
void SortComp::quickSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int pivot = l + (r - l) / 2;
        int m = partition(arr, l, r, pivot);
        quickSort(arr, l, m - 1);
        quickSort(arr, m + 1, r);
    }
}
// [done]
double SortComp::runQuickSort() {
    vector<int> array(data.begin(), data.end());
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(array, 0, array.size() - 1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    return elapsed.count();
}
// [done]
void SortComp::merge(vector<int>& arr, int l, int m, int r) {
    // step 1. copy the original array to two temp arrays
	int p, q;
	p = q = 0;
	vector<int> temp_p(arr.begin() + l, arr.begin() + m + 1);
	vector<int> temp_q(arr.begin() + m + 1, arr.begin() + r + 1);
	// step 2. merge two lists
	int sorted = l;
	while (p < m - l + 1 && q < r - m)
		arr[sorted++] = temp_p[p] < temp_q[q] ? temp_p[p++] : temp_q[q++];
	while (p < m - l + 1)
		arr[sorted++] = temp_p[p++];
	while (q < r - m)
		arr[sorted++] = temp_q[q++];
}
// [done]
void SortComp::mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// [done]
double SortComp::runMergeSort() {
    vector<int> array(data.begin(), data.end());
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(array, 0, array.size() - 1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    return elapsed.count();
}
// [done]
double SortComp::runHeapSort() {
    vector<int> array(data.begin(), data.end());
    auto start = std::chrono::high_resolution_clock::now();
    // step 1. build max heap
    priority_queue<int> maxHeap;
    for (int i = 0; i < array.size(); ++i)
        maxHeap.push(array[i]);
    // step 2. perform sorting policy
    int sorted = array.size() - 1;
    while (!maxHeap.empty()) {
        array[sorted--] = maxHeap.top();
        maxHeap.pop();
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    return elapsed.count();
}