//
// Created by grons on 04.04.2024.
//

#ifndef PROJEKT_AIZO_DATAGENERATOR_H
#define PROJEKT_AIZO_DATAGENERATOR_H
#include <iostream>
#include "shellSort.h"
#include "quickSort.h"
#include "insertionSort.h"
#include "heapSort.h"
#include "Menu.h"

//template<typename T>
class dataGenerator{
public:
    template<typename T>
    static void createRandomArray(T* tab, int size){
        tab = new T[size];
        std::random_device r;
        if constexpr (std::is_same_v<T, int>) {
            std::cout<<"int";
            for (int i = 0; i < size; ++i) {
                std::default_random_engine e1(r());
                std::uniform_int_distribution<int> uniformDist(-10000000,10000000);
                tab[i] = uniformDist(e1);
                std::cout<<tab[i]<<std::endl;
            }
        }else{
            std::cout<<"float";
            for (int i = 0; i < size; ++i) {
                std::mt19937_64 e1(r());
                std::uniform_real_distribution<float> uniformDist(-10000000,10000000);
                tab[i] = uniformDist(e1);
                std::cout<<tab[i]<<std::endl;
            }
        }
    }
    template<typename T>
    void createSortedArray(T* tab, int size){
        createRandomArray(tab,size);
        std::sort(tab);
    }
    template<typename T>
    void createReverseSortedArray(T* tab, int size){
        createRandomArray(tab,size);
        std::sort(tab);//zmienić na sortowanie malejąco
    }
    template<typename T>
    void createSortedArray33(T* tab, int size){
        createRandomArray(tab,size);
        int sortSize = 0.33*size;
        std::sort(tab, tab+sortSize);
    }

    template<typename T>
    void createSortedArray66(T* tab, int size){
        createRandomArray(tab,size);
        int sortSize = 0.66*size;//zamienić na int, zrobić podłoge z tego czy coś
        std::sort(tab, tab+sortSize);
    }

};

#endif //PROJEKT_AIZO_DATAGENERATOR_H
