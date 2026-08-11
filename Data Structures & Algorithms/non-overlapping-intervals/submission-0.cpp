class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int count =1;
        int last_end = intervals[0][1];

        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] >= last_end)
            {
                // no overlap
                count++;
                last_end = intervals[i][1];
            }
        }

        return intervals.size()- count;
    }
};
