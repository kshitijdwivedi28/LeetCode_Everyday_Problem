class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        // using prefix sums
//         vector<int> prefix_sum(nums.size()+2, 0);
        
//         int sum = 0;
//         int ans = -1;
        
//         for(int i = 0; i < nums.size(); i++)
//         {
//             sum += nums[i];
//             prefix_sum[i+1] = sum;
//         }

        
//         for(auto value : prefix_sum)
//             cout << value << " ";
        
//         // cout << endl;
//         // cout << prefix_sum[3] << endl;
//         // cout << prefix_sum[prefix_sum.size()-2] << endl;
//         // cout << nums[3] << endl;
        
//         for(int i = 1; i < prefix_sum.size()-1; i++)
//             if ( prefix_sum[i-1] == prefix_sum[prefix_sum.size()-2] - prefix_sum[i-1] - nums[i-1])
//                 return i-1;
                
        
//         return ans;
        
        
        
        // optimising to O(1) space
        
        int left_sum = 0, sum = 0, ans = -1;
        
        for(auto value : nums)
            sum += value;
        
        for(int i = 0; i < nums.size(); i++)
            if (left_sum == sum - left_sum - nums[i])
                return i;
            else
                left_sum += nums[i];
        
        return ans;
            
        
    }
};