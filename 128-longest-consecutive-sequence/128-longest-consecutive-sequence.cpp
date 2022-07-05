class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        
        int max_len = 0, curr_len = 1;
        
//         TLE => Time Complexity (n^2 log n)
        
//         set<int> s(nums.begin(), nums.end());
        
//         for(auto v : nums)
//         {
//             int curr_number = v;
//             curr_len = 1;
            
//             while(s.find(curr_number + 1) != s.end())
//             {
//                 curr_len++;
//                 curr_number++;
//             }
            
//             max_len = max(curr_len, max_len);
//         }
        
        
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i-1]) continue;
            
            if (nums[i] - nums[i-1] == 1) curr_len++;
            
            else
            {
                max_len = max(max_len, curr_len);
                curr_len = 1;
            }
        }

        return max(max_len, curr_len);
        
        
  
    }
};