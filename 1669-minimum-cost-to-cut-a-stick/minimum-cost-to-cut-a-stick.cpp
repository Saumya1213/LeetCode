class Solution {
private:
    // Memoization function
    int f(vector<int>& cuts, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int ind=i;ind<=j;ind++){
            int cost = (cuts[j+1]-cuts[i-1])+f(cuts,ind+1,j,dp)+f(cuts,i,ind-1,dp);
            mini = min(cost,mini);
        }
        return dp[i][j]=mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        sort(cuts.begin(),cuts.end());

        // Tabulation
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j) continue;

                int mini = INT_MAX;
                for(int ind=i;ind<=j;ind++){
                    int cost = (cuts[j+1]-cuts[i-1])+dp[ind+1][j]+dp[i][ind-1];
                    mini = min(cost,mini);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
        
    }
};