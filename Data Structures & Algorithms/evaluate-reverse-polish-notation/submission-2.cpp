class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto it : tokens) {
            if (it != "+" and it != "-" and it != "*" and it != "/") {
                int x = stoi(it);
                st.push(x);
            } else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(it=="+"){
                    st.push(a+b);
                }
                if(it=="-"){
                    st.push(b-a);
                }
                if(it=="*"){
                    st.push(a*b);
                }
                if(it=="/"){
                    st.push(b/a);
                }
            }
        }
        return st.top();
    }
};
