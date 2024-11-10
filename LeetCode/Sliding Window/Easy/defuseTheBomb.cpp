// Best Approach but this can be written better as we have to write
// the same thing twice so code is repeating

class Solution {
public:
    vector<int> decrypt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans(n);

        int i = 1;
        int j = 1;
        int sum = 0;
        int count = 0;

        if (k == 0)
            return ans;
        if (k > 0) {
            while (i < n) {
                sum += arr[j];
                count++;
                // cout << i << ", " << j << ", " << sum << endl;

                if (count > k) {
                    sum -= arr[i];
                    count--;
                    i += 1;
                }

                if (count == k) {
                    ans[i - 1] = sum;
                }
                j = (j + 1) % n;
            }

            return ans;
        }

        if (k < 0) {
            cout << "idhhar dekh bhai" << endl;
            i = n - 2;
            j = n - 2;
            count = 0;
            while (i >= 0) {
                sum += arr[j];
                count--;
                // cout << i << ", " << j << ", " << sum <<  ", " << count << endl;

                if (count < k) {
                // cout << "in >k: " << i << ", " << j << ", " << sum <<  ", " << count << endl;
                    sum -= arr[i];
                    count++;
                    i -= 1;
                }

                if (count == k) {
                // cout << "in ==k: " << i << ", " << j << ", " << sum <<  ", " << count <<  endl;
                    ans[i + 1] = sum;
                }
                j = (j + n - 1) % n;
            }

        }
            return ans;
    }
};