#include<iostream>
using namespace std;

void printFrom1Ton(int n){
    if(n == 0){
        return;
    }
    printFrom1Ton(n - 1);
    cout << n << endl;
}

int main(){
    int n;
    cin >> n;
    printFrom1Ton(n);
    return 0;
}