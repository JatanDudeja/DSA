
// This solution will give TLE as the input can be very large.

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long ans = 1;
        int mod = pow(10, 9) + 7;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                ans *= 5;
            }
            else{
                ans *= 4;
            }
            ans %= mod;
        }


        return ans;
    }
};