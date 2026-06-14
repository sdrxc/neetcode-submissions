class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;


        vector<int> s1Freq(26, 0);
        vector<int> windowFreq(26, 0);

        for (char c : s1)
        s1Freq[c - 'a']++;

        for(int i=0;i<n;i++)
        windowFreq[s2[i]-'a']++;
        

        if(s1Freq==windowFreq)
        return true;

        for(int r=n;r<m;r++)
        {   
            windowFreq[s2[r]-'a']++;
            windowFreq[s2[r-n]-'a']--;

            if(s1Freq==windowFreq)
            return true;
        }

        return false;

    }
};
