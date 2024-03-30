//
// Created by grons on 29.03.2024.
//

#ifndef PROJEKT_AIZO_SHELLSORT_H
#define PROJEKT_AIZO_SHELLSORT_H
#include <iostream>
#include "insertionSort.h"
int calculateSpaceing(int size,int h){
    if(h==1){
        int d[2] = {1,1};
        while(3*h+1<size){
            d[0]=d[1];
            d[1]=3*h+1;
            h++;
        }
        return d[0];

    } else{
        return h/3;
    }

}


template<typename T>
void shellSort(T tab[], int size){
    int h =1;
    h = calculateSpaceing(size,h);
    int j  = 1;
    while(j<h){
        for (int i = 0; i < size; i+=h) {

        }
        j++;
    }


}

#endif //PROJEKT_AIZO_SHELLSORT_H
