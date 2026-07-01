class Solution {
public:

    void solve(vector<int>& nums,int k) {
        if(k == 0){
            return;
        }

        int ele=nums.back();
        nums.pop_back();
        nums.insert(nums.begin(), ele);

        solve(nums,k-1); 
    }
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        solve(nums,k);
    }
};