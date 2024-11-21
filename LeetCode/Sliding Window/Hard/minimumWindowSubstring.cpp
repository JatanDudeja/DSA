// Variable Window Question

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

            while(sum >= target){
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
