#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include <bits/stdc++.h>

std::mt19937 rd(std::chrono::steady_clock::now().time_since_epoch().count());

//hàm sinh số ngẫu nhiên
int Rand(int l, int h) {
    return l + (rd() >> 1) * 1LL * (rd() >> 1) % (h - l + 1); 
}

template <typename T>
void sort(T arr[] , int left, int right){
    int pivot = arr[Rand(left, right)]; //ngẫu nhiên chọn pivot
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