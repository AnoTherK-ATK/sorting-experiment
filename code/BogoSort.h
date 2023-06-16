#ifndef __BOGOSORT_H__
#define __BOGOSORT_H__

#include <algorithm>

template <typename T>
void sort(T arr[], int N){
    while(!std::is_sorted(arr, arr + N)){
        std::random_shuffle(arr, arr + N);
    }
}
#endif