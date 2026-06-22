class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;

        while(left<=right)
        {
            long long mid = left + (right-left)/2;
            long long val = mid*mid;

            if(val<=(long long)(x))
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }

        return right;
    }
};