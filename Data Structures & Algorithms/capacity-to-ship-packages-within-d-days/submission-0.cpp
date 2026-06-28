class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end());

        int right = accumulate(weights.begin(),
                               weights.end(),
                               0);

        while(left < right)
        {
            int mid = left + (right - left) / 2;

            int daysNeeded = 1;
            int currLoad = 0;

            for(int w : weights)
            {
                if(currLoad + w > mid)
                {
                    daysNeeded++;
                    currLoad = 0;
                }

                currLoad += w;
            }

            if(daysNeeded <= days)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};