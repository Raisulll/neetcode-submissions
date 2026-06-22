class Solution {
public:
    bool isAnagram(string s, string t) {
        int s1[26]={0},s2[26]={0};
        for(auto it:s){
            s1[it-'a']++;
        }
        for(auto it:t){
            s2[it-'a']++;
        }
        for(int i=0; i<26; ++i){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        return true;
    }
};
