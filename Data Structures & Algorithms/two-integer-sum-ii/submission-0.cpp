class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        unordered_map<int,int> um;

        for(int i=0;i<numbers.size();i++)
        {
            int rem = target - numbers[i];
            if(um.count(rem))
            {
                return {um[rem]+1,i+1};
            }

            um[numbers[i]] = i;
        }
        
        return {-1,-1};
    }
};
