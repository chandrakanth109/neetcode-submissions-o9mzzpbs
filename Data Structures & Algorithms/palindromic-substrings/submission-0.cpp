class Solution {
public:
    int expand(int start,int end,string& s) {
        int count=0;
        while(start >=0 && end < s.length() && s[start]==s[end]){
            count++;
            start--;
            end++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int total=0;

        int n=s.length();
        for(int i=0;i<n;i++) {
            total+=expand(i,i,s);

            total+=expand(i,i+1,s);
        }

        return total;
    }
};
