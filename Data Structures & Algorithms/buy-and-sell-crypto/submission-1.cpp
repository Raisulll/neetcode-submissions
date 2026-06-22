class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mn[n],mx[n];
        int x=101, y=-1; 
        for(int i=0; i<n; ++i){
            x=min(x,prices[i]);
            mn[i]=x;
        }
        for(int i=n-1; i>=0; --i){
            y=max(y,prices[i]);
            mx[i]=y;
        }
        int ans=0;
        for(int i=0; i<n; ++i){
            // cout<<"ind "<<i<<" "<<mn[i]<<" "<<mx[i]<<endl;
            ans=max(ans,mx[i]-mn[i]);
        }
        return ans;
    }
};
