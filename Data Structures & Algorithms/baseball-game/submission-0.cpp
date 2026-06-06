class Solution {
   public:
    int calPoints(vector<string>& operations) {
        stack<int> s;

        for (auto it : operations) {
            // if(!isalnum(it))
            // continue;

            if (it == "+") {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.push(x);
                s.push(x + y);
            } else if (it == "D") {
                s.push(char(2 * int(s.top())));
            } else if (it == "C" && !s.empty())
                s.pop();
            else {
                s.push(stoi(it));
            }
        }

        int res = 0;
        while (!s.empty()) {
            res += int(s.top());
            s.pop();
        }

        return res;
    }
};