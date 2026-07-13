class Solution {
private:
    vector<string> ans;
    string curr;

    vector<string> keypad = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

public:

    void dfs(string& digits, int index, string& curr)
    {

        if(curr.size()==digits.size())
        {
            ans.push_back(curr);
            return;
        }

        for(char c: keypad[digits[index]-'0'])
        {
            curr.push_back(c);

            dfs(digits, index+1, curr);

            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

    // fallback corner case
     if(digits.empty())
     return {};

    dfs(digits, 0, curr);

    return ans;

    }
};
