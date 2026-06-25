class Solution {
   public:
    int reverse(int x) {
        string st = to_string(x);
        cout << st << endl;
        long long y = 0;
        for (int i = st.size() - 1; i >= 0; --i) {
            if (st[i] >= '0' and st[i] <= '9') y = y * 10 + (st[i] - '0');
        }
        int a = INT_MAX, b = INT_MIN;
        if (x < 0) y *= -1;
        if (y <= a and y >= b) return y;
        return 0;
    }
};
