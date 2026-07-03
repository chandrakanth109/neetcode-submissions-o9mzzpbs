class Solution {
public:

    bool isPoss(vector<int>& arr,int mid,int days) {
        int count=1;
        int weight=0;
        for(int i=0;i<arr.size();i++) {
            if(weight+arr[i] <= mid){
                weight+=arr[i];
            } else {
                count++;
                if(count > days || arr[i] > mid){
                    return false;
                } else {
                    weight=arr[i];
                }
            }
        }

        return count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int start=0;
        int end=accumulate(weights.begin(),weights.end(),0);
        int mid=start+(end-start)/2;
        int ans=-1;

        while(start <= end) {
            if(isPoss(weights,mid,days)){
                ans=mid;
                end=mid-1;
            } else {
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }

        return ans;
    }
};