class Solution {
private:
    int triangle(int first, int second){
        int diff=1;
        int total=0;

        while(first>=0 && second>=0){
            if(diff%2) first-=diff;
            else second-=diff;
            if(first<0 || second<0) return total;

            total+=1;
            diff+=1;
        }
        return total;
    }
public:
    int maxHeightOfTriangle(int red, int blue) {
        int res = max(triangle(red,blue),triangle(blue,red));
        return res;
    }
};