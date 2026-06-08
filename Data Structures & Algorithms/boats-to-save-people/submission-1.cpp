class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boat_count=0;
        int left = 0, right = people.size()-1;

        while(left<=right)
        {
            if(people[left]+people[right]<=limit)
            {
                left++;
                right--;
            }
            else
            {
                right--;
            }

            boat_count++;
        }

        return boat_count;
    }
};