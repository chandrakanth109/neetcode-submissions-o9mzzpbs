class Solution {
public:

    void solve(vector<vector<int>>& intervals,int q,vector<int>& ans) {
        
        int mini=INT_MAX;
        for(auto interval:intervals) {
            if(interval[0] <= q && q <= interval[1]) {
                int len=interval[1]-interval[0]+1;
                mini=min(mini,len);
            }
        }

        if(mini==INT_MAX){
            mini=-1;
        }
        ans.push_back(mini);
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        vector<int> ans;

        for(int i=0;i<queries.size();i++) {
            solve(intervals,queries[i],ans);
        }

        return ans;
    }
};
