class Solution {
public:
    
//     bool slope(vector<vector<int>>& sp, int x, int y, int z)
//     {
//         return (float)(sp[y][1] - sp[x][1]) == ((double)(sp[z][1] - sp[x][1]) / (double)(sp[z][0] - sp[x][0]))*(float)(sp[y][0] - sp[x][0]);
//     }
//     int minimumLines(vector<vector<int>>& sp) {
        
//         if (sp.size() == 1)
//             return 0;
        
//         sort(sp.begin(), sp.end());

//         int ans = 1;
        
//         for(int i = 2; i < sp.size(); i++)
//             if (slope(sp, i-2, i-1, i) == false)
            
//                 ans++;
        
//         return ans;
//     }
    
    
    int minimumLines(vector<vector<int>>& sp) 
    {
        if (sp.size() == 1)
            return 0;
        
        sort(sp.begin(), sp.end());
        
        vector<long double> v;
        
        for(int i = 1; i < sp.size(); i++)
        {
            long double x = (sp[i][0] - sp[i-1][0]);
            long double y = (sp[i][1] - sp[i-1][1]);
            
            v.push_back(y/x);  
        }
        
        v.resize(unique(v.begin(), v.end()) - v.begin());
        
        return v.size();
    }
};


