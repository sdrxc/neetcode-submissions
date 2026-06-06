class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int subarr_count =0;
        unordered_map<int,int> um;
        um[0] = 1;
        int prefix_sum = 0;
        for(int i=0;i<nums.size();i++)
        {   
            prefix_sum+=nums[i];
            int remainder  = prefix_sum -k;
            subarr_count+=um[remainder];
            um[prefix_sum]++;
        }

        return subarr_count;
    }
};