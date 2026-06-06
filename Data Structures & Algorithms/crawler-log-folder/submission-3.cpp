class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;

        for(auto it: logs)
        {
            if(it == "../" && !s.empty())
            s.pop();
            else if(it =="./" || it=="../")
            continue;
            else
            s.push(it);
        }

        return s.size();
    }
};