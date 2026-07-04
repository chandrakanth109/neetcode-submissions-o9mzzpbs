class Solution {
   public:
    bool solve(vector<int>& nums, vector<bool>& used, int start, int currSum, int target, int k) {
        if (k == 1) return true;

        if (currSum == target) {
            return solve(nums, used, 0, 0, target, k-1);
        }

        for (int i = start; i < nums.size(); i++) {
            if (used[i]) continue;

            if (currSum + nums[i] > target) continue;

            used[i] = true;

            if (solve(nums, used, i + 1, currSum+nums[i], target, k)) {
                return true;
            }

            used[i] = false;
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % k != 0) {
            return false;
        }
        int target = total / k;
        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target) {
            return false;
        }

        vector<bool> used(nums.size(), false);

        return solve(nums, used, 0, 0, target, k);
    }
};