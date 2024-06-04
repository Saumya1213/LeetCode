class Solution {
private:
    // Memoization function
    
    int f(int ind, int k, vector<int>&arr, int n, vector<int>&dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int res = 0; 
        int curMax=0;
        int len=0;
        for(int i=ind;i<min(ind+k,n);i++){
            
            curMax = max(arr[i],curMax);
            len++;
            int sum = len*curMax + f(i+1,k,arr,n,dp);
            res = max(sum,res);
            
        }
        return dp[ind] = res;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        //vector<int>dp(n,-1); Memoization dp vector
        vector<int>dp(n+1,0);

        // Tabulation approach
        for(int ind=n-1;ind>=0;ind--){
            int res = 0; 
            int curMax=0;
            int len=0;

            for(int i=ind;i<min(ind+k,n);i++){
            
            curMax = max(arr[i],curMax);
            len++;
            int sum = len*curMax + dp[i+1];
            res = max(sum,res);
            
        }
        dp[ind] = res;
        }

        return dp[0];

        // return f(0,k,arr,dp); memoization function call 
    }
};