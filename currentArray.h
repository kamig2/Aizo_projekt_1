//
// Created by grons on 10.04.2024.
//

#ifndef PROJEKT_AIZO_CURRENTARRAY_H
#define PROJEKT_AIZO_CURRENTARRAY_H
#include <iostream>

template<typename T>
class currentArray{
private:
    int size;
    T* array{};

public:
    currentArray(int size, T *arr) {
        this->size = size;
        this->array = arr;
    }

    [[nodiscard]] int getSize() const {
        return size;
    }

    T* getArr() const {
        return array;
    }

    void setSize(int size) {
        this->size = size;
    }

    void setArr(T *arr) {
        this->array = arr;
    }

    void showArray(){
        for(int i =0; i < size; i++ ){
            std::cout << array[i] << ", ";

        }
        std::cout<<std::endl;
    }
};

#endif //PROJEKT_AIZO_CURRENTARRAY_H
