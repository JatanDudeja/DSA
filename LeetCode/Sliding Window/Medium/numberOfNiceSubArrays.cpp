class Solution {
public:
    int getSubArrayCount(vector<int>& arr, int k) {
        if (k < 0)
            return 0;
        int i = 0;
        int j = 0;
        int n = arr.size();
        int ans = 0;
        int count = 0;

        while (j < n) {
            if (arr[j] % 2 == 1)
                count++;

            while (count > k) {
                if(arr[i] % 2 == 1) count--;
                i++;
            }

            if (count <= k) {
                ans += (j - i + 1);
                j++;
            }
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& arr, int k) {
        cout << getSubArrayCount(arr, k) << endl;
        cout << getSubArrayCount(arr, k - 1) << endl;
        return getSubArrayCount(arr, k) - getSubArrayCount(arr, k - 1);
    }
};