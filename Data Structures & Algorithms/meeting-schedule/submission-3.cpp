/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:

    static bool cpm(Interval a,Interval b) {
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==0) {
            return true;
        }
        sort(intervals.begin(),intervals.end(),cpm);
        vector<int> ans;
        ans.push_back(intervals[0].end);

        for(int i=1;i<intervals.size();i++) {
            if(ans.back() > intervals[i].start) {
                return false;
            } else {
                ans.push_back(intervals[i].end);
            }
        }

        return true;
    }
};
