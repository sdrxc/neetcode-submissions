class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right = *max_element(piles.begin(), piles.end());

        while(left<right)
        {
             int mid = left + (right - left) / 2;
             int total_hrs = 0;        

             for(int it: piles)
             {
                // same as ceil(pile / mid)
                total_hrs += (it+mid-1)/mid;
             }  

             if(total_hrs <=h)
             {
                right = mid;
             }
             else{
                left = mid+1;
             }

        }

        return left;
    }
};
