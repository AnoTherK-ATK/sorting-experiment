#ifndef __INTROSORT_H__
#define __INTROSORT_H__
template<typename T>
int Partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
// Function to perform insertion sort on a subarray
template<typename T>
void InsertionSort(T arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        T key = arr[i];
        int j = i - 1;
 
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
 
        arr[j + 1] = key;
    }
}
 
// Function to find the median of three elements
template<typename T>
T MedianOfThree(T arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low])
        std::swap(arr[low], arr[mid]);
    if (arr[high] < arr[low])
        std::swap(arr[low], arr[high]);
    if (arr[high] < arr[mid])
        std::swap(arr[mid], arr[high]);
    return arr[mid];
}

template<typename T>
void heapSort(T arr[], int low, int high){
    std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
    for(int i = low; i <= high; ++i){
        pq.push(arr[i]);
    }
    for(int i = low; i <= high; ++i){
        arr[i] = pq.top();
        pq.pop();
    }
}
 
// Function to perform quicksort
template<typename T>
void QuickSort(T arr[], int low, int high, int depthLimit) {
    while (low < high) {
        if (depthLimit == 0) {
            // If the recursion depth limit is reached, switch to heapsort
            heapSort(arr, low, high);
            return;
        }
 
        if (high - low < 16) {
            // If the subarray size is small, switch to insertion sort
            InsertionSort(arr, low, high);
            return;
        }
 
        T pivot = MedianOfThree(arr, low, high);
        int pivotIndex = Partition(arr, low, high);
 
        // Recursive calls on smaller subarrays
        QuickSort(arr, low, pivotIndex - 1, depthLimit - 1);
        low = pivotIndex + 1;
    }
}
 
// Function to perform introsort
template<typename T>
void sort(T arr[], int size) {
    int depthLimit = 2 * log(size);
 
    QuickSort(arr, 0, size - 1, depthLimit);
}
#endif