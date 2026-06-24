class MinStack {
    stack<long long> st, mn;

   public:
    MinStack() {}

    void push(int val) {
        if (mn.empty() or mn.top() >= val) {
            mn.push(val);
        }
        st.push(val);
    }

    void pop() {
        if (st.top() == mn.top()) {
            mn.pop();
        }
        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return mn.top(); }
};
