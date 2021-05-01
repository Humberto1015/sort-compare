#include "sortingAlgorithms.h"

int main() {
    vector<int> dataSize = {10, 100, 1000, 10000, 100000};
    for (auto size: dataSize) {
        cout << "Data size = " << size << "\n";
        SortComp sc(size);
        vector<double> times;
        times.push_back(sc.runBubbleSort());
        times.push_back(sc.runInsertionSort());
        times.push_back(sc.runSelectionSort());
        times.push_back(sc.runQuickSort());
        times.push_back(sc.runMergeSort());
        times.push_back(sc.runHeapSort());

        for (int i = 0; i < times.size(); ++i)
            cout << times[i] << " ";
        cout << "\n";
    }
    return 0;
}