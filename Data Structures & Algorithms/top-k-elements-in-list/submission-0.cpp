class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<pair<int,int>>cnt;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            cnt.push_back({it.second,it.first});
        }
        sort(cnt.rbegin(),cnt.rend());
        vector<int>ans;
        for(int i=0; i<k; ++i){
            ans.push_back(cnt[i].second);
        }
        return ans;
    }
};
