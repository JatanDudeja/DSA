// TC - O(2N)
// SC - O(N)

class Solution {
public:
    // Understanding the Question:-
    /*
    The question states that the array can have unique elements == k which means
    the frequency of the elements can be more that k but there should be only k
    unique elements.

    For Eg- [1, 2, 1, 2, 3], k = 2
    [1, 2] is one of the subarrays that has exactly 2 unique numbers.
    [1, 2, 1] is also one of the subarrays that has exactly 2 unique numbers
    because frequency of 1 is more that 2 but still the subarray has exactly 2
    unique numbers. [2, 1, 2, 3], [1, 2, 3] - These are not the correct sub
    arrays as there are more that 2 unique characters which are 1, 2 and 3.

    So we donot care about the character frequency but care about the number of
    unique elements present in a particular subarray.

    */
    

    // Thinking Process:-
    /*
    If we are not sure where to shrink the window size or increase it we use
    this method where we count the number of correct subarrays for <= k and then
    subtract the number of correct subarrays for <= k - 1

    For Eg:-
    We need to find all the sub arrays which contain unique number and length of
    that suba array == k.

    arr = [1, 2, 1, 2, 3], k = 2

    Now if we choose 1, 2 it exactly has 2 unique characters which is our answer
    so according to sliding window we just move j to next element that is 1(at
    index 2) but now [1, 2, 1] is also a answer as it still contains exactly 2
    characters which are unique even though it has 2 1s but there are still 2
    different numbers which are 1 and 2 present in the subarray so it will also
    count as an answer so now we move to next element 2 (at index 3) now this
    subarray([1, 2, 1, 2]) arrays is also a correct answer so now we move to the
    next element that is 3(at index 4) now there are more than 2 unique
    characters so we will shrink the size but if you see in the process we have
    only 3 subarrays that have exactly 2 unique numbers which is wrong as [2,
    1], [2, 1, 2], are also some examples of correct subarrays which we have
    missed and have reached at the last index but i is still at 0 which is
    incorrect.

    Now we can have conflict on that instead of doing +1 for every sub array we
    can do ans += (j - i + 1) basically add the length of the subarray in the
    answer but this approach is also wrong. Let's suppose we take [1, 2, 1] as
    one subarray as it has exactly 2 unique numbers so now if do ans += (j - i +
    1) we have ans = 3 which is absolutely wrong as [1] and [2] cannot count as
    answers as they only have 1 unique sub numbers. So adding j - i + 1 to
    answer means we are trying the add subarrays which have <= k unique
    elements.

    So instead of checking for == k we check for <= k and <= k - 1 and then
    subtract it.
    */

    int getSubArrays(vector<int> arr, int k) {
        int i = 0, j = 0;
        int n = arr.size();
        int tempAns = 0;
        unordered_map<int, int> m;


        while (j < n) {
            m[arr[j]]++;

            while (m.size() > k) {
                m[arr[i]]--;
                if (m[arr[i]] == 0) {
                    m.erase(arr[i]);
                }
                i++;
            }

            tempAns += (j - i + 1);

            j++;
        }

        return tempAns;
    }

    int subarraysWithKDistinct(vector<int>& arr, int k) {

        return getSubArrays(arr, k) - getSubArrays(arr, k - 1);
    }
};