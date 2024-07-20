class Solution {
public:
    string getSmallestString(string s) {
        int n=s.length();
        for(int i=0;i<n-1;i++){
            //if(s[i]=='0' || s[i+1]=='0') continue;
            if(s[i]>s[i+1] && s[i]%2 == s[i+1]%2){
                char t = s[i];
                s[i] = s[i+1];
                s[i+1] = t;
                break;
            }
        }

        return s;
    }
};