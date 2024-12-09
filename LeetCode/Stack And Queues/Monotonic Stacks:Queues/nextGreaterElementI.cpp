// My Approach - Best Solution But the code can we well written as there
// repetition so that better code is below this

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr, vector<int>& arr1) {
        unordered_map<int, int> temp;

        int n1 = arr1.size();
        int n = arr.size();

        stack<int> st;
        vector<int> ans(n, -1);

        for(int i = n1 - 1; i >= 0; i--){
            if(st.empty()){
                temp[arr1[i]] = -1;
                st.push(arr1[i]);
            }
            else{
                if(arr1[i] < st.top()){
                    temp[arr1[i]] = st.top();
                    st.push(arr1[i]);
                }
                else{
                    int j = 0;
                    while (!st.empty() && arr1[i] > st.top()){
                        if(st.empty()) break;
                        st.pop();
                    }
                    
                    if(st.empty()){
                        temp[arr1[i]] = -1;
                    }
                    else{
                        temp[arr1[i]] = st.top();
                    }
                    st.push(arr1[i]);
                }
            }
        }



        for(int i = 0; i < n; i++){
            if(temp.find(arr[i]) != temp.end()){
                ans[i] = temp[arr[i]];
            }
        }

        return ans;    
    }
};


// Better written code
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        stack<int> st;
        for(int i = nums2.size()-1 ; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if(!st.empty()) mpp[nums2[i]] = st.top();
            else mpp[nums2[i]] = -1;
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int num:nums1){
            ans.push_back(mpp[num]);
        }
        return ans;
    }
};