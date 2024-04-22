class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1.0;
        }

        if(n < 0){ // converts the negative power to positive and x to 1 / x, now x is 1 / x and the power is positive now we can follow the approach of n / 2 and multiplying x * x
            n = abs(n);
            x = 1 / x;
        }
        
        double po = myPow(x, n / 2);

        double ans = n % 2 == 0 ? po * po : po * po * x; 

        return ans;
    }
};