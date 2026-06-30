class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        freq[0]=1;

        int count=0;
        int left=0;
        int preSum=0;

        for(int right=0;right<nums.size();right++) {
            preSum+=nums[right];

            if(freq.find(preSum-k)!=freq.end()){
                count+=freq[preSum-k];
            }

            freq[preSum]++;
        }
        return count;
    }
};