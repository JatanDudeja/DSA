class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {

        int i = 0, j = 1;
        int n = arr.size();
        unordered_map<int, int> m;

        for (; i < n; i++) {
            // check if the current eleemtn is present in the map or not
            if (m.find(arr[i]) != m.end()) {
                // if present in the map then check if that
                // index - current index of the element <= k
                // then it is a potential answer
                if (abs(m[arr[i]] - i) <= k)
                    return true;
            }
            // if not a potenital answer or index = 0 i.e.
            // it is the first element we just add it into map
            m[arr[i]] = i;
        }

        return false;
    }
};