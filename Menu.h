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
        file.open( fileName.data() );
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

        }else{
            std::cout<<"Nie otwarto pliku"<<std::endl;
        }
        file.close();
        return size;
    }

public:
    void chooseType(){
        while (true){
            std::cout<<"Wybierz typ badanych danych:"<<std::endl;
            std::cout<<"1. int"<<std::endl;
            std::cout<<"2. float"<<std::endl;
            std::cout<<"0. Wyjdź"<<std::endl;
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
        int *arr{};
        int size = 0 ;
        currentArray curAr(size, arr);
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
            dataGenerator generator;//czy da sie zrobić tak żeby przekazywać typ tylko raz do klasy a nie do karzdej metody
            switch (choice) {
                case 1:
                    std::cout<<"Podaj nazwe pliku"<<std::endl;
                    std::cin>>fileName;
                    size = readFile(fileName, arr);
                    std::cout<<size<<std::endl;
                    if(size !=0){
                        curAr.setSize(size);
                        curAr.setArr(arr);
                    }
                    break;
                case 2:
                    std::cout<<"Wpisz rozmiar tablicy: "<<std::endl;
                    std::cin>>size;
                    generator.createRandomArray<int>(arr, size);
                    curAr.setSize(size); //dlaczego jeśli tu przekazuje rozmiar który jest niezerowy w funkcji show array jest zerowy
                    curAr.setArr(arr);   //jak sprawdzić co jest w tej tablicy
                    break;
                case 3:
//                    curAr.showArray();
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
            dataGenerator generator;//czy da sie zrobić tak żeby przekazywać typ tylko raz do klasy a nie do karzdej metody
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
                    generator.createRandomArray<float>(arr, size);
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
