#include <iostream>
#include "shellSort.h"
#include "quickSort.h"
#include "insertionSort.h"
#include "heapSort.h"

using namespace std;

void menu(){
    setlocale(LC_CTYPE, "Polish");
    while (true){
        int choice;
        cout << "Menu:"<<endl;
        cout<<"1. Wczytanie tablicy z pliku"<<endl;
        cout<<"2. Wygenerowanie tablicy o zadanym rozmiarze zawierające losowe wartości"<<endl;
        cout<<"3. Wyświetlenie ostatnio utworzonej tablicy na ekranie"<<endl;
        cout<<"4. Uruchomienie wybranego algorytmu na ostatnio utworzonej tablicy"<<endl;
        cout<<"5. Wyświetlenie posortowanej tablicy na ekranie "<<endl;
        cin >> choice;
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;

        }
    }

}



int main() {
//    menu();
    int tab[] ={1,4,2,8,7,6};
    int n = sizeof(tab)/sizeof(int);
    cout<<n<<endl;
    insertionSort(tab, n);
    for(int i =0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    int tab2[] = {9,2,4,1,3,4,5,8};
    n = sizeof(tab2) / sizeof(int);
    heapSort(tab2,n);
    cout<<endl;
    for(int i =0;i<n;i++){
        cout<<tab2[i]<<", ";
    }

    return 0;

}
