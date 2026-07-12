class Solution {
private: 
    vector<string> res;
public:
    void parenthesis(string curr, int open, int close, int n)
    {
        if(curr.size()==2*n)
        {
            res.push_back(curr);
            return;
        }

        // add '('
        if(open < n)
            parenthesis(curr+"(", open +1, close, n);

        // add ')'
        if(close < open)
        parenthesis(curr+")", open, close +1, n);

    }
    vector<string> generateParenthesis(int n) {
        parenthesis("",0,0, n);
        return res;
    }
};
