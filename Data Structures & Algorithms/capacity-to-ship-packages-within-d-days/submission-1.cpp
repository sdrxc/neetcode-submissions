class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        // least weight capacity/day  = Largest weight present || MIN RANGE
        int left = *max_element(weights.begin(), weights.end());

        // least weight capacity/day  = Total Weight (one day) || MAX RANGE
        int right = accumulate(weights.begin(),
                               weights.end(),
                               0);

        while(left<right)
        {
            int mid = left + (right - left) / 2;
            int days_needed = 1; // min 1 day @ LWC = total wt
            int curr_load = 0;

            for(auto it: weights)
            {
                if(curr_load + it > mid)
                {
                    days_needed++;
                    curr_load = 0;
                }

                curr_load +=it;
            }

            if(days_needed <= days)
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }

        return left;
    }
};