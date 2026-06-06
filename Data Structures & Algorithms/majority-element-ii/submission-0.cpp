class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0; // Counters for the potential majority elements
        int candidate1 = 0, candidate2 = 0; // Potential majority element candidates
        int threshold = nums.size() / 3; // Threshold for majority element

        for(auto it: nums)
        {
            if(count1==0 && it!=candidate2)
            {
                count1=1;
                candidate1=it;
            }
            else if(count2==0 && it!=candidate1)
            {
                count2=1;
                candidate2=it;
            }
            else if(candidate1==it)
            count1++;
            else if(candidate2==it)
            count2++;
            else
            {
                count1--;
                count2--;
            }
        }

        vector<int> res;
        count1=0, count2=0;
        for(auto it: nums)
        {
            if(it==candidate1)
            count1++;
            if(it==candidate2)
            count2++;
        }

        if(count1 > threshold)
        res.push_back(candidate1);
        if(count2 > threshold)
        res.push_back(candidate2);   

        return res;
        

    }
};