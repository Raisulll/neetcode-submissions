class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (auto it : s) {
            if (it == '[' or it == '(' or it == '{') {
                st.push(it);
            } else if (st.size() == 0) {
                return false;
            } else {
                if (it == ']' and st.top() != '[') {
                    return false;
                }
                if (it == '}' and st.top() != '{') {
                    return false;
                }
                if (it == ')' and st.top() != '(') {
                    return false;
                }
                st.pop();
            }
        }
        if (st.size() == 0) return true;
        return false;
    }
};
