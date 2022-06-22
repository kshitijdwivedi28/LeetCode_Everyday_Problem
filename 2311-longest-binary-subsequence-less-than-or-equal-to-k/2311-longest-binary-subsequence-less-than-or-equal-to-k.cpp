class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        
        int ans = 0;
        
        reverse(s.begin(), s.end());
        
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0') ans++;
            
            // bit manipulation to check the maximum
            else if (i < 31)
            {
                if (k >= (1 << i))
                {
                    k -= (1 << i);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};