class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        // Sort intervals by starting point
        sort(intervals.begin(), intervals.end());

        // Store {query, original index}
        vector<pair<int,int>> sorted_queries;

        for(int i=0;i<queries.size();i++)
        sorted_queries.push_back({queries[i], i});

         // Sort queries by value
        sort(sorted_queries.begin(), sorted_queries.end());   
        

        // min heap for {lenght, end}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;


        // answer placeholder list with default set as -1
        vector<int> ans(queries.size(), -1);
    
        int i = 0;

        for(auto [q, index]: sorted_queries)
        {
             // Add every interval that starts before/equal to q
            while(i <intervals.size() && intervals[i][0] <=q)
            {
                int left = intervals[i][0];
                int right = intervals[i][1];

                int length = right-left +1;

                min_heap.push({length, right});

                i++;
            } 

            // Remove intervals that no longer contain q
            while (!min_heap.empty() &&
                   min_heap.top().second < q) {

                min_heap.pop();
            }

            //smallest valid interval
            if(!min_heap.empty())
            {
                ans[index]= min_heap.top().first;
            }            
        }

        return ans;

    }
};
