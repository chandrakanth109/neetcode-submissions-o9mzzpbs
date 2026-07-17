class Solution {
public:

    int solve(vector<int>& arr,int i,int total) {
        if(i >= arr.size() || total < 0) {
            return INT_MAX;
        }

        if(total==0) {
            return 0;
        }


        int pick=INT_MAX;
        if(total-arr[i] >= 0) {
            int ans=solve(arr,i,total-arr[i]);
            if(ans!=INT_MAX){
                pick=1+ans;
            }
        }
        int notPick=solve(arr,i+1,total);

        return min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
         int ans=solve(coins,0,amount);
         if(ans==INT_MAX) {
            return -1;
         }
         return ans;
    }
};
