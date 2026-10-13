class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxDepth = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
                maxDepth = max(maxDepth, (int)st.size());
            }
            else if (c == ')') {
                st.pop();
            }
        }

        return maxDepth;
    }
};