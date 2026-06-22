class Solution {
public:

    string encode(vector<string>& strs) {
        string st="";
        for(int i=0; i<strs.size(); ++i){
            st+=strs[i];
            st+="+?";
        }
        return st;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string st="";
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='?' and st.size()!=0 and s[i-1]=='+'){
                st.pop_back();
                strs.push_back(st);
                st="";
                continue;
            }
            st+=s[i];
        }
        return strs;
    }
};
