//
// Created by grons on 29.03.2024.
//

#ifndef PROJEKT_AIZO_INSERTIONSORT_H
#define PROJEKT_AIZO_INSERTIONSORT_H

template<typename T>
void insertionSort(T tab[], int size ){
    int key;
    for (int i =1; i<size;i++){
        key = tab[i];
        int j = i;
        while (j>0 and tab[j-1]>key){
            tab[j]=tab[j-1];
            j--;
        }
        tab[j]=key;
    }
}


#endif //PROJEKT_AIZO_INSERTIONSORT_H
