class Solution {
public:
    bool isPalindrome(string s) {
        string st; 
        for(auto it:s){
            if((it>='a' and it<='z') or (it>='0' and it<='9')){
                st+=it;
            }
            if(it>='A' and it<='Z'){
                st+=it+32;
            }
        }
        int l=0,r=st.size()-1;
        while(l<=r){
            if(st[l]!=st[r]){
                return false;
            }
            l++,r--;
        }
        return true;
    }
};
