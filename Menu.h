//
// Created by grons on 30.03.2024.
//

#ifndef PROJEKT_AIZO_MENU_H
#define PROJEKT_AIZO_MENU_H
#include <iostream>
#include<random>
#include <fstream>
#include "dataGenerator.h"
#include "currentArray.h"

class Menu{
private:
    template<typename T>
    static int readFile(std::string_view fileName,T* arr){
        std::ifstream file;
        file.open( fileName.data());
        int size = 0;
        if(file.is_open()){
            file>>size;
            arr = new T[size];
            for(int i = 0; i<size;i++){
                file>>arr[i];
            }
            for(int i =0; i<size;i++){
                std::cout<<arr[i]<<" ";
            }
            file.close();

        }else{
            std::cout<<"Nie otwarto pliku"<<std::endl;
        }
        return size;
    }

public:
   /* void chooseMode(){
        while(true){
            std::cout<<"Wybierz tryb pracy:"<<std::endl;
            std::cout<<"1. Automatyczna generacja danych"<<std::endl;
            std::cout<<"2."

        }
    }*/
    void chooseType(){
        while (true){
            std::cout<<"Wybierz typ badanych danych:"<<std::endl;
            std::cout<<"1. int"<<std::endl;
            std::cout<<"2. float"<<std::endl;
            std::cout<<"0. Powrot"<<std::endl;
            int choice;
            std::cin>>choice;
            switch (choice) {
                case 1:
                    showMenuInt();
                    break;
                case 2:
                    showMenuFloat();
                    break;
                case 0:
                    return;
                default:
                    break;
            }
        }
    }


    void showMenuInt(){
        int *arr = {};
        int *cArr = {};
        int size = 0 ;
        currentArray curArr(size, arr);
        currentArray sortedArr(size, cArr);
        dataGenerator generator;//czy da sie zrobić tak żeby przekazywać typ tylko raz do klasy a nie do karzdej metody
        while (true){
            int choice;
            std::cout << "Menu:"<<std::endl;
            std::cout<<"1. Wczytanie tablicy z pliku"<<std::endl;
            std::cout<<"2. Wygenerowanie tablicy o zadanym rozmiarze zawierające losowe wartości"<<std::endl;
            std::cout<<"3. Wyświetlenie ostatnio utworzonej tablicy na ekranie"<<std::endl;
            std::cout<<"4. insertion sort"<<std::endl;
            std::cout<<"5. heap sort"<<std::endl;
            std::cout<<"6. shell sort"<<std::endl;
            std::cout<<"7. quick sort"<<std::endl;
            std::cout<<"8. Wyświetlenie posortowanej tablicy na ekranie "<<std::endl;
            std::cout<<"0. Powrot"<<std::endl;
            std::cin >> choice;
            std::string fileName;
            switch (choice) {
                case 1:
                    std::cout<<"Podaj nazwe pliku"<<std::endl;
                    std::cin>>fileName;
                    size = readFile(fileName, arr);//czmu ni moge otworzyć pliku?
                    std::cout<<size<<std::endl;
                    if(size !=0){
                        curArr.setSize(size);
                        curArr.setArr(arr);
                    }
                    break;
                case 2:
                    std::cout<<"Wpisz rozmiar tablicy: "<<std::endl;
                    std::cin>>size;
                    arr = generator.createRandomArray<int>(arr, size);
                    curArr.setSize(size);
                    curArr.setArr(arr);
                    break;
                case 3:
                    curArr.showArray();
                    break;
                case 4:
                    cArr = generator.copyArray<int>( arr, size );
                    insertionSort(cArr,size);
                    sortedArr.setSize(size);
                    sortedArr.setArr(cArr);
                    break;
                case 5:
                    cArr = generator.copyArray<int>( arr, size );
                    heapSort(cArr,size);
                    sortedArr.setSize(size);
                    sortedArr.setArr(cArr);
                    break;
                case 6:
                    std::cout<<"Wybierz wersje sortowania shella: "<<std::endl;
                    std::cout<<"1. Wersja pierwsza"<<std::endl;
                    std::cout<<"2. Wersja druga"<<std::endl;
                    std::cout<<"0. Powrot"<<std::endl;
                    int version;
                    std::cin>>version;
                    if(version==0) break;
                    cArr = generator.copyArray<int>( arr, size );
                    if(version==1){
                        shellSort1(cArr, size);
                    }else if(version==2){

                    }
                    sortedArr.setSize(size);
                    sortedArr.setArr(cArr);
                    break;
                case 7:
                    std::cout<<"Wybierz pozycje pivota:"<<std::endl;
                    std::cout<<"1. Lewy"<<std::endl;
                    std::cout<<"2. Prawy"<<std::endl;
                    std::cout<<"3. Srodkowy"<<std::endl;
                    std::cout<<"4. Losowy"<<std::endl;
                    std::cout<<"0. Powrot"<<std::endl;
                    int pivot;
                    std::cin >> pivot;
                    switch(pivot){
                        case 1:
                            quickSort1(cArr,0,size-1,0);//nie działa
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 0:
                            break;
                        default:
                            break;
                    }

                    break;
                case 8:
                    sortedArr.showArray();
                    break;
                case 0:
                    return;
                default:
                    break;
            }
        }
    }

    void showMenuFloat(){
        while (true){
            int choice;
            std::cout << "Menu:"<<std::endl;
            std::cout<<"1. Wczytanie tablicy z pliku"<<std::endl;
            std::cout<<"2. Wygenerowanie tablicy o zadanym rozmiarze zawierające losowe wartości"<<std::endl;
            std::cout<<"3. Wyświetlenie ostatnio utworzonej tablicy na ekranie"<<std::endl;
            std::cout<<"4. Uruchomienie wybranego algorytmu na ostatnio utworzonej tablicy"<<std::endl;
            std::cout<<"5. Wyświetlenie posortowanej tablicy na ekranie "<<std::endl;
            std::cout<<"0. Powrot"<<std::endl;
            std::cin >> choice;
            std::string fileName;
            int size;
            dataGenerator generator; //czy da sie zrobić tak żeby przekazywać typ tylko raz do klasy a nie do karzdej metody
            float *arr{};
            switch (choice) {
                case 1:
                    std::cout<<"Podaj nazwe pliku"<<std::endl;
                    std::cin>>fileName;
                    readFile(fileName, arr);
                    break;
                case 2:
                    std::cout<<"Wpisz rozmiar tablicy: "<<std::endl;
                    std::cin>>size;
                    arr = generator.createRandomArray<float>(arr, size);
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 0:
                    return;
                default:
                    break;
            }
        }
    }


};

#endif //PROJEKT_AIZO_MENU_H
