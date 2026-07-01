class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        int left=0;
        unordered_map<char,int> freq;

        for(int right=0;right<s.size();right++) {

            while(freq[s[right]] > 0) {

                freq[s[left]]--;

                if(freq[s[left]]==0){
                    freq.erase(s[left]);
                }
                left++;
            }

            freq[s[right]]++;
            maxLen=max(maxLen,right-left+1);
        }

        return maxLen;
    }
};
