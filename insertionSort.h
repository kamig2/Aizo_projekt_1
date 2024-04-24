//
// Created by grons on 29.03.2024.
//

#ifndef PROJEKT_AIZO_INSERTIONSORT_H
#define PROJEKT_AIZO_INSERTIONSORT_H

template<typename T>
long long insertionSort(T arr[], int size ){
    auto start = std::chrono::high_resolution_clock::now();
    T k;
    //rozpoczęcie sortowania
    for (int i =1; i<size;i++){
        k = arr[i];//zapamiętanie elementu
        int j = i;
        while (j>0 and arr[j - 1] > k){
            arr[j]=arr[j - 1];
            j--;
        }
        // Umieszczenie zapamiętanego elementu w odpowiednim miejscu
        arr[j]=k;
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}


#endif //PROJEKT_AIZO_INSERTIONSORT_H
