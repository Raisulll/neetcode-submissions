int dp[50];
class Solution {
   public:
    int climbStairs(int n) {
        if (dp[n]) return dp[n];
        if (n < 0) return 0;
        if (n == 0) return 1;
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
