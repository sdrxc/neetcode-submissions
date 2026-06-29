class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //  nums = [2, 2, 2, 3, 4, 2]
        // target = 3
        // Now nums[left] == nums[mid], but you can’t tell if the left or right half is sorted.

        // ✅ Solution Strategy with Duplicates
        // 	1. If nums[left] == nums[mid] == nums[right], you can't determine which side is sorted.
        // 		○ So: shrink the search space: left += 1 and right -= 1
        // 	2. Else:
        // Proceed with normal binary search logic as before.       

        int left = 0, right = nums.size() - 1;
        while(left<=right)
        {
            int mid = left+(right-left)/2;

            if(nums[mid]==target)
            return true;

            if(nums[mid]==nums[left] && nums[mid]==nums[right])
            {
                left+=1;
                right-=1;
            }
            else if(nums[left]<=nums[mid])
            {
                // Target is in the left half
                if(nums[left]<=target && target<nums[mid])
                {
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else{
                // Target is in the right half
                if(nums[mid]<target && target<=nums[right])
                {
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }

        }

        return false;
    }


};