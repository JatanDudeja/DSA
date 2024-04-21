#include<iostream>
using namespace std;

void print1Ton(int i, int n){
    if(i == n){
        return;
    }
    cout << i << endl;
    print1Ton(i + 1, n);
}

void main(){
    int n;
    cin >> n;
    print1Ton(1, n);
    return;
}