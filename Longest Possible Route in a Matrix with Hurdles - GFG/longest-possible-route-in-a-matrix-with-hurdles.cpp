// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int sol(vector<vector<int>> matrix,vector<vector<int>> &visited, int xs, int ys, int xd, int yd){
        int r=matrix.size(),c=matrix[0].size();
        if(xs<0 || ys<0 || xs>=r || ys>=c || matrix[xs][ys]==0 || visited[xs][ys]==1)return -1;
        
        visited[xs][ys]=1;
        
        if(xs==xd && ys==yd){
            visited[xs][ys]=0;
            return 0;
        };
        
        int l = sol(matrix,visited,xs,ys-1,xd,yd);
        int ri = sol(matrix,visited,xs,ys+1,xd,yd);
        int u = sol(matrix,visited,xs-1,ys,xd,yd);
        int d = sol(matrix,visited,xs+1,ys,xd,yd);
        
        visited[xs][ys]=0;
        if((l+ri+u+d)==-4)return -1;
        
        return 1+max(max(l,ri),max(u,d));
        
        
        
    }
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        vector<vector<int>> visited(matrix.size(),vector<int>(matrix[0].size(),0));
        return sol(matrix,visited,xs,ys,xd,yd);
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends