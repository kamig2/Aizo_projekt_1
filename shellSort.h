//
// Created by grons on 29.03.2024.
//

#ifndef PROJEKT_AIZO_SHELLSORT_H
#define PROJEKT_AIZO_SHELLSORT_H
#include <iostream>
#include <chrono>
#include "insertionSort.h"


template<typename T>
long long shellSort1(T tab[], int size){//dodać drugi algorytm o mniejszej zlożoności
    auto start = std::chrono::high_resolution_clock::now();
    int h =1;
    int d[2] = {1,1};
    while(3*h+1<size){
        d[0]=d[1];
        d[1]=3*h+1;
        h++;
    }
    h = d[0];
    while(h>0){
        for (int i = h; i < size; i+=1) {
            T tmp = tab[i];
            int j;
            for(j=i;j>=h && tab[j-h]>tmp;j-=h){
                tab[j]= tab[j-h];
            }
            tab[j]=tmp;
        }
        h /=3;
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

template<typename T>
long long shellSort2(T arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();
    // Obliczenie początkowej odległości Hibbarda
    int k = 1;
    while (k <= n / 2) {
        k = 2 * k + 1;
    }

    // Rozpoczęcie sortowania z odległością Hibbarda
    while (k >= 1) {
        // Przechodzenie przez podtablice
        for (int i = k; i < n; ++i) {
            // Zapamiętanie elementu, który będzie porównywany
            T temp = arr[i];

            // Przesunięcie elementów większych od zapamiętanego elementu
            int j = i;
            while (j >= k && arr[j - k] > temp) {
                arr[j] = arr[j - k];
                j -= k;
            }

            // Umieszczenie zapamiętanego elementu w odpowiednim miejscu
            arr[j] = temp;
        }

        // Zmniejszenie odległości Hibbarda
        k = (k - 1) / 2;
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

#endif //PROJEKT_AIZO_SHELLSORT_H
