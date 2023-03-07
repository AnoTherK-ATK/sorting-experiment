#include <bits/stdc++.h>


namespace quicksort{
    #include "QuickSort.h"
}

namespace mergesort{
    #include "MergeSort.h"
}

namespace heapsort{
    #include "HeapSort.h"
}

template <typename F> 
void benchmark(F func, double arr[], int N,const std::string& name){
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;

    auto t1 = high_resolution_clock::now(); //thời gian trước khi thực hiện thuật toán
    if(name == "Quicksort")
        func(arr, 0, N - 1);
    else if(name == "Mergesort")
        func(arr, 0, N - 1);
    else if(name == "Heapsort")
        func(arr, N);
    else
        func(arr, arr + N);
    auto t2 = high_resolution_clock::now(); //thời gian sau khi thực hiện thuật toán

    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << name << "\t\t:" << ms_double << '\n';
}

template <typename T>
void startbench(T arr[], int N){
    benchmark(quicksort::sort(), arr, N, "Quicksort");
    benchmark(mergesort::sort(), arr, N, "Mergesort");
    benchmark(heapsort::sort(), arr, N, "Heapsort");
    benchmark(std::sort(), arr, N, "std::sort()");
    
}

double arr[1'000'000];

void input(const std::string& file){
    std::ifstream in(file);
    for(int i = 0; i < 1000000; ++i){
        in >> arr[i];
    }
}

signed main(){
    
    //test 1: increasing
    input("1-increasing.txt");
    std::cout << "test 1:\n"; 
    startbench(arr, 1'000'000);

    //test 2: decreasing
    input("2-decreasing.txt");
    std::cout << "test 2:\n";
    startbench(arr, 1'000'000);

    //test 3 - 10: random
    for(int i = 3; i <= 10; ++i){
        std::string suffix = "-random.txt";
        std::string file = std::to_string(i) + suffix;
        input(file);
        std::cout << "test " << i << ":\n";
        startbench(arr, 1'000'000);
    }
    return 0;
}