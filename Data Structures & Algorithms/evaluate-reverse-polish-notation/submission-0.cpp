class Solution {
public:
    int evalRPN(vector<string>& tokens) {

    // Whenever you see a number:
        // Put it in the basket (stack)
    // Whenever you see an operator:
        // Take out the last two toys
        // Do the operation
    // Put the answer back

    stack<int> st;

    for(auto it: tokens)
    {
        if( it=="+" || it == "-" || it=="*" || it=="/")
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();
            
            if(it=="+")
            st.push(b+a);
            else if(it=="-")
            st.push(b-a);
            else if(it=="*")
            st.push(b*a);
            else
            st.push(b/a);

        }
        else
        {
            st.push(stoi(it));
        }
    }

    return st.top();

    }
};