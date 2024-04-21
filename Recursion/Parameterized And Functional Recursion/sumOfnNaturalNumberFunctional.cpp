#include<iostream>
using namespace std;

int sumN(int i){
    if(i == 0){
        return 0;
    }

    return i + sumN(i - 1);
}

int main(){
    int n;
    cin >> n;
    cout << sumN(n) << endl;;
    return 0;
}