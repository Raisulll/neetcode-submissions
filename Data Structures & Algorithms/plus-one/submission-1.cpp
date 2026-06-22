class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long x=0;
        for(auto it:digits){
            x=x*10+it;
        }
        x++;
        cout<<x<<endl;
        vector<int>ans;
        while(x>0){
            ans.push_back(x%10);
            x/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
