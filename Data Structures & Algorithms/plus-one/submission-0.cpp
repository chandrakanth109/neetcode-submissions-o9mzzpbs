class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;

        int carry=1;
        reverse(digits.begin(),digits.end());

        int i=0;
        while(i<digits.size()){
            int sum=digits[i]+carry;
            carry=sum/10;
            int last=sum%10;
            ans.push_back(last);
            i++;
        }

        if(carry){
            ans.push_back(carry);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
