#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <chrono>

using namespace std;

class SortComp {
public:
    SortComp(int dataSize) {
        initData(dataSize);
    }
    double runBubbleSort();
    double runInsertionSort();
    double runSelectionSort();
    double runQuickSort();
    double runMergeSort();
    double runHeapSort();
private:
    vector<int> data;
    void initData(int);
    void swap(vector<int>&, int, int);
    int partition(vector<int>&, int, int, int);
    void quickSort(vector<int>&, int, int);
    void merge(vector<int>&, int, int, int);
    void mergeSort(vector<int>&, int, int);
};