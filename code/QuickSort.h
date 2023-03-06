#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include <bits/stdc++.h>

std::mt19937 rd(std::chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

template <typename T>
void sort(T arr[] , int left, int right){
    int pivot = arr[Rand(left, right)];
    int l = left;
    int r = right;
    do{
        while((l <= right) && (arr[l] < pivot))
            ++l;
        while((r >= left) && (arr[r] > pivot))
            --r;
        if(l > r) 
            break;
        std::swap(arr[l], arr[r]);
        ++l, --r;
    }while(l <= r);
    if(left < r)
        sort(arr, left, r);
    if(l < right)
        sort(arr, l, right);
}

#endif