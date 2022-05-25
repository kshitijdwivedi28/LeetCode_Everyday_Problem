class Solution {
public:

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


