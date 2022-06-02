class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v;
        
        for(int i = 0; i < m; i++)
        {
            v.clear();
            
            for(int j = 0; j < n; j++)
                v.push_back(matrix[j][i]);

            matrix.push_back(v);
        }
        
        // for(auto x : matrix)
        // {
        //     for(auto y : x)
        //         cout << y << " ";
        //     cout << endl;
        // }
        
        for(int i = 0; i < n; i++)
            matrix.erase(matrix.begin());
        
        return matrix;
    }
};