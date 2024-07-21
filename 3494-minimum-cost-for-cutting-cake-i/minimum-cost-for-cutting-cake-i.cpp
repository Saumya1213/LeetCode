class Solution {
public:
    static bool compareDescending(int a, int b) {
     return a > b; // Descending order comparison
    }
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), compareDescending);
        sort(verticalCut.begin(), verticalCut.end(), compareDescending);

        int i=0, j=0;
        int rowCount = 1, colCount = 1, res = 0;

        while(i<horizontalCut.size() && j<verticalCut.size()){
            if(horizontalCut[i]>=verticalCut[j]){
                res+=horizontalCut[i]*colCount;
                rowCount++;
                i++;
            }
            else if(horizontalCut[i]<=verticalCut[j]){
                res+=verticalCut[j]*rowCount;
                colCount++;
                j++;
            }
        }

        while(i<horizontalCut.size()){
            res+=horizontalCut[i]*colCount;
            rowCount++;
            i++;
        }

        while(j<verticalCut.size()){
            res+=verticalCut[j]*rowCount;
            colCount++;
            j++;
        }

        return res;
    }
};