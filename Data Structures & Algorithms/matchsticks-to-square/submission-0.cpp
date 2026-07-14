class Solution {
public:

    bool dfs(vector<int>& nums,
             vector<int>& sides,
             int index,
             int target)
    {
        if(index==nums.size())
        {
            return true;
        }

        for(int i=0;i<4;i++)
        {
            if(sides[i]+nums[index]>target)
            continue;

            sides[i]+=nums[index];

            if(dfs(nums,
                    sides,
                    index+1,
                    target))
            {
                return true;
            }

            sides[i]-=nums[index];

            //optimization 
            if(sides[i]==0)
            break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(),0);

        if(sum%4!=0)
        return false;

        int target = sum/4;

        // sort in desc
        sort(matchsticks.rbegin(), matchsticks.rend());

        vector<int> sides(4,0);

        return dfs(matchsticks,
                    sides,
                    0,
                    target);
    }
};