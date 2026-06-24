// top down appraoch, time complexity O(n), space O(n);

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 2,0);
        return min(costCalc(cost, dp, 0), costCalc(cost, dp, 1));
    }

    int costCalc(vector<int>& cost, vector<int>& dp, int ind) {
        if (ind >= cost.size()) return 0;
        if (dp[ind]) return dp[ind];
        return dp[ind] = cost[ind] + min(costCalc(cost, dp, ind + 1), costCalc(cost, dp, ind + 2));
    }
};
