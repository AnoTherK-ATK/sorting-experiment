#ifndef __INSERTIONSORT_H__
#define __INSERTIONSORT_H__
template <typename T>
void sort(T arr[], int N){
    for(int i = 1; i < N; ++i){
        T key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
#endif