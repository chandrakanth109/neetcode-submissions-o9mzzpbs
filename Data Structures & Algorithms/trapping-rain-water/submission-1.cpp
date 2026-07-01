class Solution {
public:
    int solve(vector<int>& arr){
        int n=arr.size();
        int left=0;
        int right=n-1;
        int maxLeft=arr[0];
        int maxRight=arr[n-1];

        int water=0;

        while(left <= right) {
            if(arr[left] <= arr[right]){
                if(maxLeft < arr[left]){
                    maxLeft=arr[left];
                } else {
                    water+=maxLeft-arr[left];
                }
                left++;
            } else {
                if(maxRight < arr[right]){
                    maxRight=arr[right];
                } else {
                    water+=maxRight-arr[right];
                }
                right--;
            }
        }
        return water;
    }
    int trap(vector<int>& height) {
        return solve(height);
    }
};
