class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int s1 = 0;
        for (auto it : nums) s1 += it;
        cout<<n<<" "<<sum<<" "<<s1<<endl;
        return sum - s1;
    }
};
