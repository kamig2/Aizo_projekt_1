//
// Created by grons on 29.03.2024.
//

#ifndef PROJEKT_AIZO_HEAPSORT_H
#define PROJEKT_AIZO_HEAPSORT_H
#include <iostream>
template<typename T>
// Funkcja sprawdzająca, czy dany poddrzewo w drzewie binarnym maksymalnym (max heap) jest poprawnie posortowane.
void validateMaxHeap(T arr[], int heapSize, int parentIndex){
    // Inicjalizacja indeksu największego elementu jako indeks rodzica.
    int maxIndex = parentIndex;
    // Obliczanie indeksów lewego i prawego dziecka rodzica
    int lChild = 2*parentIndex + 1;
    int rChild = 2*parentIndex +2;

    // Sprawdzanie, czy lewe dziecko istnieje i czy jest większe od obecnego największego elementu.
    // Jeśli tak, aktualizacja indeksu największego elementu.
    if (lChild<heapSize and arr[lChild] > arr[maxIndex]) {
        maxIndex = lChild;
    }
    // Sprawdzanie, czy prawe dziecko istnieje i czy jest większe od obecnego największego elementu.
    // Jeśli tak, aktualizacja indeksu największego elementu.
    if(rChild<heapSize and arr[rChild] > arr[maxIndex]){
        maxIndex = rChild;
    }
    // Jeśli indeks największego elementu nie jest już indeksem rodzica,
    // oznacza to, że elementy nie są poprawnie posortowane.
    // Wymiana miejscami elementu rodzica z największym elementem w poddrzewie,
    // a następnie rekurencyjne wywołanie funkcji dla poddrzewa, które zawiera nowy element rodzica.
    if(maxIndex != parentIndex){
        std::swap(arr[maxIndex], arr[parentIndex]);
        validateMaxHeap(arr, heapSize, maxIndex);
    }


}

template<typename T>
// Funkcja sortująca tablicę za pomocą algorytmu sortowania przez kopcowanie (heap sort)
long long heapSort(T arr[], int size){
    // Zapisanie czasu rozpoczęcia sortowania.
    auto start = std::chrono::high_resolution_clock::now();

    // Inicjalizacja kopca maksymalnego.
    // Począwszy od ostatniego rodzica (indeksy od 0 do size/2-1),
    // dla każdego rodzica wywołujemy funkcję validateMaxHeap,
    // aby upewnić się, że poddrzewo jest poprawnie posortowane.
    for(int i = size/2-1;i>=0;i--){
        validateMaxHeap(arr, size, i);
    }
    // Sortowanie tablicy.
    // Zaczynając od ostatniego elementu,
    // wymieniamy go z elementem na początku kopca,
    // a następnie redukujemy rozmiar kopca o 1.
    // Następnie, dla nowego elementu na początku kopca,
    // wywołujemy funkcję validateMaxHeap, aby upewnić się,
    // że kopiec jest poprawnie posortowany.
    for(int i = size-1;i>0;i--){
        std::swap(arr[0], arr[i]);
        size--;
        validateMaxHeap(arr, size, 0);
    }
    // Zapisanie czasu zakończenia sortowania.
    auto end = std::chrono::high_resolution_clock::now();
    // Obliczenie czasu trwania sortowania w mikrosekundach.
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

}

#endif //PROJEKT_AIZO_HEAPSORT_H
