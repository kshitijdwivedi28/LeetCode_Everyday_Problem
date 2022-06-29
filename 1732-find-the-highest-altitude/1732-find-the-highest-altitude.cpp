class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
//         int max_altitude = 0,  curr_altitude = 0;
        
//         for(int i = 0; i < gain.size(); i++)
//         {
//             curr_altitude = curr_altitude + gain[i];
            
//             if (curr_altitude > max_altitude)
//                 max_altitude = curr_altitude;
//         }
        
//         return max_altitude;
        
        
        int ans = 0 , curr = 0;
        for(auto g : gain)
        {
            curr += g;
            ans = max(ans, curr);
        }
        
        return ans;

        
    }
};