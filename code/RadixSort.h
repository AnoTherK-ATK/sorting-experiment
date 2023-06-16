#ifndef __RADIXSORT_H__
#define __RADIXSORT_H__
template <typename T>
void sort(T arr[], int N){
    T *sorted = new T[N + 7];
    int *cnt = new int[256];
    int *pos = new int[256];
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 256; ++j){
            cnt[j] = 0;
        }
        for(int j = 0; j < N; ++j){
            ++cnt[(arr[j] >> (i * 8)) & 255];
        }
        pos[0] = 0;
        for(int j = 1; j < 256; ++j){
            pos[j] = pos[j - 1] + cnt[j - 1];
        }
        for(int j = 0; j < N; ++j){
            sorted[pos[(arr[j] >> (i * 8)) & 255]++] = arr[j];
        }
        for(int j = 0; j < N; ++j){
            arr[j] = sorted[j];
        }
    }
    delete(sorted);
    delete(cnt);
    delete(pos);
}
#endif