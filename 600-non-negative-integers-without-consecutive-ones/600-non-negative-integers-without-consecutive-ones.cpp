class Solution {
public:
    int findIntegers(int n) {
        
        vector<int> f(31, 0);
        f[0] = 1, f[1] = 2;
        
        for(int i = 2; i < 31; i++)
            f[i] = f[i-1] + f[i-2];
        
        int prev_bit = 0, ans = 0, bits = 30;
        
        while(bits >= 0)
        {
            if (n & (1 << bits))
            {
                ans += f[bits];
                
                if (prev_bit == 1)
                    return ans;
                
                prev_bit = 1;
            }
            else
                prev_bit = 0;
            
            bits--;  
        }
        
        return ans+1;
        
        
        
    }
};