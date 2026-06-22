class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int it : asteroids) {

            bool alive = true;

            while (alive &&
                   !st.empty() &&
                   st.top() > 0 &&
                   it < 0) {

                if (abs(st.top()) < abs(it)) {
                    st.pop();
                }
                else if (abs(st.top()) == abs(it)) {
                    st.pop();
                    alive = false;
                }
                else {
                    alive = false;
                }
            }

            if (alive)
                st.push(it);
        }

        vector<int> res(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};