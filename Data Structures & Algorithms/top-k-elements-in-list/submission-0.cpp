class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // num, count
        unordered_map<int,int> um;
        for(auto it: nums)
        um[it]++;
        
        // Min-heap to keep top k elements
        using pii = pair<int, int>; // {frequency, number}
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        
        for (auto& [key, value] : um) {
            pq.push({value, key});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;

     }
};