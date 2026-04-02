class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        sort(intervals.begin(),intervals.end());
        vector<int>& first=intervals[0];
        for(int i=1;i<intervals.size();i++){
            vector<int>& second=intervals[i];

            if(first[1] > second[0]){
                count++;

                if(first[1] > second[1]){
                    first=second;
                }
            } else {
                first=second;
            }
        }

        return count;
    }
};
