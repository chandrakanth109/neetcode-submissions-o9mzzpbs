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
    static bool compare(Interval& a,Interval& b){
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==0) return 0;

        sort(intervals.begin(),intervals.end(),compare);

        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(intervals[0].end);

        for(int i=1;i<intervals.size();i++) {
            if(pq.top() <= intervals[i].start){
                pq.pop();
            }

            pq.push(intervals[i].end);
        }

        return pq.size();
    }
};
