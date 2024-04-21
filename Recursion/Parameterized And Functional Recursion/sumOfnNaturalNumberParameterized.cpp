#include<iostream>
using namespace std;

void sumN(int i, int sum){
    if(i == 0){
        cout << sum << endl;
        return;
    }

    sumN(i - 1, sum + i);
}

int main(){
    int n;
    cin >> n;
    sumN(n, 0);
    return 0;
}