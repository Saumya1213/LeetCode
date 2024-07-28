class Solution {
private:
    static bool compareDescending(int a, int b) {
    return a > b; // Descending order comparison
}
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), compareDescending);
        sort(verticalCut.begin(), verticalCut.end(), compareDescending);

        long long i = 0, j = 0;
        long long rowcount = 1, colcount = 1;
        long long res = 0;

        while(i<m-1 && j<n-1){
            if(horizontalCut[i]>=verticalCut[j]){
                res+=colcount*horizontalCut[i];
                i++; rowcount++;
            }

            else{
                res+=rowcount*verticalCut[j];
                j++; colcount++;
            }
        }

        while(i<m-1){
                res+=colcount*horizontalCut[i];
                i++; rowcount++;
            }

        while(j<n-1){
                res+=rowcount*verticalCut[j];
                j++; colcount++;
            }

            return res;
    }
};