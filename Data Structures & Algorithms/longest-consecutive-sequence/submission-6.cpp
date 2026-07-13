class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) {
            return 0;
        }
        vector<int> ans;
        sort(nums.begin(),nums.end());
        ans.push_back(nums[0]);
        int maxi=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==nums[i-1]) continue;

            if(abs(nums[i]-ans.back())==1){
                ans.push_back(nums[i]);
            } else {
                maxi=max(maxi,(int)ans.size());
                ans.clear();
                ans.push_back(nums[i]);
            }
        }

        return maxi = max(maxi, (int)ans.size());
    }
};
