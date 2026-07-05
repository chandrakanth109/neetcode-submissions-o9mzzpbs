class Solution {
public:
    int solve(vector<int>& arr,int i,vector<int>& dp) {
        if(i >= arr.size()){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int pick=arr[i] + solve(arr,i+2,dp);
        int notPick = 0 + solve(arr,i+1,dp);

        return dp[i]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,0,dp);
    }
};
