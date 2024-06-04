class Solution {
private:
    // Memoization
    int f(int ind, vector<int>&cost, int n, vector<int>&dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int price=INT_MAX;
        price = min(cost[ind]+f(ind+1,cost,n,dp),cost[ind]+f(ind+2,cost,n,dp));
        return dp[ind] = price;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+2,0);

        // tabulation
        for(int ind=n-1;ind>=0;ind--){
            int price=INT_MAX;
            price = min(cost[ind]+dp[ind+1],cost[ind]+dp[ind+2]);
            dp[ind] = price;
        }
       // return min(f(0,cost,n,dp),f(1,cost,n,dp));
       return min(dp[0],dp[1]);
    }
};