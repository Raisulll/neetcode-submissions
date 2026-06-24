class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1) return 1;
        unordered_map<char,int>mp;
        int ans=0, l=0;
        for(int i=0; i<s.size(); ++i){
            if(mp[s[i]]!=0){
                ans=max(ans,i-l);
                l=max(l,mp[s[i]]);
                mp[s[i]]=i+1;
                cout<<s[i]<<" "<<l<<endl;
            }else{
                mp[s[i]]=i+1;
            }
        }
        return max(ans,(int)s.size()-l);
    }
};
