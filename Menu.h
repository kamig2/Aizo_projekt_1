//
// Created by grons on 30.03.2024.
//

#ifndef PROJEKT_AIZO_MENU_H
#define PROJEKT_AIZO_MENU_H
#include <iostream>
#include<random>
#include <fstream>
#include <string>
#include "dataGenerator.h"
#include "currentArray.h"

class Menu{ //klasa reprezentująca menu
private:
    template<typename T>
    static T* readFile(std::string_view fileName,T* arr,int *size){ //metoda odczytująca dane z pliku tekstowego
        std::cout<<fileName<<std::endl;
        std::ifstream file;
        file.open( fileName.data());
        if(file.is_open()){
            file>>*size;
            arr = new T[*size];
            for(int i = 0; i<*size;i++){
                file>>arr[i];
            }
            for(int i =0; i<*size;i++){
                std::cout<<arr[i]<<" ";
            }
            file.close();

        }else{
            std::cout<<"Nie otwarto pliku"<<std::endl;
        }
        return arr;
    }


    void chooseType(){//metoda wyboru typu danych
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
    void menu(){
        std::cout << "Menu:"<<std::endl;
        std::cout<<"1. Wczytanie tablicy z pliku"<<std::endl;
        std::cout<<"2. Wygenerowanie tablicy o zadanym rozmiarze zawierające losowe wartosci"<<std::endl;
        std::cout<<"3. Wyswietlenie ostatnio utworzonej tablicy na ekranie"<<std::endl;
        std::cout<<"4. insertion sort"<<std::endl;
        std::cout<<"5. heap sort"<<std::endl;
        std::cout<<"6. shell sort"<<std::endl;
        std::cout<<"7. quick sort"<<std::endl;
        std::cout<<"8. Wyswietlenie posortowanej tablicy na ekranie "<<std::endl;
        std::cout<<"0. Powrot"<<std::endl;
    }


    void showMenuInt(){//metoda zawierająca menu dla danych typu int
        int *arr = {}; //utworzenie wskaźnika na pustą tablicę typu int
        int *cArr = {};//utworzenie wskaźnika na pustą tablicę typu int gdzie będzie kopiowana tablica
        int size = 0 ;
        currentArray curArr(size, arr);
        currentArray sortedArr(size, cArr);
        dataGenerator generator;
        while (true){//utworzenie pętli, która tworzy menu
            int choice;
            menu();//wyświetlenie opcji menu na ekranie
            std::cin >> choice;//sczytanie wyboru z konsoli
            std::string fileName;
            switch (choice) {
                case 1://wybór pierwszy umożliwia wczytanie tablicy z pliku txt
                    std::cout<<"Podaj nazwe pliku"<<std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin,fileName);
                    arr = readFile(fileName, arr,&size);
                    std::cout<<size<<std::endl;
                    if(size !=0){
                        //ustawienie wartości ostatnio sczytanej tablicy
                        curArr.setSize(size);
                        curArr.setArr(arr);
                    }
                    break;
                case 2://wybór drugi umożliwia generacje losowych liczb
                    std::cout<<"Wpisz rozmiar tablicy: "<<std::endl;
                    std::cin>>size;
                    //wywołanie funkcji generującej liczby losowe
                    arr = generator.createRandomArray<int>(arr, size);
                    //ustawienie wartości ostatnio sczytanej tablicy
                    curArr.setSize(size);
                    curArr.setArr(arr);
                    break;
                case 3://wybór trzeci umożliwiający wyświetlenie ostatnio utworzonej tablicy
                    if(size!=0){
                        //wywołanie funkcji wyświetlającej obecną tablicę
                        curArr.showArray();
                    }else{
                        std::cout<<"Nie utworzono jeszcze żadnej tablicy"<<std::endl;
                    }
                    break;
                case 4://wybór czwarty umożliwiający wykonanie sortowania insertion sort na kopii ostatnio utworzonej tablicy
                    cArr = generator.copyArray<int>( arr, size ); //utworzenie kopii tablicy
                    insertionSort(cArr,size); //wywołanie funkcji insertion sort
                    sortedArr.setSize(size); //ustawienie wartości posortowanej tablicy
                    sortedArr.setArr(cArr);
                    break;
                case 5://wybór piąty umożliwiający wykonanie sortowania heap sort na kopii ostatnio utworzonej tablicy
                    cArr = generator.copyArray<int>( arr, size ); //utworzenie kopii tablicy
                    heapSort(cArr,size);//wywołanie funkcji heap sort
                    sortedArr.setSize(size);//ustawienie wartości posortowanej tablicy
                    sortedArr.setArr(cArr);
                    break;
                case 6://wybór szósty umożliwiający wykonanie sortowania shell sort na kopii ostatnio utworzonej tablicy
                    std::cout<<"Wybierz wersje sortowania shella: "<<std::endl;//wyświetlenie opcji wyboru dla sortowania shella
                    std::cout<<"1. Wersja pierwsza"<<std::endl;
                    std::cout<<"2. Wersja druga"<<std::endl;
                    std::cout<<"0. Powrot"<<std::endl;
                    int version;
                    std::cin>>version;
                    if(version==0) break;
                    cArr = generator.copyArray<int>( arr, size );//utworzenie kopii tablicy
                    if(version==1){
                        shellSort1(cArr, size);//wywołanie pierwszej funkcji shella
                    }else if(version==2){
                        shellSort2(cArr,size); //wywołanie drugiej funkcji shella
                    }

                    //ustawienie wartości posortowanej tablicy
                    sortedArr.setSize(size);
                    sortedArr.setArr(cArr);
                    break;
                case 7://wybór siódmy umożliwiający wykonanie sortowania quick sort na kopii ostatnio utworzonej tablicy
                    std::cout<<"Wybierz pozycje pivota:"<<std::endl;//wyświetlenie opcji wyboru dla quick sorta
                    std::cout<<"1. Lewy"<<std::endl;
                    std::cout<<"2. Prawy"<<std::endl;
                    std::cout<<"3. Srodkowy"<<std::endl;
                    std::cout<<"4. Losowy"<<std::endl;
                    std::cout<<"0. Powrot"<<std::endl;
                    cArr = generator.copyArray<int>( arr, size );//utworzenie kopii tablicy
                    int pivot;
                    std::cin >> pivot;
                    switch(pivot){
                        case 1://wywołanie funkcji quick sort dla lewego pivota
                            quickSort(cArr,size,0);
                            //ustawienie wartości posortowanej tablicy
                            sortedArr.setSize(size);
                            sortedArr.setArr(cArr);
                            break;
                        case 2://wywołanie funkcji quick sort dla prawego pivota
                            quickSort(cArr,size,1);
                            //ustawienie wartości posortowanej tablicy
                            sortedArr.setSize(size);
                            sortedArr.setArr(cArr);
                            break;
                        case 3://wywołanie funkcji quick sort dla środkowego pivota
                            quickSort(cArr,size,2);
                            //ustawienie wartości posortowanej tablicy
                            sortedArr.setSize(size);
                            sortedArr.setArr(cArr);
                            break;
                        case 4://wywołanie funkcji quick sort dla losowego pivota
                            quickSort(cArr,size,3);
                            //ustawienie wartości posortowanej tablicy
                            sortedArr.setSize(size);
                            sortedArr.setArr(cArr);
                            break;
                        case 0:
                            break;
                        default:
                            break;
                    }

                    break;
                case 8://wybór ósmy umożliwia wyświetlenie posortowanej tablicy
                    sortedArr.showArray();
                    break;
                case 0:
                    return;
                default:
                    break;
            }
        }
    }

