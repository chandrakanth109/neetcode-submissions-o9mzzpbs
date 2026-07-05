class Solution {
public:
    int maxLen=0;
    int startInd=0;

    void expand(string& s,int i,int j) {
        
        while(i >= 0 && j < s.size() && s[i]==s[j]) {
            int len=j-i+1;

            if(maxLen < len) {
                maxLen=len;
                startInd=i;
            }

            i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
        for(int i=0;i<s.size();i++) {
            expand(s,i,i);
            expand(s,i,i+1);
        }

        return s.substr(startInd,maxLen);
    }
};
