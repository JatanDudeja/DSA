class Solution {
    int mod = 1000000007;
public:
    long long countGoodNumbersHelper(long long n, long long ans){
        if(n == 0){
            return 1;
        }

        long long midAns = countGoodNumbersHelper(n / 2, ans) % mod;

        if(n % 2 == 0){
            return (midAns * midAns) % mod;
        }

        else{
            return ((midAns * midAns) % mod * ans) % mod;
        }

    }

    int countGoodNumbers(long long n) {
        long long ans = 1;
        long long even = n / 2 + n % 2;
        long long odd = n / 2;

        long long evenAns = countGoodNumbersHelper(even, 5) % mod;
        long long oddAns = countGoodNumbersHelper(odd, 4) % mod;

        return evenAns * oddAns % mod;
    }
};