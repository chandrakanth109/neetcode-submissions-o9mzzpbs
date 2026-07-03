/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findPeak(MountainArray &mountainArr) {
        int start=0;
        int end=mountainArr.length()-1;

        while(start < end) {
            int mid=start+(end-start)/2;

            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                start=mid+1;
            } else {
                end=mid;
            }
        }
        return start;
    }
    int binaryAsc(MountainArray &mountainArr,int target,int start,int end) {
        while(start <= end) {
            int mid=start+(end-start)/2;
            int val=mountainArr.get(mid);

            if(val==target) {
                return mid;
            }
            if(val < target) {
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
    int binaryDesc(MountainArray &mountainArr, int target,int start,int end) {
        
        while(start <= end) {
            int mid=start+(end-start)/2;

            int val=mountainArr.get(mid);

            if(val==target){
                return mid;
            }
            if(val < target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int peak = findPeak(mountainArr);

        int ans=binaryAsc(mountainArr,target,0,peak);

        if(ans!=-1){
            return ans;
        }

        return binaryDesc(mountainArr,target,peak+1,mountainArr.length()-1);
    }
};