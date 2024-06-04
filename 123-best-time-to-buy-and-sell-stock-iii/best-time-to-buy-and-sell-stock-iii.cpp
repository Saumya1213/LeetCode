class Solution {
private: 
    // Memoization
    int f(int ind, int buy, int cap, vector<int>&prices,int n, vector<vector<vector<int>>>&dp){
        if(ind==n) return 0;
        if(cap==0) return 0;
        int profit = 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

        if(buy){
            profit = max((-prices[ind]+f(ind+1,0,cap,prices,n,dp)),(0+f(ind+1,1,cap,prices,n,dp)));
        }
        else{
            profit = max((prices[ind]+f(ind+1,1,cap-1,prices,n,dp)),(0+f(ind+1,0,cap,prices,n,dp)));
        }
        return dp[ind][buy][cap]=profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1))); for memoization

        //vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0))); for tabulation

        vector<vector<int>>after(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit = 0;
                    if(buy==1){
                        profit = max((-prices[ind]+after[0][cap]),(0+after[1][cap]));
                    }
                    else{
                        profit = max((prices[ind]+after[1][cap-1]),(0+after[0][cap]));
                    }
                    curr[buy][cap]=profit;
                }
            }
            after = curr;
        }
        return after[1][2];

        //return f(0,1,2,prices,n,dp);
    }
};