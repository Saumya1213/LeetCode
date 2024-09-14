class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n=queries.size();
        priority_queue<int>dist;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            dist.push(abs(queries[i][0])+abs(queries[i][1]));
            if(dist.size()>k) dist.pop();
            res[i] = (dist.size()==k)?dist.top():-1;
        }
        return res;
    }
};