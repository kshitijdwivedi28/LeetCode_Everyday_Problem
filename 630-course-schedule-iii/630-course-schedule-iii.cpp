class Solution {
    
private :
    
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        // sorting according to end times
        sort(courses.begin(), courses.end(), [&](vector<int> &x, vector<int>&y) 
                                                {
                                                    return x[1] < y[1];
                                                });
        
        priority_queue<int> pq; // for duration
        int total_time = 0;
        
        for(auto c : courses)
        {
            total_time += c[0]; // adding duration;
            pq.push(c[0]); // pushing into pq;
            
            // if total time exceeds end time for the current course, remove the course having the maximum duration among the currently selected courses
            
            if (total_time > c[1] and pq.size()) 
            {
                // remove the maximum duration 
                total_time -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
        
        
        
    }
};