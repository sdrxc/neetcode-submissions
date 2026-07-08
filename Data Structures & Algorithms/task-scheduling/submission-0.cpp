class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26,0);

        for(char c: tasks)
        {
            freq[c-'A']++;
        }

        int max_freq = *max_element(freq.begin(), freq.end());

        int count_max = 0;

        for(int x : freq)
        {
            if(x==max_freq)
            count_max++;
        }

        return max((int)tasks.size(), (max_freq-1)*(n+1)+count_max);
    }
};
