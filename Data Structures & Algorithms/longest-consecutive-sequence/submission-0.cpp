class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int i=0, ans=0;
        while(i<nums.size()){
            if(!st.count(nums[i]-1)){
                int cnt=1;
                while(st.count(nums[i]+cnt)){
                    cnt++;
                }
                ans=max(ans,cnt);
            }
            i++;
        }
        return ans;
    }
};
