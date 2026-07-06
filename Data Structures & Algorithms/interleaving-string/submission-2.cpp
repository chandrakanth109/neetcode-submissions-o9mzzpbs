class Solution {
public:

    bool solve(string& s1, string& s2, string& s3,int i,int j) {
        int k=i+j;

        if(k==s3.size()) {
            return true;
        }

        bool ans=false;

        if(i< s1.size() && s1[i]==s3[k]){
            ans=ans || solve(s1,s2,s3,i+1,j);
        }

        if(j< s2.size() && s2[j]==s3[k]){
            ans=ans || solve(s1,s2,s3,i,j+1);
        }

        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        
        return solve(s1,s2,s3,0,0);
    }
};
