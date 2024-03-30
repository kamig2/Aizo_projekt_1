//
// Created by grons on 29.03.2024.
//

#ifndef PROJEKT_AIZO_QUICKSORT_H
#define PROJEKT_AIZO_QUICKSORT_H
#include <iostream>


template<typename T>
int partition(T tab[], int left, int right){
    int pivot = tab[left];
    int l = left;
    int r = right;
    while(true){
        while(tab[l]<pivot) l++;
        while(tab[r]>pivot) r--;
        if(l<r){
            std::swap(tab[l],tab[r]);
            l++;
            r--;

        }else{
            if(r=right) r--;
            return r;
        }
    }

}

template<typename T>
void quickSort(T tab[],int l,int p){
    if(l>=p) return;
    int m = partition(tab,l,p);
    quickSort(tab,l,m);
    quickSort(tab,m+1,l);
}

#endif //PROJEKT_AIZO_QUICKSORT_H
