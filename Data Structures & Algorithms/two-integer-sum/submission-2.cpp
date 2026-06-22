class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;
        for(int i=0; i<nums.size(); ++i){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int l=0,r=arr.size()-1;
        while(l<r){
            if(arr[l].first+arr[r].first==target){
                int x=arr[l].second, y= arr[r].second;
                return {min(x,y),max(x,y)};
            }else if(arr[l].first+arr[r].first>target){
                r--;
            }else{
                l++;
            }
        }
        return { };
    }
};
