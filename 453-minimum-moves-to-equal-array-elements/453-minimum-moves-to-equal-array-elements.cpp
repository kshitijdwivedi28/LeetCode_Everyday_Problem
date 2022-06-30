class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int min_ele = *min_element(nums.begin(), nums.end());
        
        int ans = 0;
        
        for(auto v : nums)
            ans += abs(v - min_ele);
        
        return ans;
    }
};