class Solution {
   public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string curr = "";
        int num = 0;

        for (auto it : s) {
            if (isdigit(it)) {
                num = num * 10 + (it - '0');
            } else if (it == '[') {
                countStack.push(num);
                stringStack.push(curr);

                num = 0;
                curr = "";
            } else if (it == ']') {
                int repeat = countStack.top();
                countStack.pop();

                string prev = stringStack.top();
                stringStack.pop();

                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += curr;
                }

                curr=prev+temp;
            }
            else
            {
                curr+=it;
            }
        }

        return curr;
    }
};