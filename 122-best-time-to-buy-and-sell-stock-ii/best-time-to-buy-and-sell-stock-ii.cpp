class Solution {

private:
    // Memoization 
    int f(int ind, int buy, vector<int>& prices, int n, vector<vector<int>>&dp){
        if(ind==n) return 0;
        int profit = 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        if(buy){ //buy mode on
            profit = max((-prices[ind]+f(ind+1,0,prices,n,dp)),(0+f(ind+1,1,prices,n,dp)));
        }
        else { //sale mode only
            profit = max((0+f(ind+1,0,prices,n,dp)),(prices[ind]+f(ind+1,1,prices,n,dp)));
        }
        return dp[ind][buy] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,0));
        //return f(0,1,prices,n,dp);
        dp[n][0] = dp[n][1] = 0;

        for(int ind = n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
            int profit  = 0;
            if(buy){ //buy mode on
            profit = max((-prices[ind]+dp[ind+1][0]),(0+dp[ind+1][1]));
            }
            else { //sale mode only
            profit = max((0+dp[ind+1][0]),(prices[ind]+dp[ind+1][1]));
            }
            dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};