    void showMenuFloat(){//metoda zawierająca menu dla danych typu float
        float *arr = {};  //utworzenie wskaźnika na pustą tablicę typu float
        float *cArr = {}; //utworzenie wskaźnika na pustą tablicę typu float gdzie będzie kopiowana tablica
        int size = 0 ;
        currentArray curArr(size, arr);
        currentArray sortedArr(size, cArr);
        dataGenerator generator;
        while (true){
            int choice;
            menu();
            std::cin >> choice;
            std::string fileName;
            switch (choice) {
                case 1://wybór pierwszy umożliwia wczytanie tablicy z pliku txt
                    std::cout<<"Podaj nazwe pliku"<<std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin,fileName);
                    arr = readFile(fileName, arr,&size);
                    std::cout<<size<<std::endl;
                    if(size !=0){
                        //ustawienie wartości ostatnio sczytanej tablicy
                        curArr.setSize(size);
                        curArr.setArr(arr);
                    }
                    break;
                case 2://wybór drugi umożliwia generacje losowych liczb
                    std::cout<<"Wpisz rozmiar tablicy: "<<std::endl;
                    std::cin>>size;
                    //wywołanie funkcji generującej liczby losowe
                    arr = generator.createRandomArray<float>(arr, size);
                    //ustawienie wartości ostatnio sczytanej tablicy
                    curArr.setSize(size);
                    curArr.setArr(arr);

                    break;
                case 3://wybór trzeci umożliwiający wyświetlenie ostatnio utworzonej tablicy
                    if(size!=0){
                        //wywołanie funkcji wyświetlającej obecną tablicę
                        curArr.showArray();
                    }else{
                        std::cout<<"Nie utworzono jeszcze żadnej tablicy"<<std::endl;
                    }
                    break;
                case 4://wybór czwarty umożliwiający wykonanie sortowania insertion sort na kopii ostatnio utworzonej tablicy
                    cArr = generator.copyArray<float>( arr, size );
                    insertionSort(cArr,size);
                    //ustawienie wartości posortowanej tablicy
                    sortedArr.setSize(size);
                    sortedArr.setArr(cArr);
                    break;
                case 5://wybór piąty umożliwiający wykonanie sortowania heap sort na kopii ostatnio utworzonej tablicy
                    cArr = generator.copyArray<float>( arr, size );
                    heapSort(cArr,size);
                    //ustawienie wartości posortowanej tablicy
                    sortedArr.setSize(size);
                    sortedArr.setArr(cArr);
                    break;
                case 6://wybór szósty umożliwiający wykonanie sortowania shell sort na kopii ostatnio utworzonej tablicy
                    std::cout<<"Wybierz wersje sortowania shella: "<<std::endl;
                    std::cout<<"1. Wersja pierwsza"<<std::endl;
                    std::cout<<"2. Wersja druga"<<std::endl;
                    std::cout<<"0. Powrot"<<std::endl;
                    int version;
                    std::cin>>version;
                    if(version==0) break;
                    cArr = generator.copyArray<float>( arr, size );
                    if(version==1){
                        shellSort1(cArr, size);
                    }else if(version==2){
                        shellSort2(cArr,size);
                    }

                    //ustawienie wartości posortowanej tablicy
                    sortedArr.setSize(size);
                    sortedArr.setArr(cArr);
                    break;
                case 7://wybór siódmy umożliwiający wykonanie sortowania quick sort na kopii ostatnio utworzonej tablicy
                    std::cout<<"Wybierz pozycje pivota:"<<std::endl;
                    std::cout<<"1. Lewy"<<std::endl;
                    std::cout<<"2. Prawy"<<std::endl;
                    std::cout<<"3. Srodkowy"<<std::endl;
                    std::cout<<"4. Losowy"<<std::endl;
                    std::cout<<"0. Powrot"<<std::endl;
                    cArr = generator.copyArray<float>( arr, size );
                    int pivot;
                    std::cin >> pivot;
                    switch(pivot){
                        case 1://wywołanie funkcji quick sort dla lewego pivota
                            quickSort(cArr,size,0);
                            //ustawienie wartości posortowanej tablicy
                            sortedArr.setSize(size);
                            sortedArr.setArr(cArr);
                            break;
                        case 2://wywołanie funkcji quick sort dla prawego pivota
                            quickSort(cArr,size,1);
                            //ustawienie wartości posortowanej tablicy
                            sortedArr.setSize(size);
                            sortedArr.setArr(cArr);
                            break;
                        case 3://wywołanie funkcji quick sort dla środkowego pivota
                            quickSort(cArr,size,2);
                            //ustawienie wartości posortowanej tablicy
                            sortedArr.setSize(size);
                            sortedArr.setArr(cArr);
                            break;
                        case 4://wywołanie funkcji quick sort dla losowego pivota
                            quickSort(cArr,size,3);
                            //ustawienie wartości posortowanej tablicy
                            sortedArr.setSize(size);
                            sortedArr.setArr(cArr);
                            break;
                        case 0:
                            break;
                        default:
                            break;
                    }
                    break;
                case 8://wybór ósmy umożliwia wyświetlenie posortowanej tablicy
                    sortedArr.showArray();
                    break;
                case 0:
                    return;
                default:
                    break;
            }
        }
    }
public:
    void chooseMode(){
        while(true){
            std::cout<<"Wybierz tryb pracy:"<<std::endl;
            std::cout<<"1. Automatyczna generacja danych"<<std::endl;
            std::cout<<"2. Menu"<<std::endl;
            std::cout<<"0. Wyjdz"<<std::endl;
            dataGenerator g;
            int choice;
            std::cin>>choice;
            switch (choice) {
                case 1:
                    g.generateDataToTests();
                    break;
                case 2:
                    chooseType();
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
