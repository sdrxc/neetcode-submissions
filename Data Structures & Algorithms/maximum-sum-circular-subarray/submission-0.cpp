class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        // int total_sum = accumulate(nums.begin(), nums.end(),0);


        int global_max = nums[0];
        int local_max = nums[0];

        int global_min = nums[0];
        int local_min = nums[0];


        int total_sum=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            int x_i = nums[i];
            total_sum+=x_i;


            // Kadane for max
            local_max = max(local_max + x_i, x_i);
            global_max = max(global_max, local_max);


            // Kadane for min
            local_min = min(local_min + x_i, x_i);
            global_min = min(global_min, local_min);
        }

        // ❗ edge case: all numbers negative
        if(global_max <0)
        {
            return global_max;
        }

        return max(global_max, total_sum-global_min);

    }
};