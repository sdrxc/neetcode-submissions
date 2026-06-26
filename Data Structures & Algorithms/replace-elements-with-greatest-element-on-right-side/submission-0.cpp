class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        vector<int> res;
        res.push_back(-1);

        int n = arr.size();
        int local_max = arr[n-1];

        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>local_max)
            {
                res.push_back(local_max);
                local_max = arr[i];
            }
            else
            {
            res.push_back(local_max);
            }
            
        }

        reverse(res.begin(), res.end());
        return res;
    }
};