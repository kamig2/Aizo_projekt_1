//
// Created by grons on 29.03.2024.
//

#ifndef PROJEKT_AIZO_QUICKSORT_H
#define PROJEKT_AIZO_QUICKSORT_H
#include <ctime>
#include <iostream>
#include <chrono>
#include <random>
#include <stack>


template<typename T>
T partition(T *arr, int left, int right, int pivot) {

    // Jeśli indeks ostatniego elementu (right) nie jest tym samym co indeks wybranego elementu (pivot),
    // zamieniają się miejscami elementy na tych indeksach
    if(right != pivot){
        T temp = arr[right];
        arr[right] = arr[pivot];
        arr[pivot] = temp;

    }
    // Wybieramy element, który będzie służył jako pivot dla sortowania
    T p = arr[right];
    // Inicjalizacja indeksu, który będzie wskazywał miejsce, gdzie elementy mniejsze od pivot będą umieszczone
    int j = left;
    // Iteracja przez tablicę od lewej do prawej strony pivota
    for (int i = left; i < right; i++){
        // Jeśli element na indeksie i jest mniejszy lub równy pivot,
        // zamienia go z elementem na indeksie j, a następnie zwiększa j
        if(arr[i] <= p){
            T temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;
        }
    }
    // Po zakończeniu iteracji element na indeksie j jest pierwszym elementem większym od pivota
    // Zamienia go z elementem na indeksie right, aby umieścić pivot na swoim ostatecznym miejscu
    T temp = arr[j];
    arr[j] = arr[right];
    arr[right] = temp;
    // Zwraca indeks, na którym umieszczony jest pivot po sortowaniu.
    return j;
}

template<typename T>
void sortLeft(T *arr, int size) {
    // Jeśli rozmiar tablicy jest mniejszy lub równy 1, nie ma potrzeby sortowania, więc funkcja kończy działanie
    if (size <= 1) return;

    // Inicjalizacja stosu, który będzie przechowywać pary indeksów reprezentujących zakresy do sortowania
    std::stack<std::pair<int, int>> stack;
    // Na początku stosu umieszczamy cały zakres tablicy
    stack.push({0, size - 1});

    // Główna pętla, która będzie działała, dopóki stos nie jest pusty
    while (!stack.empty()) {
        // Pobieranie z góry stosu pary indeksów reprezentujących zakres do sortowania
        auto range = stack.top();
        stack.pop();

        // Wyodrębnianie dolnego i górnego indeksu zakresu
        int low = range.first;
        int high = range.second;

        // Jeśli dolny indeks jest mniejszy od górnego, oznacza to, że zakres ma więcej niż jeden element
        if (low < high) {
            // Wywołanie funkcji partition, która sortuje zakres i zwraca indeks pivota
            T pivot = partition(arr, low, high, low);
            // Dodawanie do stosu zakresów po lewej i prawej stronie pivota
            stack.push({low, pivot - 1});
            stack.push({pivot + 1, high});
        }
    }
}

template<typename T>
void sortRight(T *arr, int size) {
    // Jeśli rozmiar tablicy jest mniejszy lub równy 1, nie ma potrzeby sortowania, więc funkcja kończy działanie
    if (size <= 1) return;

    // Inicjalizacja stosu, który będzie przechowywać pary indeksów reprezentujących zakresy do sortowania
    std::stack<std::pair<int, int>> stack;
    // Na początku stosu umieszczamy cały zakres tablicy
    stack.push({0, size - 1});

    // Główna pętla, która będzie działała, dopóki stos nie jest pusty
    while (!stack.empty()) {
        // Pobieranie z góry stosu pary indeksów reprezentujących zakres do sortowania
        auto range = stack.top();
        stack.pop();

        // Wyodrębnianie dolnego i górnego indeksu zakresu
        int low = range.first;
        int high = range.second;

        // Jeśli dolny indeks jest mniejszy od górnego, oznacza to, że zakres ma więcej niż jeden element
        if (low < high) {
            // Wywołanie funkcji partition, która sortuje zakres i zwraca indeks pivota
            T pivot = partition(arr, low, high, high);
            // Dodawanie do stosu zakresów po lewej i prawej stronie pivota
            stack.push({low, pivot - 1});
            stack.push({pivot + 1, high});
        }
    }
}

template<typename T>
void sortMiddle(T *arr, int size) {
    // Jeśli rozmiar tablicy jest mniejszy lub równy 1, nie ma potrzeby sortowania, więc funkcja kończy działanie
    if (size <= 1) return;

    // Inicjalizacja stosu, który będzie przechowywać pary indeksów reprezentujących zakresy do sortowania
    std::stack<std::pair<int, int>> stack;
    // Na początku stosu umieszczamy cały zakres tablicy
    stack.push({0, size - 1});

    // Główna pętla, która będzie działała, dopóki stos nie jest pusty
    while (!stack.empty()) {
        // Pobieranie z góry stosu pary indeksów reprezentujących zakres do sortowania
        auto range = stack.top();
        stack.pop();

        // Wyodrębnianie dolnego i górnego indeksu zakresu
        int low = range.first;
        int high = range.second;

        // Jeśli dolny indeks jest mniejszy od górnego, oznacza to, że zakres ma więcej niż jeden element
        if (low < high) {
            // Wywołanie funkcji partition, która sortuje zakres i zwraca indeks pivota
            T pivot = partition(arr, low, high, ((high - low) / 2 + low));
            // Dodawanie do stosu zakresów po lewej i prawej stronie pivota
            stack.push({low, pivot - 1});
            stack.push({pivot + 1, high});
        }
    }
}
template<typename T>
void sortRandom(T *arr, int size) {
    // Jeśli rozmiar tablicy jest mniejszy lub równy 1, nie ma potrzeby sortowania, więc funkcja kończy działanie
    if (size <= 1) return;

    // Inicjalizacja stosu, który będzie przechowywać pary indeksów reprezentujących zakresy do sortowania
    std::stack<std::pair<int, int>> stack;
    // Na początku stosu umieszczamy cały zakres tablicy
    stack.push({0, size - 1});

    // Główna pętla, która będzie działała, dopóki stos nie jest pusty
    while (!stack.empty()) {
        // Pobieranie z góry stosu pary indeksów reprezentujących zakres do sortowania
        auto range = stack.top();
        stack.pop();

        // Wyodrębnianie dolnego i górnego indeksu zakresu
        int low = range.first;
        int high = range.second;

        // Inicjalizacja generatora liczb pseudolosowych
        std::mt19937 rng;
        // Ustawienie ziarna (seed) dla generatora liczb pseudolosowych.
        rng.seed(std::chrono::system_clock::now().time_since_epoch().count());

        // Definicja rozkładu jednostajnego dla liczb całkowitych w określonym zakresie
        std::uniform_int_distribution<int> distribution(low, high);
        // Generowanie i zapisywanie losowej liczby całkowitej zdefiniowanego zakresu
        // za pomocą generatora liczb pseudolosowych i rozkładu jednostajnego
        int random = distribution(rng);

        // Jeśli dolny indeks jest mniejszy od górnego, oznacza to, że zakres ma więcej niż jeden element
        if (low < high) {
            // Wywołanie funkcji partition, która sortuje zakres i zwraca indeks pivota
            T pivot_index = partition(arr, low, high, random);
            // Dodawanie do stosu zakresów po lewej i prawej stronie pivota
            stack.push({low, pivot_index - 1});
            stack.push({pivot_index + 1, high});
        }
    }
}

template<typename T>
long long quickSort(T *arr,int size, int type) {//funkcja umożliwiająca wywołanie funkcji sortującej o określonym wyborze pivota
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
