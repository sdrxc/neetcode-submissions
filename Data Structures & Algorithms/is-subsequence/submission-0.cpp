class Solution {
public:

    bool isSubSeqRec(string& s, string& t, int m, int n){
        
        // Base Cases
        if (m == 0)
            return true;
        if (n == 0)
            return false;

        // If last characters match
        if (s[m - 1] == t[n - 1])
            return isSubSeqRec(s, t, m - 1, n - 1);

        // If last characters don't match
        return isSubSeqRec(s, t, m, n - 1);
    }

    bool isSubSeq(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        if(m > n)
        return false;

        return isSubSeqRec(s, t, m, n);

    }
    bool isSubsequence(string s, string t) {
        if (isSubSeq(s, t))
        return true;
        else
        return false;
    }
};