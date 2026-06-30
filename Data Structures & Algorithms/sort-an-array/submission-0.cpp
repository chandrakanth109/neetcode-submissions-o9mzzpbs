class Solution {
public:

    void Merge(vector<int>& arr,int start,int end) {
        int mid=start+(end-start)/2;

        int len1=mid-start+1;
        int len2=end-mid;

        vector<int> leftArr(len1);
        vector<int> rightArr(len2);

        int k=start;
        for(int i=0;i<len1;i++){
            leftArr[i]=arr[k++];
        }
        k=mid+1;
        for(int i=0;i<len2;i++){
            rightArr[i]=arr[k++];
        }

        int leftInd=0;
        int rightInd=0;
        int startInd=start;

        while(leftInd < len1 && rightInd < len2) {
            if(leftArr[leftInd] <= rightArr[rightInd]){
                arr[startInd++]=leftArr[leftInd++];
            } else {
                arr[startInd++]=rightArr[rightInd++];
            }
        }

        while(leftInd < len1){
            arr[startInd++]=leftArr[leftInd++];
        }

        while(rightInd < len2){
            arr[startInd++]=rightArr[rightInd++];
        }

    }
    void solve(vector<int>& arr,int start,int end) {
        if(start >= end){
            return;
        }

        int mid=start+(end-start)/2;
        solve(arr,start,mid);
        solve(arr,mid+1,end);
        Merge(arr,start,end);
    } 
    vector<int> sortArray(vector<int>& nums) {
        
        solve(nums,0,nums.size()-1);

        return nums;
    }
};