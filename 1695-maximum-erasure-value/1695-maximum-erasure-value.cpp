class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
//         unordered_set<int> st;

//         // sliding window or two pointers
        
//         int l = 0, r = 0, n = nums.size(), max_sum = INT_MIN, ans = 0;
        
//         while(l < n && r < n)
//         {
//             if (st.find(nums[r]) == st.end())
//             {
//                 st.insert(nums[r]);
//                 ans += nums[r];
//                 max_sum = max(ans, max_sum);
//                 r++;
//             }
//             else
//             {
//                 st.erase(nums[l]);
//                 ans -= nums[l];
//                 l++;
//             }
//         }
        
//         return max_sum;
        
        
        vector<int> occur(10001, 0);

        // sliding window or two pointers
        
        int l = 0, r = 0, n = nums.size(), max_sum = INT_MIN, ans = 0;
        
        while(l < n && r < n)
        {
            if (occur[nums[r]] == 0)
            {
                occur[nums[r]]++;
                ans += nums[r];
                max_sum = max(ans, max_sum);
                r++;
            }
            else
            {
                occur[nums[l]]--;
                ans -= nums[l];
                l++;
            }
        }
        
        return max_sum;
        
    }
};