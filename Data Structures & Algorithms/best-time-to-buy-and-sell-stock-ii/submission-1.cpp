class Solution {
public:

    int solve(vector<int>& arr,int i,int buy,vector<vector<int>>& dp) {
        if(i >= arr.size()){
            return 0;
        }

        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }

        int maxi=INT_MIN;
        if(buy) {
            int buyNow=-arr[i]+solve(arr,i+1,0,dp);
            int skip=solve(arr,i+1,1,dp);
            maxi=max(buyNow,skip);
        } else {
            int sellnow=arr[i] + solve(arr,i+1,1,dp);
            int skip=solve(arr,i+1,0,dp);
            maxi=max(sellnow,skip);
        }
        return dp[i][buy]=maxi;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};