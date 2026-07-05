class Solution {
public:

    int solve(vector<int>& nums,int prev,int curr,vector<vector<int>>& dp) {
        if(curr >= nums.size()){
            return 0;
        }
        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }

        int pick=0;
        if(prev==-1 || nums[prev] < nums[curr]) {
            pick=1+solve(nums,curr,curr+1,dp);
        }
        int notPick=solve(nums,prev,curr+1,dp);

        return dp[prev+1][curr]=max(pick,notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int curr=0;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(nums,prev,curr,dp);
    }
};
