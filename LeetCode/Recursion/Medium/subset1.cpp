class Solution {
  public:
  void helper(vector<int> arr, int i, int sum, vector<int> &ans, int n){
    //   cout <<" in " << endl;
    if(i >= n){
        ans.push_back(sum);
        
        return;
    }
    
    // cout << arr[i] << " ";
    // sum += arr[i];
    //pick the current element
    helper(arr, i + 1, sum + arr[i], ans, n);

    // sum -= arr[i];
    // do not pick the current element
    helper(arr, i + 1, sum, ans, n);
  }
  
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        
        vector<int> ans;
        
        helper(arr, 0, 0, ans, n);
        
        return ans;
    }
};