class Solution {
private:
    // Memoization
    int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=0+f(i-1,j-1,s1,s2,dp);
        else return dp[i][j]=min(1+f(i-1,j,s1,s2,dp),min((1+f(i-1,j-1,s1,s2,dp)),(1+f(i,j-1,s1,s2,dp))));
    }

public:
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        //vector<vector<int>>dp(n,vector<int>(m,-1)); dp vector for memoization

        //vector<vector<int>>dp(n+1,vector<int>(m+1,0)); dp table for tabulation

        vector<int> prev(m+1,0), curr(m+1,0);
        for(int j=0;j<=m;j++) prev[j] = j;

        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) curr[j]=0+prev[j-1];
                else curr[j]=min(1+prev[j],min((1+prev[j-1]),(1+curr[j-1])));
            }
            prev = curr;
        }
        //return f(n-1,m-1,s1,s2,dp); call for memoization
        return prev[m];
    }
};