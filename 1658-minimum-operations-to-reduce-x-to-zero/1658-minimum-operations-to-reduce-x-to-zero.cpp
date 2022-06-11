class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
//         // taken hint
//         int req_sum = accumulate(nums.begin(), nums.end(), 0) - x;
        
//         if (req_sum < 0) return -1;
        
//         // now its like find the length of the longest subarray with required sum 
//         // O(n) time, O(1) space
        
//         // using sliding window principle
        
//         int max_len = INT_MIN, left = 0, right = 0, curr_sum = 0;
        
//         while(right < nums.size())
//         {

//             curr_sum += nums[right];
            
//             if (curr_sum > req_sum)
//             {
//                 curr_sum -= nums[left];
//                 left++;
//             }
//             else if (curr_sum == req_sum)
//             {
//                 max_len = max(max_len, right - left + 1);
//             }
            
//             right++;
//         }
        
//         return max_len == INT_MIN ? -1 : nums.size() - max_len;
        
         int total=0, n=nums.size();
        for(auto i:nums) total+=i;
        if(x>total) return -1;
        int left=0,right=0, curr=0, ans=-1;
        for(; right<n;right++){
            curr+=nums[right];
            while(curr>total-x&&left<=right){
                curr-=nums[left];
                left++;
            }
            if(curr==total-x) ans=max(ans, right-left+1);
        }
        if(ans==-1) return ans;
        return n-ans;
    }
};