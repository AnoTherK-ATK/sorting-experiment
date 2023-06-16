#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include <bits/stdc++.h>

int medianOfThree(int a, int b, int c){
    if(a > b) std::swap(a, b);
    if(a > c) std::swap(a, c);
    if(b > c) std::swap(b, c);
    return b;
}

template <typename T>
void sort(T arr[] , int left, int right){
    T pivot = arr[medianOfThree(left, right, (left + right) >> 1)]; //ngẫu nhiên chọn pivot
    int l = left;
    int r = right;
    do{
        while((l <= right) && (arr[l] < pivot)) //bỏ qua các phần tử nhỏ hơn pivot và nằm bên trái
            ++l;
        while((r >= left) && (arr[r] > pivot)) //bỏ qua các phần tử lớn hơn pivot và nằm bên phải
            --r;
        if(l > r) //nếu như chạy quá pivot, thoát
            break;
        std::swap(arr[l], arr[r]); //thay đổi vị trí 2 phần tử nằm khác bên của pivot
        ++l, --r; //tiếp tục
    } while(l <= r);
    //chia thành các nửa để sắp xếp
    if(left < r) 
        sort(arr, left, r);
    if(l < right)
        sort(arr, l, right);
}

#endif