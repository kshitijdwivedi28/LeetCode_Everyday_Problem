// 452. Minimum Number of Arrows to Burst Balloons
// Medium

// 3086

// 91

// Add to List

// Share
// There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

// Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

// Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

 

// Example 1:

// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
// - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
// Example 2:

// Input: points = [[1,2],[3,4],[5,6],[7,8]]
// Output: 4
// Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
// Example 3:

// Input: points = [[1,2],[2,3],[3,4],[4,5]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
// - Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
 

// Constraints:

// 1 <= points.length <= 105
// points[i].length == 2
// -231 <= xstart < xend <= 231 - 1
// Accepted
// 171,171
// Submissions
// 325,667

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        // Approach
        // Answer = Count total non overlapping range
        
//         vector<pair<int,int>> vp;
        
//         for(auto value : points)
//             vp.push_back(make_pair(value[0], value[1]));
        
//         // Sorting on the basis of arrival times 
//         sort(vp.begin(), vp.end());
        
//         // for(auto value : vp)
//         //      cout << value.first << " " << value.second << endl;
        
//         int ans = 1;
//         int prev_end = vp[0].second;
        
//         for(int i = 1; i < vp.size(); i++)
//         {
//             if (vp[i].first > prev_end)
//             {
//                 ans++;
//                 prev_end = vp[i].second;
//             }
            
//             prev_end = min(prev_end, vp[i].second);
//         }
        
//         return ans;
        
        
        // Complexity = O(nlogn) Space = O(N)
        
        
        // Sorting on the basis of end time 
//         vector<pair<int,int>> vp;
        
//         for(auto value : points)
//             vp.push_back(make_pair(value[1], value[0]));
        
//         // Sorting on the basis of arrival times 
//         sort(vp.begin(), vp.end());
        
//         int ans = 1;
//         int prev_start = vp[0].first;
        
//         for(int i = 1; i < vp.size(); i++)
//             if(vp[i].second > prev_start)
//             {
//                 ans++;
//                 prev_start = vp[i].first;
//             }
        
        
//         return ans;
        
        
        
      //  Another approach simplified sorting
     // No extra space
        
//         sort(points.begin(), points.end());
        
//         int s = points[0][0];
//         int e = points[0][1];
        
//         int ans = 1;
        
//         for(int i = 1; i < points.size(); i++)
//         {
//             if (points[i][0] > e)
//             {
//                 ans++;
//                 s = points[i][0];
//                 e = points[i][1];
//             }
//             else if (points[i][1] < e)
//             {
//                 s = points[i][0];
//                 e = points[i][1];
//             }
            
//         }
        
//         return ans;

        
        
        // Though just prev code is same, just handling 2nd condition by 
        // putting an equal to in the else if case
        // Reduces running time by half 
        // prev code run time = 800+ ms
        // below code run time = 400 ms
        sort(points.begin(), points.end());
        
        int s = points[0][0];
        int e = points[0][1];
        
        int ans = 1;
        
        for(int i = 1; i < points.size(); i++)
        {
            // Finding non overlapping intervals that need a seperate arrow
            if (points[i][0] > e)
            {
                ans++;
                s = points[i][0];
                e = points[i][1];
            }
            // else shift to current interval as the previous interval can also be hit by the same arrow 
            else if (points[i][1] <= e)
            {
                s = points[i][0];
                e = points[i][1];
            }
            
        }
        
        return ans;
        
    }
};
