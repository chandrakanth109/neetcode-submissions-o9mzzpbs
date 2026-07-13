class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())
            return 1;

        sort(nums.begin(), nums.end());

        int expected = 1;

        for(int num : nums) {

            if(num <= 0)
                continue;

            if(num == expected)
                expected++;

            else if(num > expected)
                return expected;
        }

        return expected;
    }
};