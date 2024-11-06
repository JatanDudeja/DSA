class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int i = 0;
        int j = 0;
        int n = arr.size();
        long long sum = 0;
        long long maxi = 0;
        long long count = 0;
        unordered_map<int, long long> m;

        while (j < n) {
            sum += arr[j];
            m[arr[j]]++;
            // if (m[arr[j]] > 0) {
            count += m[arr[j]];
            // }

            // if (j - i + 1 < k) {
            //     j++;
            // }

            while (count > k) {
                if (count >= 0) {
                    sum -= arr[i];
                    count -= m[arr[i]];
                    m[arr[i]]--;
                    // break;
                }
                i++;
            }

            if (j - i + 1 == k) {
                if (count == k) {
                    maxi = max(maxi, sum);
                    sum -= arr[i];
                    count -= m[arr[i]];
                    m[arr[i]]--;
                    i++;
                }
            }
            j++;
        }

        return maxi;
    }
};