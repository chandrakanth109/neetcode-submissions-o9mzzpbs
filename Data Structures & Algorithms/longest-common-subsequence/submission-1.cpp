class Solution {
public:

    int solve(string& s1,string& s2,int i,int j,int n,int m,vector<vector<int>>& dp) {
        if(i >= n || j >= m) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;
        if(s1[i]==s2[j]) {
            ans=1+solve(s1,s2,i+1,j+1,n,m,dp);
        } else {
            ans=max(solve(s1,s2,i+1,j,n,m,dp),solve(s1,s2,i,j+1,n,m,dp));
        }

        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(text1,text2,0,0,n,m,dp);
    }
};
