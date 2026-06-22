class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount=0,product=1;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]!=0){
                product*=nums[i];
            }else{
                zeroCount++;
            }
        }
        vector<int>ans;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]!=0 and zeroCount>0){
                ans.push_back(0);
            }else if(nums[i]!=0 and zeroCount==0){
                ans.push_back(product/nums[i]);
            }else if(nums[i]==0 and zeroCount>1){
                ans.push_back(0);
            }else{
                ans.push_back(product);
            }
        }
        return ans;
    }
};
