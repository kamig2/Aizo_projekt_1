//
// Created by grons on 30.03.2024.
//

#ifndef PROJEKT_AIZO_MENU_H
#define PROJEKT_AIZO_MENU_H
#include <iostream>
#include<random>
#include <fstream>
#include "dataGenerator.h"

class Menu{
private:
    template<typename T>
    static void readFile(std::string_view fileName,T* tab){
        std::ifstream file;
        file.open( fileName.data() );
        if(file.is_open()){
            int size;
            file>>size;
            tab = new T[size];
            for(int i = 0; i<size;i++){
                file>>tab[i];
            }
            for(int i =0; i<size;i++){
                std::cout<<tab[i]<<" ";
            }
            delete [] tab;

        }else{
            std::cout<<"Nie otwarto pliku"<<std::endl;
        }
        file.close();
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
            int *tab{};
            switch (choice) {
                case 1:
                    std::cout<<"Podaj nazwe pliku"<<std::endl;
                    std::cin>>fileName;
                    readFile(fileName,tab);
                    break;
                case 2:
                    std::cout<<"Wpisz rozmiar tablicy: "<<std::endl;
                    std::cin>>size;
                    dataGenerator::createRandomArray<int>(tab,size);
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
            float *tab{};
            switch (choice) {
                case 1:
                    std::cout<<"Podaj nazwe pliku"<<std::endl;
                    std::cin>>fileName;
                    readFile(fileName,tab);
                    break;
                case 2:
                    std::cout<<"Wpisz rozmiar tablicy: "<<std::endl;
                    std::cin>>size;
                    dataGenerator::createRandomArray<float>(tab, size);
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
