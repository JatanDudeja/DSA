/*

Things to remember :- 
1. Move the right pointer by 1 always.
2. We will keep a count variable to keep track of the zeroes
and ensure that count is always less or equal to k so that we can calculate maxLen of the subarray
we can obtain.
3. Only shrink the window or increase l when count > k so that we can get to a subarray where
count <= k
4. While shrinking keep checking if the element at l is 0 if yes then decrease the count and
move l by 1 so that we leave that 0 which is at l and have count <=k
5. l will always move by 1 in the loop and even if the element at l is not 0 it will still move
because we need to find a 0 and when we find a 0 we follow step 4.
*/

class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {

        int maxLen = 0;
        int n = arr.size();
        int l = 0, r = 0;
        int count = 0;

        while (r < n) {
            // check if the current element is 0 if yes then increase the count by 1
            if(arr[r] == 0){
                count++;
            }

            // now check if the count > k which means we have extra 0s and now we
            // want to shrink the window size and move l pointer
            while(count > k){
                // as we any 0 we just decrease the count
                // and always move l by 1 even if we find the 0 because
                // when we cross this one 0 we will be definitely sure that
                // now count == k -> dry run to verify this
                if(arr[l] == 0) count--;
                l++;
            }


            // now if we have current element as either 1 or the count <= k
            // we have to calculate maxLen again
            // we can even remove this if condition and this will work perfectly fine
            // as either the element is one or 2 we do not case and the above loop
            // will take care of the count is always less than k

            // if(arr[r] == 1 || count <= k){
                maxLen = max(maxLen, r - l + 1);
            // }
            r++;
        }

        return maxLen;
    }
};