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
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.start < b.start;
        }); 
        int n = intervals.size(); 
        if(n == 0) return 0; 
        int ans = 0; 
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i<n; i++) {
           if(!pq.empty() && pq.top() <= intervals[i].start) {
                pq.pop(); 
                pq.push(intervals[i].end);
            }
           else {
                ans++; 
                pq.push(intervals[i].end);
            }
        }
        return ans;
    }
};
