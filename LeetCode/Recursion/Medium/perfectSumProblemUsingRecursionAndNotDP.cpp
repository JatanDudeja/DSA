/*
    Note:- This is not the best solution as it solves the question in 2^N time complexity and uses Recursion.

    To solve completely DP should be used.
*/


class Solution{
    int mod = 10e9 + 7;

	public:
	void getCount(int arr[], int i, int n, int sum, int count, int & ans){
	   if(i >= n){
	       // if i >= n and sum == count just increase the ans by 1
	       if(sum == count){
	         ans = (ans + 1) % mod; // Update answer with modulo
	        }
	        
	       // then return
	       return;
	   }
	   
	   // add the current element in the count
	   count += arr[i];
	   getCount(arr, i + 1, n, sum, count, ans);
	   
	   // when backtracking just remove the current element from
	   // the tatal sum till now to get the sum of the element
	   // till i - 1 and not including the arr[i] now
	   count -= arr[i];
	   getCount(arr, i + 1, n, sum, count, ans);
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int ans = 0;
        getCount(arr, 0, n, sum, 0, ans);
        
        return ans;
	}
	  
};