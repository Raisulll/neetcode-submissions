// bottom up appraoch, hare start with 1 and reach n. 
// time complexity O(n), space complexity O(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        int prev1=1; 
        int prev2=1;
        int temp=0;
        for(int i=2; i<=n; ++i){
            temp=prev1+prev2;
            prev2=prev1;
            prev1=temp;
        }
        return temp;
    }
};
