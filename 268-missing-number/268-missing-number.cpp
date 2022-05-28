class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int sum = 0;
        
        for(auto value : nums)
            sum += value;
        
        return (((nums.size()*(nums.size()+1))/2) - sum);
            
    }
};