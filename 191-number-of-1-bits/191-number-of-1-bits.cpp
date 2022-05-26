class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        // return __builtin_popcount(n);
        
        int ans = 0;
        
        for(uint32_t i = 0; i <= 31; i++)
            if (n & (1 << i))
                ans++;
        
        return ans;
            
        
        
    }
};