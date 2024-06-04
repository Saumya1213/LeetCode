class Solution {
private:
    int f(int ind, int prev_ind, vector<int>& arr, int n, vector<vector<int>>&dp) {
        
        if (ind == n) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];

        int len = f(ind + 1, prev_ind, arr, n,dp);
        if (prev_ind == -1 || arr[ind] > arr[prev_ind]) {
            len = max(len, (1 + f(ind + 1, ind, arr, n,dp)));
        }

        return dp[ind][prev_ind+1]=len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>next(n+1,0), curr(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){

               int len = next[prev_ind+1];
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    len = max(len, (1 + next[ind+1]));
                }

                curr[prev_ind+1]=len;

            }
            next=curr;
        }
        return curr[0];
    }
};