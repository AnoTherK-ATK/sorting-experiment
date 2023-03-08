#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

#include <bits/stdc++.h>

template <typename T>
void sort(T arr[], int N){ //ta cần độ dài của mảng
    std::priority_queue< T, std::vector<T>, std::greater<T> > pq; 
    //khai báo cấu trúc là giá trị nhỏ hơn sẽ nằm ở phía bên trái
    for(int i = 0; i < N; ++i)
        pq.push(arr[i]); //cho các phần tử của mảng vào priority queue
    for(int i = 0; i < N; ++i){
        arr[i] = pq.top(); //trả các phần tử đã sắp xếp trong priority queue ngược lại mảng
        pq.pop(); //xoá phần tử đã trả khỏi priority queue
    }
}

#endif