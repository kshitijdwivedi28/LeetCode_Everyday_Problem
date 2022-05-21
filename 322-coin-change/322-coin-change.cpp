class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount + 1, INT_MAX);
        
        dp[0] = 0;
        
        for(int i = 1; i < amount + 1; i++)
        {
            for(auto v : coins)
            {
                if (i - v >= 0 && dp[i - v] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i - v]);
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
        
        
    }
};