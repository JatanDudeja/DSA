#include<iostream>
using namespace std;

void fact(int i, int factorial){
    if(i == 0){
        cout << factorial << endl;
        return;
    }

    fact(i - 1, factorial * i);
}


int main(){
    int n;
    cin >> n;
    fact(n, 1);
    return 0;
}