class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int candidate;
        int candidate_count=0;

        for(auto it: nums)
        {
            if(candidate_count==0)
            {
                candidate=it;
                candidate_count=1;
            }
            else if(it==candidate)
            candidate_count++;
            else
            candidate_count--;
        }

        int verify_count=0;
        for(auto it: nums)
        {
            if(it==candidate)
            verify_count++;
        }

        if(verify_count>n/2)
        return candidate;
        else
        return -1;
    }
};