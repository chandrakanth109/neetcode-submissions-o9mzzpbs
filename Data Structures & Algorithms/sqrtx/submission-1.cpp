class Solution {
public:
    int mySqrt(int x) {
        int start=1;
        int end=x;

        int mid=start+(end-start)/2;

        int ans=0;

        while(start <= end) {
            long long square = 1LL * mid * mid;
            if(square==x){
                return mid;
            }
            else if(square  < x){
                ans=mid;
                start=mid+1;
            } else {
                //ans=mid;
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
};