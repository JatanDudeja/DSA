// Variable Window Size Question

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int n = arr.size();
        int size = INT_MAX;

        while(j < n){
            sum += arr[j];

            /*
            Whenever we find and sum >= target we loop it and shrink the
            window size until we reach the value of sum which is < target
            */
            while(sum >= target){
                // this if condition is for when i > j i.e. when both are on the same element and we know there cannot be any possible sub array whose sum >= target whose length < 1
                if(size == 1) return size;
                size = min(size, j - i + 1);
                sum -= arr[i];
                i++;
            }

            j++;

        }


        return size == INT_MAX ? 0 : size;
        
    }
};