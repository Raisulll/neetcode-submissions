class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int x = s1.size(), y = s2.size();
        sort(s1.begin(), s1.end());
        for (int i = 0; i <= y - x; ++i) {
            string st = "";
            for (int j = i; j < i + x; ++j) {
                st += s2[j];
            }
            sort(st.begin(), st.end());
            if (s1 == st) return true;
        }
        return false;
    }
};
