class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==0) {
            return {};
        }
        int maxi=nums.size()/3;
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        vector<int> ans;
        for(auto it=mp.begin();it!=mp.end();it++) {
            if(it->second > maxi) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};