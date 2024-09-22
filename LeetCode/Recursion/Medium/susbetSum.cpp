/*
This is not the best approach use DP for this question.
*/

bool getCount(vector<int> arr, int i, int n, int sum, int count, int & ans){
	   if(i >= n || count > sum){
	       if(sum == count){
	         return true;
	        }
	        
	       // then return
	       return false;
	   }

       if(getCount(arr, i + 1, n, sum, count + arr[i], ans)) return true;
        if(getCount(arr, i+1,n, sum, count, ans)) return true;

    return false;
	}
	
	int perfectSum(vector<int> arr, int n, int sum)
	{
        // Your code goes here
        int ans = 0;
        return getCount(arr, 0, n, sum, 0, ans);
	}
	  


bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    if(perfectSum(a, n, k))
        return true;
    
    return false;
}