class MinStack {
   public:
    stack<long long> st;
    map<long long, int> mp;
    long long mn = LONG_LONG_MAX;
    MinStack() {}

    void push(int val) {
        st.push(val);
        mn = min(mn, (long long)val);
        mp[val]++;
    }

    void pop() {
        int val = st.top();
        st.pop();
        mp[val]--;
        if (mp[val] == 0) {
            mp.erase(val);
        }
        if (val == mn) {
            if (mp.empty()) {
                mn = LONG_LONG_MAX;
            } else {
                mn = mp.begin()->first;
            }
        }
    }

    int top() { return st.top(); }

    int getMin() { return mn; }
};
