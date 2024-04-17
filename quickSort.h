//
// Created by grons on 29.03.2024.
//

#ifndef PROJEKT_AIZO_QUICKSORT_H
#define PROJEKT_AIZO_QUICKSORT_H
#include <iostream>
#include <random>
#include <stack>


/*template<typename T>
int partition(T arr[], int left, int right, int whichPivot){
    T pivot;
    std::cout<<"part"<<std::endl;
    if (whichPivot==0){
        pivot = arr[left];
        std::cout<<"part2"<<std::endl;
    }else if(whichPivot ==1){
        pivot = arr[right];
    }else if(whichPivot == 2){
        pivot == arr[(left+right)/2];
    }else{
        std::random_device r;
        std::default_random_engine e1(r());
        std::uniform_int_distribution<int> uniformDist(left,right);
        pivot = arr[ uniformDist(e1)];
    }
    std::cout<<"part3"<<std::endl;
    int l = left;
    int r = right;
    while(true){
        while(arr[l] < pivot) l++;
        while(arr[r] > pivot) r--;
        if(l<r){
            std::cout<<"part4"<<std::endl;
            std::swap(arr[l], arr[r]);
            std::cout<<"part5"<<std::endl;
            l++;
            r--;

        }else{
            if(r=right) r--;
            std::cout<<"part6"<<std::endl;
            return r;
        }
    }

}

*//*template<typename T>
void quickSort(T arr[], int l, int p, int pivot){
    if(l>=p) return;

    std::cout<<"guicksort"<<std::endl;
    int m = partition(arr, l, p,pivot);
    quickSort(arr, l, m,pivot);
    quickSort(arr, m + 1, l,pivot);

}*//*

template<typename T>
void quickSortLeft(T* arr,int l,int r){
    if (l>=r) return;
    std::stack<std::pair<int, int>> stack;
    stack.push({l, r});

    while (!stack.empty()) {
        auto range = stack.top();
        stack.pop();

        int low = l;
        int high = r;

        if (low < high) {
            int index = partition(arr, low, high, low);
            stack.push({low, index - 1});
            stack.push({index + 1, high});
        }
    }

}
template<typename T>
long long quickSort1(T arr[], int l, int p, int pivot){
    auto start = std::chrono::high_resolution_clock::now();
    std::cout<<"guicksort1"<<std::endl;
    quickSort(arr,l,p,pivot); //nie działa
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}*/

#include "QuickSort.h"
#include <ctime>
#include <iostream>
#include <chrono>
#include <random>
#include <stack>


template<typename T>
T partition(T *arr, int left, int right, int pivot) {

    if(right != pivot){
        T temp = arr[right];
        arr[right] = arr[pivot];
        arr[pivot] = temp;

    }
    T p = arr[right];
    int j = left;
    for (int i = left; i < right; i++){
        if(arr[i] <= p){
            T temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;
        }
    }
    T temp = arr[j];
    arr[j] = arr[right];
    arr[right] = temp;
    return j;
}

template<typename T>
void sortLeft(T *arr, int size) {
    if (size <= 1) return;

    std::stack<std::pair<int, int>> stack;
    stack.push({0, size - 1});


    while (!stack.empty()) {
        auto range = stack.top();
        stack.pop();

        int low = range.first;
        int high = range.second;

        if (low < high) {

            T pivot_index = partition(arr, low, high, low);
            stack.push({low, pivot_index - 1});
            stack.push({pivot_index + 1, high});
        }
    }
}

template<typename T>
void sortRight(T *arr, int size) {
    if (size <= 1) return;

    std::stack<std::pair<int, int>> stack;
    stack.push({0, size - 1});

    while (!stack.empty()) {
        auto range = stack.top();
        stack.pop();

        int low = range.first;
        int high = range.second;

        if (low < high) {
            T pivot_index = partition(arr, low, high, high);
            stack.push({low, pivot_index - 1});
            stack.push({pivot_index + 1, high});
        }
    }
}

template<typename T>
void sortMiddle(T *arr, int size) {
    if (size <= 1) return;

    std::stack<std::pair<int, int>> stack;
    stack.push({0, size - 1});

    while (!stack.empty()) {
        auto range = stack.top();
        stack.pop();

        int low = range.first;
        int high = range.second;

        if (low < high) {
            T pivot_index = partition(arr, low, high, ((high-low)/2 + low));
            stack.push({low, pivot_index - 1});
            stack.push({pivot_index + 1, high});
        }
    }
}
template<typename T>
void sortRandom(T *arr, int size) {
    if (size <= 1) return;

    std::stack<std::pair<int, int>> stack;
    stack.push({0, size - 1});

    while (!stack.empty()) {
        auto range = stack.top();
        stack.pop();

        int low = range.first;
        int high = range.second;

        std::mt19937 rng;
        rng.seed(std::chrono::system_clock::now().time_since_epoch().count());

        std::uniform_int_distribution<int> distribution(low, high);
        int random = distribution(rng);

        if (low < high) {
            T pivot_index = partition(arr, low, high, random);
            stack.push({low, pivot_index - 1});
            stack.push({pivot_index + 1, high});
        }
    }
}

template<typename T>
long long quickSort(T *arr,int size, int type) {
    auto start = std::chrono::high_resolution_clock::now();
    switch (type){
        case 0:
            sortLeft(arr, size);
            break;
        case 1:
            sortRight(arr, size);
            break;
        case 2:
            sortMiddle(arr, size);
            break;
        case 3:
            sortRandom(arr, size);
            break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

#endif //PROJEKT_AIZO_QUICKSORT_H
