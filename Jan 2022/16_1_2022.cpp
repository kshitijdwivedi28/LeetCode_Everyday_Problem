// 849. Maximize Distance to Closest Person
// Medium

// 2004

// 152

// Add to List

// Share
// You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

// There is at least one empty seat, and at least one person sitting.

// Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

// Return that maximum distance to the closest person.

 

// Example 1:


// Input: seats = [1,0,0,0,1,0,1]
// Output: 2
// Explanation: 
// If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
// If Alex sits in any other open seat, the closest person has distance 1.
// Thus, the maximum distance to the closest person is 2.
// Example 2:

// Input: seats = [1,0,0,0]
// Output: 3
// Explanation: 
// If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
// This is the maximum distance possible, so the answer is 3.
// Example 3:

// Input: seats = [0,1]
// Output: 1
 

// Constraints:

// 2 <= seats.length <= 2 * 104
// seats[i] is 0 or 1.
// At least one seat is empty.
// At least one seat is occupied.
// Accepted
// 142,320
// Submissions
// 308,296

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int s = -1, e = 0;
        int max_dist = 0;
        
        for(int i = 0; i < seats.size(); i++)
            if (seats[i] == 1)
                s = i;
            else
            {
                while(e < seats.size() && seats[e] == 0 || e < i)
                    e++;
                
                int left, right;
                
                if (s == -1)
                    left = seats.size();
                else
                    left = i-s;
                
                if(e == seats.size())
                    right = seats.size();
                else
                    right = e-i;

                max_dist = max(max_dist, min(left, right));
                    
            }
            
        return max_dist;
        
        
//         // By grouping empty seats
        
//         int count = 0, max_count = 0;
        
//         // first empty seats
//         for(int i = 0; i < seats.size(); i++)
//             if(seats[i] == 1)
//             {
//                 max_count = max(max_count, i);
//                 break;
//             }
        
//         // for last empty seats
//         for(int i = seats.size()-1; i >= 0; i--)
//             if(seats[i] == 1)
//             {
//                 int curr = (seats.size()-1-i);
//                 max_count = max(max_count, curr );
//                 break;
//             }
               
        
//         for(int i = 0; i < seats.size(); i++)
//             if (seats[i] == 1)
//                 count = 0;
//             else
//             {
//                 count++;
//                 int curr = (count+1)/2;
//                 max_count = max(max_count, curr);
//             }
        
//         return  max_count;

    }
};
