// 1094. Car Pooling
// Medium

// 2296

// 57

// Add to List

// Share
// There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

// You are given the integer capacity and an array trips where trip[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

 

// Example 1:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false
// Example 2:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
// Output: true
 

// Constraints:

// 1 <= trips.length <= 1000
// trips[i].length == 3
// 1 <= numPassengersi <= 100
// 0 <= fromi < toi <= 1000
// 1 <= capacity <= 105
// Accepted
// 114,755
// Submissions
// 193,027
  
  
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> seats_in_use(1001,0);
        
        for(int i = 0; i < trips.size(); i++)
        {
            int p = trips[i][0];
            int s = trips[i][1];
            int e = trips[i][2];
            
            for(int j = s; j < e; j++)
            {
                seats_in_use[j] += p;
                if (seats_in_use[j] > capacity)
                    return false;
            }   
        }
        
        return true;
    }
};
  
