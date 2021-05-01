# Comparisons of Sorting Algorithms
## Algorithms
- Bubble sort
- Insertion sort
- Selection sort
- Quick sort
- Merge sort
- Heap sort
## Comparison Result

After applying sorting algorithms on different sizes of data, we have the following table. The cost time is in seconds.

| Algorithm |  10 samples   |  100 samples   |  1000 samples   |  10000 samples   | 100000 samples |
| --------- | --- | --- | --- | --- | --------- |
| Bubble Sort|0.000001021|0.000080346|0.00683811|0.731437|70.5418|
| Insertion Sort|0.000000824|0.000046901|0.00469361|0.440733|44.146|
| Selection Sort|0.000000811|0.000027316|0.00194979|0.188101|18.9768|
| Quick Sort|0.000000743|0.000010898|0.000150127|0.00201223|0.0242033|
| Merge Sort|0.000018431|0.000105988|0.00118194|0.0139549|0.152184|
| Heap Sort|0.000005781|0.000045861|0.000537181|0.0068288|0.0800461|

## Usage
Take bubble sort as an example, if you want to get the cost time of sorting 1000 samples, try the following code.
```=c++
#include "sortingAlgorithms.h"

int main() {
    SortComp sc(1000);
    double costTime = sc.runBubbleSort();
    return 0;
}
```

