//
// Created by grons on 29.03.2024.
//

#ifndef PROJEKT_AIZO_QUICKSORT_H
#define PROJEKT_AIZO_QUICKSORT_H
#include <iostream>
#include <random>
#include <stack>


template<typename T>
int partition(T arr[], int left, int right, int whichPivot){
    int pivot;
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

template<typename T>
void quickSort(T arr[], int l, int p, int pivot){
    if(l>=p) return;

    std::cout<<"guicksort"<<std::endl;
    int m = partition(arr, l, p,pivot);
    quickSort(arr, l, m,pivot);
    quickSort(arr, m + 1, l,pivot);

}
template<typename T>
long long quickSort1(T arr[], int l, int p, int pivot){
    auto start = std::chrono::high_resolution_clock::now();
    std::cout<<"guicksort1"<<std::endl;
    quickSort(arr,l,p,pivot); //nie działa
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

#endif //PROJEKT_AIZO_QUICKSORT_H
