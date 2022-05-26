class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        // return __builtin_popcount(n);
        
        // faster than previous inbuilt function and compatible with all languages
        int ans = 0;
        
        for(int i = 0; i <= 31; i++)
            if (n & (1 << i))
                ans++;
        
        return ans;
            
        
        
    }
};