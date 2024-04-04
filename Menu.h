//
// Created by grons on 30.03.2024.
//

#ifndef PROJEKT_AIZO_MENU_H
#define PROJEKT_AIZO_MENU_H
#include <iostream>
#include<random>
#include <fstream>
using namespace std;

class Menu{
public:
    //metoda createArray tworzy tablice z wygenerowanymi randomowo liczbami
    void createArray(int* tab, int size){
        cout<<"int";
        tab = new int[size];
        srand(time(NULL));
        for (int i = 0; i < size; ++i) {
            tab[i] = rand();
            cout<<tab[i]<<endl;
        }
        delete [] tab;
    }

    void createArray(float* tab, int size){
        cout<<"float";
        tab = new float [size];
        srand(time(NULL));
        for (int i = 0; i < size; ++i) {
            tab[i] = rand();
            cout<<tab[i]<<endl;
        }
        delete [] tab;

    }

    void readFile(std::string fileName){
        ifstream file;
        file.open( fileName );
        if(file.is_open()){
            int* tab;
            int size;
            file>>size;
            tab = new int[size];
            for(int i = 0; i<size;i++){
                file>>tab[i];
            }
            for(int i =0; i<size;i++){
                cout<<tab[i]<<" ";
            }
            delete [] tab;

        }else{
            cout<<"Nie otwarto pliku"<<endl;
        }
        file.close();
    }

    void chooseType(){
        bool loop = true;
        while (loop){
            cout<<"Wybierz typ badanych danych:"<<endl;
            cout<<"1. int"<<endl;
            cout<<"2. float"<<endl;
            int choice;
            cin>>choice;
            switch (choice) {
                case 1:
                    int type;
                    showMenu(type);
                    break;
                case 2:
                    float type1;
                    showMenu(type1);
                    break;

            }
        }
    }

    template<typename T>
    void showMenu(T type){
        setlocale(LC_CTYPE, "Polish");
        while (true){
            int choice;
            cout << "Menu:"<<endl;
            cout<<"1. Wczytanie tablicy z pliku"<<endl;
            cout<<"2. Wygenerowanie tablicy o zadanym rozmiarze zawierające losowe wartości"<<endl;
            cout<<"3. Wyświetlenie ostatnio utworzonej tablicy na ekranie"<<endl;
            cout<<"4. Uruchomienie wybranego algorytmu na ostatnio utworzonej tablicy"<<endl;
            cout<<"5. Wyświetlenie posortowanej tablicy na ekranie "<<endl;
            cout<<"6. Wróć do wyboru typu"<<endl;
            cin >> choice;
            switch (choice) {
                case 1:
//                    cout<<"Podaj nazwe pliku"<<endl;
                    readFile("C:\\Users\\grons\\Desktop\\Studia\\4 sem\\Aizo\\Projekt_Aizo\\probny.txt");
                    break;
                case 2:
                    int size;
                    cout<<"Wpisz rozmiar tablicy: "<<endl;
                    cin>>size;
                    if(typeid(type)== typeid(int)){
                        int *tab;
                        createArray(tab,size);
                    }else{
                        float *tab;
                        createArray(tab, size);
                    }
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    chooseType();

            }
        }
    }

};

#endif //PROJEKT_AIZO_MENU_H
