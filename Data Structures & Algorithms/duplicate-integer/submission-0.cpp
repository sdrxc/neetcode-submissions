class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

       unordered_map<int, int> um;

       for(auto it: nums)
       {
        if(um[it]==1)
        {
            return true;
        }
        
        um[it]++;
       } 

       return false;
    }
};