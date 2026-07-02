class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int preSum=0;
        int minLen=INT_MAX;
        int left=0;

        for(int right=0;right<nums.size();right++) {
            preSum+=nums[right];

            while(preSum >= target){
                minLen=min(minLen,right-left+1);
                preSum-=nums[left];
                left++;
            }

            
        }
         return minLen==INT_MAX ? 0 : minLen;
    }
};