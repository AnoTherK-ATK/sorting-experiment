#include <bits/stdc++.h>


namespace quicksort{
    #include "QuickSort.h"
}

namespace mergesort{
    #include "MergeSort.h"
}

namespace heapsort{
    #include "HeapSort.h"
}

signed main(){
    int arr[5] = {5, 4, 3, 2, 1};
    for(int i = 0; i < 5; ++i){
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
    //quicksort::sort(arr, 0, 4);
    //mergesort::sort(arr, 0, 4);
    heapsort::sort(arr, 5);
    for(int i = 0; i < 5; ++i){
        std::cout << arr[i] << ' ';
    }
    return 0;
}