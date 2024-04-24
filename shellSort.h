//
// Created by grons on 29.03.2024.
//

#ifndef PROJEKT_AIZO_SHELLSORT_H
#define PROJEKT_AIZO_SHELLSORT_H
#include <iostream>
#include <chrono>
#include "insertionSort.h"


template<typename T>
long long shellSort1(T arr[], int size){
    auto start = std::chrono::high_resolution_clock::now();
    int h =1;
    int d[2] = {1,1};
    //obliczenie początkowej odległości metodą Knutha
    while(3*h+1<size){
        d[0]=d[1];
        d[1]=3*h+1;
        h++;
    }
    h = d[0];//początkowa odległość
    //rozpocęcie sortowania z obliczoną odległością
    while(h>0){
        //przechodzenie przez podtablice
        for (int i = h; i < size; i+=1) {
            //zapamiętanie elementu, który będzie porównywany
            T tmp = arr[i];
            // Przesunięcie elementów większych od zapamiętanego elementu
            int j;
            for(j=i;j>=h && arr[j - h] > tmp; j-=h){
                arr[j]= arr[j - h];
            }
            // Umieszczenie zapamiętanego elementu w odpowiednim miejscu
            arr[j]=tmp;
        }
        //zmiejszenie odległości poprzez podzielenie na 3
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
