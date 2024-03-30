//
// Created by grons on 29.03.2024.
//

#ifndef PROJEKT_AIZO_HEAPSORT_H
#define PROJEKT_AIZO_HEAPSORT_H
#include <iostream>
template<typename T>
void validateMaxHeap(T tab[],int heapSize, int parentIndex){
    int maxIndex = parentIndex;
    int lChild = 2*parentIndex + 1;
    int rChild = 2*parentIndex +2;
    if (lChild<heapSize and tab[lChild]>tab[maxIndex]) {
        maxIndex = lChild;
    }
    if(rChild<heapSize and tab[rChild]>tab[maxIndex]){
        maxIndex = rChild;
    }
    if(maxIndex != parentIndex){
        std::swap(tab[maxIndex],tab[parentIndex]);
        validateMaxHeap(tab,heapSize,maxIndex);
    }


}

template<typename T>
void heapSort(T tab[], int size){
    for(int i = size/2-1;i>=0;i--){
        validateMaxHeap(tab,size,i);
    }
    for(int i = size-1;i>0;i--){
        std::swap(tab[0],tab[i]);
        size--;
        validateMaxHeap(tab,size,0);
    }

}

#endif //PROJEKT_AIZO_HEAPSORT_H
