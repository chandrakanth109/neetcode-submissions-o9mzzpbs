class Solution {
public:

    int solve(string& s1,string& s2,int i,int j,vector<vector<int>>& dp) {
        if(i >= s1.length() && j >= s2.length()){
            return 0;
        }

        if(i >= s1.length() && j < s2.length()){
            return s2.length()-j;
        }

        if(i < s1.length() && j >= s2.length()){
            return s1.length()-i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s1[i]==s2[j]){
            return solve(s1,s2,i+1,j+1,dp);
        }

       
            int insert=1+solve(s1,s2,i+1,j,dp);
            int del=1+solve(s1,s2,i+1,j+1,dp);
            int rep=1+solve(s1,s2,i,j+1,dp);

            return dp[i][j]=min({insert,del,rep});
        
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};
