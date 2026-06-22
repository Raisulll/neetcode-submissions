class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        int bits[32];
        for (int i = 0; i < 32; ++i) {
            bits[i] = n % 2;
            n /= 2;
        }
        for(int i=0; i<32; ++i) cout<<bits[i]<<" ";
        cout<<endl;
        uint32_t ans = 0;
        for (int i = 0; i < 32; ++i) {
            if (bits[i]) ans += pow(2, 32 - i -1);
        }
        return ans;
    }
};
