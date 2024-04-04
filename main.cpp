#include <iostream>
#include "shellSort.h"
#include "quickSort.h"
#include "insertionSort.h"
#include "heapSort.h"
#include "Menu.h"

using namespace std;


int main() {
    Menu menu;
    menu.chooseType();

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
