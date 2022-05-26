class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        // return __builtin_popcount(n);
        
        // faster than previous inbuilt function and compatible with all languages
//         int ans = 0;
        
//         for(int i = 0; i <= 31; i++)
//             if (n & (1 << i))
//                 ans++;
        
//         return ans;
        
        // above algo's run atleast 32 times 
        // but this one does not
        // as it recedes to the previous number having number of '1' bits, one less than the
        // the current number. Thereby traversing 32 times only when all bits are one
        // or can be said as 
        // the loop runs only number of 1 bit times 
        
        int ans = 0;
        
        while(n > 0)
        {
            n = n & (n-1);  // n & (n-1) calculates to 0 when the number is a power of 2, 
                            // as it will have only single 1 bit.
            ans++;
        }
        
        return ans;
        
        
            
        
        
    }
};