// 312. Burst Balloons
// Hard

// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

 

// Example 1:

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
// Example 2:

// Input: nums = [1,5]
// Output: 10
 

// Constraints:

// n == nums.length
// 1 <= n <= 500
// 0 <= nums[i] <= 100


class Solution {
public:

    int maxCoins(vector<int>& nums) 
    {
        if (nums.size() == 1)
            return nums[0];
        
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int> > dyn_prog(nums.size(), vector<int>(nums.size(), 0));
        
        for (int i = nums.size() - 3; i >= 0; i --) 
            for (int j = i + 2; j < nums.size();j ++) 
                for (int k = i + 1; k < j; k ++)
                    dyn_prog[i][j] = max(dyn_prog[i][j], dyn_prog[i][k] + dyn_prog[k][j] +                                                nums[i] * nums[k] * nums[j] );

        return dyn_prog[0][nums.size() - 1];
    }
};
