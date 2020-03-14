#include "task1.h"

int getnthFib(int n){
    if(n==0 || n==1){
        return n;
    }
    else{
        return getnthFib(n-1)+getnthFib(n-2);
    }
}

void fillInFibonacciNumbers(int result[], int length){
    for(int i=0;i<length;++i){
        result[i] = getnthFib(i);
    }
}
void printArray(int arr[], int length){
    for(int i=0;i<length;++i){
        cout << arr[i] << endl;
    }
}
void createFibonacci(){
    int usrInp;
    cout << "Enter number of wanted Fibonacci-numers: ";
    cin >> usrInp;
    //int* fibAr = nullptr; //Ser ut til å funke uten å initiere peker til nullptr først, hva er best praksis?
    int* fibAr = new int[usrInp];
    fillInFibonacciNumbers(fibAr,usrInp);
    printArray(fibAr, usrInp);
    delete[] fibAr;
}