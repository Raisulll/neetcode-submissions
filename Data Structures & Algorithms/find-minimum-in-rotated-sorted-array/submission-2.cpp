class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1, ans=1001;
        while(l<=r){
            int m=(l+r)/2;
            ans=min(ans,nums[m]);
            if(nums[m]>nums[r]){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return ans;
    }
};
