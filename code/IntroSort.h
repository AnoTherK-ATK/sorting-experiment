#ifndef __INTROSORT_H__
#define __INTROSORT_H__
template <typename T>
void introsort(T arr[], int N){
    int maxdepth = 2 * log2(N);
    std::function<void(T[], int, int, int)> quicksort = [&](T arr[], int l, int r, int depth){
        if(l >= r) return;
        if(depth == 0){
            std::sort(arr + l, arr + r + 1);
            return;
        }
        int i = l, j = r;
        T pivot = arr[(l + r) >> 1];
        while(i <= j){
            while(arr[i] < pivot) ++i;
            while(arr[j] > pivot) --j;
            if(i <= j){
                std::swap(arr[i], arr[j]);
                ++i;
                --j;
            }
        }
        if(l < j) quicksort(arr, l, j, depth - 1);
        if(i < r) quicksort(arr, i, r, depth - 1);
    };
    quicksort(arr, 0, N - 1, maxdepth);
}
#endif