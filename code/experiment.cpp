#include <bits/stdc++.h>
#include <chrono>
// using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;

namespace quicksort{
    #include "QuickSort.h"
}

namespace mergesort{
    #include "MergeSort.h"
}

namespace heapsort{
    #include "HeapSort.h"
}


template <typename T> 
void benchmark(T arr[], int N, const std::string& name){
    auto t1 = high_resolution_clock::now(); //thời gian trước khi thực hiện thuật toán
    if(name == "Quicksort")
        quicksort::sort(arr, 0, N - 1);
    else if(name == "Mergesort")
        mergesort::sort(arr, 0, N - 1);
    else if(name == "Heapsort")
        heapsort::sort(arr, N);
    else
        std::sort(arr, arr + N);
    auto t2 = high_resolution_clock::now(); //thời gian sau khi thực hiện thuật toán

    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << name << "\t\t: " << ms_double.count() << "ms\n";
}

template <typename T>
void init(T arr[], T ans[],int N){
    for(int i = 0; i < N; ++i) {
        ans[i] = arr[i];
    }
}

template <typename T>
void startbench(T arr[], int N){
    T *array = new T[N + 7]; 
    init<T>(arr, array, N);
    benchmark<T>(array, N, "Quicksort");
    init<T>(arr, array, N);
    benchmark<T>(array, N, "Mergesort");
    init<T>(arr, array, N);
    benchmark<T>(array, N, "Heapsort");
    init<T>(arr, array, N);
    benchmark<T>(array, N, "std::sort()");
    delete(array);
}

double arr[1'000'000];

void input(const std::string& file){
    std::ifstream in("../tests\\" + file);
    for(int i = 0; i < 1000000; ++i){
        in >> arr[i];
    }
}

signed main(){
    //test 1: increasing
    input("1-increasing.txt");
    std::cout << "test 1:\n"; 
    startbench<double>(arr, 1'000'000);

    //test 2: decreasing
    input("2-decreasing.txt");
    std::cout << "test 2:\n";
    startbench<double>(arr, 1'000'000);

    //test 3 - 10: random
    for(int i = 3; i <= 10; ++i){
        std::string suffix = "-random.txt";
        std::string file = std::to_string(i) + suffix;
        input(file);
        std::cout << "test " << i << ":\n";
        startbench<double>(arr, 1'000'000);
    }
    return 0;
}