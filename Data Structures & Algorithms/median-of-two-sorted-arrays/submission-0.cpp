class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        for (auto it : nums2)
            nums1.push_back(it);

        sort(nums1.begin(), nums1.end());

        int total = nums1.size();
        int mid = total / 2;

        if (total % 2 == 0) {
            return (nums1[mid] + nums1[mid - 1]) / 2.0;
        }

        return nums1[mid];
    }
};