#include<iostream>
using namespace std;

void printFromnTo1(int i, int n){
    if(i == 0){
        return;
    }
    cout << i << endl;
    printFromnTo1(i - 1, n);
}

void main(){
    int n;
    cin >> n;

    printFromnTo1(n, n);
    return;
}