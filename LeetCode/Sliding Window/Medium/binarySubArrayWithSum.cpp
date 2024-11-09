class Solution {
public:
    int getSubArrayCount(vector<int>& arr, int target) {
        if (target < 0)
            return 0;
        int i = 0, j = 0;
        int n = arr.size();
        int ans = 0;
        int sum = 0;

        while (j < n) {
            sum += arr[j];

            while (sum > target) {
                sum -= arr[i];
                i++;
            }

            if (sum <= target) {
                ans += (j - i + 1);
                j++;
            }
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& arr, int target) {
        // Approach:- 
        /*
        1. Get count of all the subarrays that are equal to or less than
        target
        2. Get the count of all the subarrays that are equal to or less than target - 1

        Q. Why we did this and not use just one sliding window that gives answer
        for directly the number of subarrays that are equal to target?

        Ans. If you use this example [1,0,1,0,1], target = 2
            then possible sub arrays are:-
            1. [1, 0, 1]
            2. [1, 0, 1, 0]
            3. [0, 1, 0, 1]
            4. [1, 0, 1]

            but once the sum > target and you try to reduce the window size it will
            not work. For the above example when sum > target i will come at 1 and j will be
            at  n - 1 that will give subarray([0, 1, 0, 1]) which is true and now you will increase
            j by 1 again for the next iteration but now you will figure out that this will reach end
            end of the array but you will not have the count for the next sub array that is [1, 0, 1]
            so you will miss so many sub arrays so this approach is not valid.

            Try for [0,0,0,0,0,0], target = 0;

        Q. Why we did 2 calculations i.e. one for target and 1 for target - 1 and then subtracted then?
        Ans. Because when you calculate sub arrays that lead to a sum that is <= target(lets keep 
            target = 2 for this example) then you will have all the subarrays whose sum equals to 0, 1 and 2.
    
            And now you calculate the total number of subarrays whose sum is <= target - 1 in this
            case which is 1 as we have assumed target = 2 so we will have the count of the subarrays
            whose sum is <= 0 and 1.
    
            So now if we remove the all count of the sub arrays whose sum is <= 0, 1 from the count
            of the subarrays whose sum <= 0, 1, 2 then we will only be left with count of 
            subarrays whose sum is exactly 2;
        */
        return getSubArrayCount(arr, target) -
               getSubArrayCount(arr, target - 1);
    }
};