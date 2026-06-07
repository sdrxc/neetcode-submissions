class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();

        string res;
        int i=0;
        for(;i<min(m,n);i++)
        {
            res+=word1[i];
            res+=word2[i];
        }

        if(m>n)
        {
            for(;i<m;i++)
            {
                res+=word1[i];
            }
        }
        else
        {
            for(;i<n;i++)
            {
                res+=word2[i];
            }
        }
        return res;

    }
};