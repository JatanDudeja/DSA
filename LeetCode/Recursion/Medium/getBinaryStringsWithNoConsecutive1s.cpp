class Solution{
public:
    void getBinaryStrings(int n, string startWith, vector<string> &ans){
        if(n <= 0){
            // cout << "in: " << startWith << endl;
            ans.push_back(startWith);
            return;
        }
        
        // push back 0 because repeting 0's is not an issue
        startWith.push_back('0');
        
        // call the fuction recursively
        getBinaryStrings(n - 1, startWith, ans);
        
        // remove the taken 0
        startWith.pop_back();
        
        
        // if the last element is 1 so nothing 1 cannot be added
        // so no further recursion just return
        if(startWith.back() == '1') {
            return;
        }
        // cout << n << ", " << startWith << endl;
        
        // otherwise push back 1
        startWith.push_back('1');
        
        // cout << n << ", " << startWith << endl;
        
        // and recall the function recursively
        getBinaryStrings(n - 1, startWith, ans);
    }
    
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string> ans;
        if(num == 0) return ans;
        getBinaryStrings(num, "", ans);
        // cout << "\n\n\n\n\n";
        return ans;
    }
};