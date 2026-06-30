class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;   // double ended-q stores indices
        vector<int> ans; // stores ans        

        for (int i = 0; i < nums.size(); i++) {
        
            // Step 1: Remove out-of-window elements from the front
            while(!dq.empty() && dq.front() == i -k)
            dq.pop_front();

            // Remove all elements smaller than current from the back
            while(!dq.empty() && nums[i] > nums[dq.back()])
            dq.pop_back();

            
            // regular
            dq.push_back(i);

            // first window push and other window pushes
            if(i >= k-1)
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
