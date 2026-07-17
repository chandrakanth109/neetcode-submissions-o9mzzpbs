class Solution {
public:

    int solve(vector<int>& arr,int i,int total,vector<vector<int>>& dp) {
        if(i >= arr.size() || total < 0) {
            return INT_MAX;
        }

        if(total==0) {
            return 0;
        }

        if(dp[i][total]!=-1){
            return dp[i][total];
        }

        int pick=INT_MAX;
        if(total-arr[i] >= 0) {
            int ans=solve(arr,i,total-arr[i],dp);
            if(ans!=INT_MAX){
                pick=1+ans;
            }
        }
        int notPick=solve(arr,i+1,total,dp);

        return dp[i][total]=min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
         int ans=solve(coins,0,amount,dp);
         if(ans==INT_MAX) {
            return -1;
         }
         return ans;
    }
};
