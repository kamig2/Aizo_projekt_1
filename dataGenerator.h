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
    long long timeInsertionSortInt = 0;
    long long timeInsertionSortFloat = 0;
    long long timeShellSort1 =0 ;
    long long timeShellSort2 =0 ;
    long long timeHeapSort = 0;
    long long timeQuickSortLeft = 0;
    long long timeQuickSortRight = 0;
    long long timeQuickSortMiddle = 0;
    long long timeQuickSortRandom = 0;


public:
    template<typename T>
    T* createRandomArray(T* arr, int size){
        arr = new T[size];
        std::random_device r;
        if constexpr (std::is_same_v<T, int>) {
//            std::cout<<"int";
            for (int i = 0; i < size; ++i) {
                std::default_random_engine e1(r());
                std::uniform_int_distribution<int> uniformDist(-10000000,10000000);
                arr[i] = uniformDist(e1);
            }
        }else{
//            std::cout<<"float";
            for (int i = 0; i < size; ++i) {
                std::mt19937_64 e1(r());
                std::uniform_real_distribution<float> uniformDist(-10000000,10000000);
                arr[i] = uniformDist(e1);
//                std::cout << arr[i] << std::endl;
            }
        }
        return arr;
    }
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
            std::cout<<"petla";
            arr[i]=var;
            var++;
        }
        return arr;
    }
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
        return arr;
    }
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

    template<typename T>
    T* copyArray(T* arr, int size){
        T *cArr = new T[size];
        for(int i = 0; i < size; i++){
            cArr[i] = arr[i];
        }
        return cArr;
    }
    static void saveToCsvFile(std::string fileName, long long time , std::string message){
        std::ofstream file(fileName,std::ios::out | std::ios::app);

        if (!file.is_open()) {
            std::cerr << "Nie można otworzyć pliku " << fileName << " do zapisu!" << std::endl;
            return;
        }
        std::cout<<"Plik utworzony";
        time /=100;
        file<<message<<std::endl;
        file<<time<<" ms"<<std::endl;
        file.close();

    }
    static void saveToCsvFile(std::string fileName, std::string message){
        std::ofstream file(fileName,std::ios::out | std::ios::app);

        if (!file.is_open()) {
            std::cerr << "Nie można otworzyć pliku " << fileName << " do zapisu!" << std::endl;
            return;
        }
        file<<message<<std::endl;
        file.close();

    }
    void save(int size){
        std::string message = "uśreniony czas pomiaru tablicy " + std::to_string(size) + " elementowej";
        saveToCsvFile("insertionSortInt.csv", timeInsertionSortInt, message);
        saveToCsvFile("insertionSortFloat.csv", timeInsertionSortFloat, message);
        saveToCsvFile("heapSortInt.csv",timeHeapSort,message);
        saveToCsvFile("shellSort1Int.csv",timeShellSort1,message);
        saveToCsvFile("shellSort2Int.csv",timeShellSort2,message);
        saveToCsvFile("quickSortRandomInt.csv",timeQuickSortRandom,message);
        saveToCsvFile("quickSortLeftInt.csv",timeQuickSortLeft,message);
        saveToCsvFile("quickSortRightInt.csv",timeQuickSortRight,message);
        saveToCsvFile("quickSortMiddleInt.csv",timeQuickSortMiddle,message);
    }
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
    void setTimeToZero(){
        timeHeapSort=0;
        timeInsertionSortInt=0;
        timeShellSort1=0;
        timeShellSort2 =0 ;
        timeQuickSortLeft = 0;
        timeQuickSortRight = 0;
        timeQuickSortMiddle = 0;
        timeQuickSortRandom = 0;

    }

    void generateArrayToTests(){
        int sizeOfArray[] = {10,20,40000,80000,100000,120000,160000};
        int *arr{};
        int *cArr{};
        float *arrFloat{};
        typeOfDataMessage("randomowa tablica");


        for(int i=0;i<7;i++){
            for(int j=0;j<100;j++){
                int size =sizeOfArray[i];
                arr = createRandomArray(arr,size);

                cArr = copyArray(arr,size);
                timeInsertionSortInt += insertionSort(cArr, size);

                arrFloat = createRandomArray(arrFloat,size);
                timeInsertionSortFloat += insertionSort(arrFloat, size);

                cArr = copyArray(arr,size);
                timeHeapSort += heapSort(cArr,size);

                cArr = copyArray(arr, size);
                timeShellSort1 += shellSort1(cArr, size);

                cArr = copyArray(arr, size);
                timeShellSort2 = shellSort2(cArr,size);

               /* cArr = copyArray(arr,size);
                timeQuickSortLeft += quickSort1(cArr,0,size,0);

                cArr = copyArray(arr,size);
                timeQuickSortRight += quickSort1(cArr,0,size,1);

                cArr = copyArray(arr,size);
                timeQuickSortMiddle += quickSort1(cArr,0,size,2);

                cArr = copyArray(arr,size);
                timeQuickSortRandom += quickSort1(cArr,0,size,3);
*/



            }

            save(sizeOfArray[i]);
            setTimeToZero();


        }
        delete[] cArr;
        delete[] arr;
    }
    void generateSortedArrToTests(){
        int sizeOfArray[] = {10,20,40000,80000,100000,120000,160000};
        int *arr{};
        int *cArr{};
        float *arrFloat{};
        typeOfDataMessage("posortowana tablica");

        for(int i=0;i<7;i++){
            for(int j=0;j<100;j++){
                int size =sizeOfArray[i];
                arr = createSortedArray(arr,size);

                cArr = copyArray(arr,size);
                timeInsertionSortInt += insertionSort(cArr, size);

                arrFloat = createSortedArray(arrFloat,size);
                timeInsertionSortFloat += insertionSort(arrFloat, size);

                cArr = copyArray(arr,size);
                timeHeapSort += heapSort(cArr,size);

                cArr = copyArray(arr, size);
                timeShellSort1 += shellSort1(cArr, size);




            }

            save(sizeOfArray[i]);
            setTimeToZero();


        }
        delete[] cArr;
        delete[] arr;

    }
    void generateSortedReversArrToTests(){
        int sizeOfArray[] = {10,20,40000,80000,100000,120000,160000};
        int *arr{};
        int *cArr{};
        float *arrFloat{};
        typeOfDataMessage("posortowana odwrócona tablica");



        for(int i=0;i<7;i++){
            for(int j=0;j<100;j++){
                int size =sizeOfArray[i];
                arr = createReverseSortedArray(arr,size);

                arrFloat = createReverseSortedArray(arrFloat,size);
                timeInsertionSortFloat += insertionSort(arrFloat, size);

                cArr = copyArray(arr,size);
                timeInsertionSortInt += insertionSort(cArr, size);

                cArr = copyArray(arr,size);
                timeHeapSort += heapSort(cArr,size);

                cArr = copyArray(arr, size);
                timeShellSort1 += shellSort1(cArr, size);



            }

            save(sizeOfArray[i]);
            setTimeToZero();

        }
        delete[] cArr;
        delete[] arr;

    }

    void generateSortedArrToTests33(){
        int sizeOfArray[] = {10,20,40000,80000,100000,120000,160000};
        int *arr{};
        int *cArr{};
        float *arrFloat{};
        typeOfDataMessage("posortowana w 33%");

        for(int i=0;i<7;i++){
            for(int j=0;j<100;j++){
                int size =sizeOfArray[i];
                arr = createSortedArray33(arr,size);

                cArr = copyArray(arr,size);
                timeInsertionSortInt += insertionSort(cArr, size);

                arrFloat = createSortedArray33(arrFloat,size);
                timeInsertionSortFloat += insertionSort(arrFloat, size);

                cArr = copyArray(arr,size);
                timeHeapSort += heapSort(cArr,size);

                cArr = copyArray(arr, size);
                timeShellSort1 += shellSort1(cArr, size);


            }

            save(sizeOfArray[i]);
            setTimeToZero();


        }
        delete[] cArr;
        delete[] arr;

    }
    void generateSortedArrToTests66(){
        int sizeOfArray[] = {10,20,40000,80000,100000,120000,160000};
        int *arr{};
        float *arrFloat{};
        typeOfDataMessage("Posortowana w 66%");

        int *cArr{};

        for(int i=0;i<7;i++){
            for(int j=0;j<100;j++){
                int size =sizeOfArray[i];
                arr = createSortedArray66(arr,size);

                cArr = copyArray(arr,size);
                timeInsertionSortInt += insertionSort(cArr, size);

                arrFloat = createSortedArray66(arrFloat,size);
                timeInsertionSortFloat += insertionSort(arrFloat, size);

                cArr = copyArray(arr,size);
                timeHeapSort += heapSort(cArr,size);

                cArr = copyArray(arr, size);
                timeShellSort1 += shellSort1(cArr, size);

            }

            save(sizeOfArray[i]);

            setTimeToZero();


        }
        delete[] cArr;
        delete[] arr;

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
