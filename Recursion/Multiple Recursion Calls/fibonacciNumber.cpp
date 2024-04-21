#include<iostream>
using namespace std;

int fib(int n){
    if(n == 0 || n == 1){
        return n;
    }

    int last = fib(n - 1);
    int secondLast = fib(n - 2);

    return last + secondLast;
}

int main(){
    int n;
    cin >> n;

    cout << fib(n) << endl;
    return 0;
}