#include<iostream>
using namespace std;

void printFromnTo1(int i, int n){
    if(i > n){
        return;
    }

    printFromnTo1(i + 1, n);
    cout << i << endl;
}

int main(){
    int n;
    cin >> n;
    printFromnTo1(1, n);
    return 0;
}