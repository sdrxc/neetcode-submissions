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
        
        if(intervals.empty())
        return 0;

        // sort by start time
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b)
        {
            return a.start < b.start;
        });

        // Min heap stores end time
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(auto interval : intervals)
        {
            // if the earliest room if free -> resuse that room

            if(!min_heap.empty() && 
                min_heap.top() <= interval.start)
                {
                    min_heap.pop();
                }

            // occupy a room with this meeting
            min_heap.push(interval.end);
        }       
        
        
        return min_heap.size();

    }
};
