class Solution {
    int squaredSum(int n){
        int sum=0;
        while(n>0){
            int x=n%10;
            sum+=x*x;
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        set<int>prev;
        while(n!=1){
            if(prev.size()!=0 and prev.count(n)) return false;
            prev.insert(n);
            n=squaredSum(n);
        }
        return true;
    }
};
