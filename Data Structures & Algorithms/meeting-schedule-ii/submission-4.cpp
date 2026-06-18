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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start(n); 
        vector<int> end(n); 
        for(int i = 0; i<n; i++) {
            start[i] = intervals[i].start; 
            end[i] = intervals[i].end; 
        }
        sort(start.begin(), start.end()); 
        sort(end.begin(), end.end()); 
        int s = 0; 
        int e = 0; 
        int res = 0; 
        int count = 0;
        while(s<n) {
            if(start[s] < end[e]) {
                s++; 
                count++; 
            }
            else {
                e++; 
                count--;
            }
            res = max(res, count);
        }
        return res;
    }
};
