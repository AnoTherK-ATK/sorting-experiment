#include <bits/stdc++.h>


namespace quicksort{
    #include "QuickSort.h"
}

namespace mergesort{
    #include "MergeSort.h"
}

signed main(){
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; ++i){
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
    //quicksort::sort(arr, 0, 4);
    mergesort::sort(arr, 0, 4);
    for(int i = 0; i < 5; ++i){
        std::cout << arr[i] << ' ';
    }
    return 0;
}