class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
        string result = "";
        int cycle = 2*numRows-2;
        for(int i=0;i<numRows;i++){
            for(int j=i;j<s.length();j+=cycle){
                result+=s[j];
                int secondj=(j+cycle)-2*i;
                if(i!=0 && i!=numRows-1 && secondj<s.length()) result+=s[secondj];
            }
        }
        return result;
    }
};