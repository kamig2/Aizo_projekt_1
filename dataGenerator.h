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
private:
    long long  timeInsertionSortInt = 0;
    long long timeInsertionSortFloat = 0;
    long long timeShellSort1 =0 ;
    long long timeShellSort2 =0 ;
    long long timeHeapSort = 0;
    long long timeQuickSortLeft = 0;
    long long timeQuickSortRight = 0;
    long long timeQuickSortMiddle = 0;
    long long timeQuickSortRandom = 0;

    //metoda tworząca posortowaną tablice o danym rozmiarze
    template<typename T>
    T* createSortedArray(T* arr, int size){
        arr = new T[size];
        for(int i=0;i<size;i++){
            arr[i]=i;
        }
        return arr;
    }
    template<typename T>
    T* createReverseSortedArray(T* arr, int size){
        arr= new T[size];
        T var =0;
        for(int i = size-1;i>=0;i--){
            arr[i]=var;
            var++;
        }
        return arr;
    }

    //metoda tworząca posortowaną tablice w 33%
    template<typename T>
    T*  createSortedArray33(T* arr, int size){
        arr = new T[size];
        int size1= size*0.33;
        int size2 = size - size1;
        T* sortedArr{};
        T* randomArr{};
        sortedArr = createSortedArray(sortedArr,size1);
        randomArr = createRandomArray(randomArr,size2);
        for (int i = 0; i < size1; ++i) {
            arr[i] = sortedArr[i] ;
        }

        for (int i = 0; i < size2; ++i) {
            arr[size1 + i] = randomArr[i];
        }
        delete[] sortedArr;
        delete[] randomArr;
        return arr;
    }

    //metoda tworząca posortowaną tablice w 66%
    template<typename T>
    T* createSortedArray66(T* arr, int size){
        arr = new T[size];
        int size1= size*0.66;
        int size2 = size - size1;
        T* sortedArr{};
        T* randomArr{};
        sortedArr = createSortedArray(sortedArr,size1);
        randomArr = createRandomArray(randomArr,size2);
        for (int i = 0; i < size1; ++i) {
            arr[i] = sortedArr[i] ;
        }

        for (int i = 0; i < size2; ++i) {
            arr[size1 + i] = randomArr[i];
        }
        delete[] sortedArr;
        delete[] randomArr;
        return arr;
    }

    //metoda zampisująca dane do pliku csv
    static void saveToCsvFile(std::string fileName, long long time , int message){
        std::ofstream file(fileName,std::ios::out | std::ios::app);

        if (!file.is_open()) {
            std::cerr << "Nie można otworzyć pliku " << fileName << " do zapisu!" << std::endl;
            return;
        }
        double time2;
        time2 = static_cast<double>(time)/100000;
        file<<message<<",";
        file<<time2<<std::endl;
        file.close();

    }
    //metoda zapisująca wiadomości do pliku csv
    static void saveToCsvFile(std::string fileName, std::string message){
        std::ofstream file(fileName,std::ios::out | std::ios::app);

        if (!file.is_open()) {
            std::cerr << "Nie można otworzyć pliku " << fileName << " do zapisu!" << std::endl;
            return;
        }
        file<<message<<std::endl;
        file.close();

    }

    //metoda wywołująca zapis danych do pliku dla każdego sortowania
    void save(int size){
        saveToCsvFile("insertionSortInt.csv", timeInsertionSortInt, size);
        saveToCsvFile("insertionSortFloat.csv", timeInsertionSortFloat, size);
        saveToCsvFile("heapSortInt.csv",timeHeapSort,size);
        saveToCsvFile("shellSort1Int.csv",timeShellSort1,size);
        saveToCsvFile("shellSort2Int.csv",timeShellSort2,size);
        saveToCsvFile("quickSortRandomInt.csv",timeQuickSortRandom,size);
        saveToCsvFile("quickSortLeftInt.csv",timeQuickSortLeft,size);
        saveToCsvFile("quickSortRightInt.csv",timeQuickSortRight,size);
        saveToCsvFile("quickSortMiddleInt.csv",timeQuickSortMiddle,size);
    }

    //metoda wywołująca zapis wiadomości do pliku dla każdego sortowania
    void typeOfDataMessage(std::string message){
        saveToCsvFile("insertionSortInt.csv",message);
        saveToCsvFile("insertionSortFloat.csv",message);
        saveToCsvFile("heapSortInt.csv",message);
        saveToCsvFile("shellSort1Int.csv",message);
        saveToCsvFile("shellSort2Int.csv",message);
        saveToCsvFile("quickSortLeftInt.csv",message);
        saveToCsvFile("quickSortRightInt.csv",message);
        saveToCsvFile("quickSortMiddleInt.csv",message);
        saveToCsvFile("quickSortRandomInt.csv",message);

    }

    //metoda ustawiająca wartości czasów dla wszystkich sortowań na 0
    void setTimeToZero(){
        timeHeapSort=0;
        timeInsertionSortInt=0;
        timeInsertionSortFloat =0;
        timeShellSort1=0;
        timeShellSort2 =0 ;
        timeQuickSortLeft = 0;
        timeQuickSortRight = 0;
        timeQuickSortMiddle = 0;
        timeQuickSortRandom = 0;

    }

    //metoda wykonująca sortowania dla losowych danych w tablicach o różnych wielkościach
    void generateArrayToTests(){
        int sizeOfArray[] = {5000,10000,20000,40000,60000,80000,100000};//wielkości tablic
        int *arr{};//tablica dla inta
        int *cArr{};
        float *arrFloat{};//tablica dla float
        typeOfDataMessage("randomowa tablica");//wywołanie metody zapisującej wiadomość do plików csv
        typeOfDataMessage("Rozmiar,Czas sortowania [ms]");


        for(int i=0;i<3;i++){//pętla przechodząca przez tablice rozmiarów
            for(int j=0;j<100;j++){//pętla wykonująca 100 pomiarów dla jednej wielkości tablicy
                int size =sizeOfArray[i];
                arr = createRandomArray(arr,size);//utworzenie losowej tablicy

                cArr = copyArray(arr,size);
                timeInsertionSortInt += insertionSort(cArr, size);

                arrFloat = createRandomArray(arrFloat,size);
                timeInsertionSortFloat += insertionSort(arrFloat, size);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeHeapSort += heapSort(cArr,size);

                delete[] cArr;
                cArr = copyArray(arr, size);
                timeShellSort1 += shellSort1(cArr, size);

                delete[] cArr;
                cArr = copyArray(arr, size);
                timeShellSort2 += shellSort2(cArr,size);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortLeft += quickSort(cArr,size,0);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortRight += quickSort(cArr,size,1);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortMiddle += quickSort(cArr,size,2);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortRandom += quickSort(cArr,size,3);

                delete[] cArr;
                delete[] arr;
                delete[] arrFloat;
            }

            save(sizeOfArray[i]);//zapis czasów sortowania do pliku csv
            setTimeToZero();//ustawienie wartości czasu na zero
        }
    }

    //metoda wykonująca sortowania dla posortowanych danych w tablicach o różnych wielkościach
    void generateSortedArrToTests(){
        int sizeOfArray[] = {5000,10000,20000,40000,60000,80000,100000};//wielkości tablic
        int *arr{};
        int *cArr{};
        float *arrFloat{};
        typeOfDataMessage("posortowana tablica");//wywołanie metody zapisującej wiadomość do plików csv
        typeOfDataMessage("Rozmiar,Czas sortowania [ms]");


        for(int i=0;i<7;i++){//pętla przechodząca przez tablice rozmiarów
            for(int j=0;j<100;j++){//pętla wykonująca 100 pomiarów dla jednej wielkości tablicy
                int size =sizeOfArray[i];
                arr = createSortedArray(arr,size);

                cArr = copyArray(arr,size);
                timeInsertionSortInt += insertionSort(cArr, size);

                arrFloat = createSortedArray(arrFloat,size);
                timeInsertionSortFloat += insertionSort(arrFloat, size);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeHeapSort += heapSort(cArr,size);

                delete[] cArr;
                cArr = copyArray(arr, size);
                timeShellSort1 += shellSort1(cArr, size);

                delete[] cArr;
                cArr = copyArray(arr, size);
                timeShellSort2 += shellSort2(cArr,size);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortLeft += quickSort(cArr,size,0);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortRight += quickSort(cArr,size,1);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortMiddle += quickSort(cArr,size,2);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortRandom += quickSort(cArr,size,3);
                delete[] cArr;
                delete[] arr;
                delete[] arrFloat;

            }

            save(sizeOfArray[i]);
            setTimeToZero();



        }


    }
    void generateSortedReversArrToTests(){
        int sizeOfArray[] = {5000,10000,20000,40000,60000,80000,100000};
        int *arr{};
        int *cArr{};
        float *arrFloat{};
        typeOfDataMessage("posortowana odwrócona tablica");
        typeOfDataMessage("Rozmiar,Czas sortowania [ms]");




        for(int i=0;i<1;i++){
            for(int j=0;j<100;j++){
                int size =sizeOfArray[i];
                arr = createReverseSortedArray(arr,size);

                arrFloat = createReverseSortedArray(arrFloat,size);
                timeInsertionSortFloat += insertionSort(arrFloat, size);

                cArr = copyArray(arr,size);
                timeInsertionSortInt += insertionSort(cArr, size);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeHeapSort += heapSort(cArr,size);

                delete[] cArr;
                cArr = copyArray(arr, size);
                timeShellSort1 += shellSort1(cArr, size);

                delete[] cArr;
                cArr = copyArray(arr, size);
                timeShellSort2 += shellSort2(cArr,size);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortLeft += quickSort(cArr,size,0);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortRight += quickSort(cArr,size,1);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortMiddle += quickSort(cArr,size,2);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortRandom += quickSort(cArr,size,3);
                delete[] cArr;
                delete[] arr;
                delete[] arrFloat;

            }

            save(sizeOfArray[i]);
            setTimeToZero();

        }

    }

    void generateSortedArrToTests33(){
        int sizeOfArray[] = {5000,10000,20000,40000,60000,80000,100000};
        int *arr{};
        int *cArr{};
        float *arrFloat{};
        typeOfDataMessage("posortowana w 33%");
        typeOfDataMessage("Rozmiar,Czas sortowania [ms]");


        for(int i=0;i<7;i++){
            for(int j=0;j<100;j++){
                int size =sizeOfArray[i];
                arr = createSortedArray33(arr,size);

                cArr = copyArray(arr,size);
                timeInsertionSortInt += insertionSort(cArr, size);

                arrFloat = createSortedArray33(arrFloat,size);
                timeInsertionSortFloat += insertionSort(arrFloat, size);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeHeapSort += heapSort(cArr,size);

                delete[] cArr;
                cArr = copyArray(arr, size);
                timeShellSort1 += shellSort1(cArr, size);

                delete[] cArr;
                cArr = copyArray(arr, size);
                timeShellSort2 += shellSort2(cArr,size);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortLeft += quickSort(cArr,size,0);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortRight += quickSort(cArr,size,1);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortMiddle += quickSort(cArr,size,2);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortRandom += quickSort(cArr,size,3);
                delete[] cArr;
                delete[] arr;
                delete[] arrFloat;
            }

            save(sizeOfArray[i]);
            setTimeToZero();



        }

    }
    void generateSortedArrToTests66(){
        int sizeOfArray[] = {5000,10000,20000,40000,60000,80000,100000};
        int *arr{};
        float *arrFloat{};
        typeOfDataMessage("Posortowana w 66%");
        typeOfDataMessage("Rozmiar,Czas sortowania [ms]");


        int *cArr{};

        for(int i=0;i<7;i++){
            for(int j=0;j<100;j++){
                int size =sizeOfArray[i];
                arr = createSortedArray66(arr,size);

                cArr = copyArray(arr,size);
                timeInsertionSortInt += insertionSort(cArr, size);

                arrFloat = createSortedArray66(arrFloat,size);
                timeInsertionSortFloat += insertionSort(arrFloat, size);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeHeapSort += heapSort(cArr,size);

                delete[] cArr;
                cArr = copyArray(arr, size);
                timeShellSort1 += shellSort1(cArr, size);

                delete[] cArr;
                cArr = copyArray(arr, size);
                timeShellSort2 += shellSort2(cArr,size);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortLeft += quickSort(cArr,size,0);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortRight += quickSort(cArr,size,1);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortMiddle += quickSort(cArr,size,2);

                delete[] cArr;
                cArr = copyArray(arr,size);
                timeQuickSortRandom += quickSort(cArr,size,3);

                delete[] cArr;
                delete[] arr;
                delete[] arrFloat;

            }

            save(sizeOfArray[i]);
            setTimeToZero();


        }

    }

public:
    template<typename T>
    T* copyArray(T* arr, int size){
        T* cArr = new T[size];
        for(int i = 0; i < size; i++){
            cArr[i] = arr[i];
        }
        return cArr;
    }

    template<typename T>
    T* createRandomArray(T* arr, int size){
        arr = new T[size];
        std::random_device r;
        if constexpr (std::is_same_v<T, int>) {
            for (int i = 0; i < size; ++i) {
                std::default_random_engine e1(r());
                std::uniform_int_distribution<int> uniformDist(-1000,1000);
                arr[i] = uniformDist(e1);
            }
        }else{
            for (int i = 0; i < size; ++i) {
                std::mt19937_64 e1(r());
                std::uniform_real_distribution<float> uniformDist(-1000,1000);
                arr[i] = uniformDist(e1);
            }
        }
        return arr;
    }


    void generateDataToTests(){
        generateArrayToTests();
        generateSortedArrToTests();
        generateSortedReversArrToTests();
        generateSortedArrToTests33();
        generateSortedArrToTests66();

    }




};

#endif //PROJEKT_AIZO_DATAGENERATOR_H
