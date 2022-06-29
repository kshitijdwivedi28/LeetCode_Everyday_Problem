class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int max_altitude = 0, start_altitude = 0;
        
        for(int i = 0; i < gain.size(); i++)
        {
            int curr_altitude = gain[i];
            start_altitude = start_altitude + curr_altitude;
            
            if (start_altitude > max_altitude)
                max_altitude = start_altitude;
        }
        
        return max_altitude;
        
    }
};