class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 0, ans = 0;
        for (int it : piles) {
            ans = max(ans, it);
            hi = max(hi, it);
        }
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int hrs = 0;
            for (int i = 0; i < piles.size(); ++i) {
                hrs += (piles[i]+mid-1)/mid;
            }
            // cout<<"low "<<lo<<" high "<<hi<<" mid "<<mid<<" hrs "<<hrs<<endl;
            if (hrs <= h) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
