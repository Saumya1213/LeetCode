class Solution {
private:
    // Memoization
    int f(int i, int j, vector<int> &values, vector<vector<int>>&dp){
        if(i+1==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for(int k=i+1;k<j;k++){
            ans = min(ans,values[i]*values[j]*values[k]+f(i,k,values,dp)+f(k,j,values,dp));
        }
        return dp[i][j] = ans;
    }
public: 
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();

        // Tabulation
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){
                int ans = INT_MAX;
                for(int k=i+1;k<j;k++){
                    ans = min(ans,values[i]*values[j]*values[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j] = ans;
                }
        }

        return dp[0][n-1];
    }
};