class Solution {
public:
    int maxArea(vector<int>& heights) {

        int max_water = INT_MIN;
        int right = heights.size()-1;
        int left = 0;


        while(left < right)
        {   
            int optimized_height = min(heights[left], heights[right]);
            int width = right - left;
            max_water = max(max_water, (optimized_height * width));

            if(heights[left] < heights[right])
            {
                left++;
            }
            else
            {   
                right--;
            }
        }

        return max_water;

    }
};
