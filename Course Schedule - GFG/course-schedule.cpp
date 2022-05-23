// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int> graph[n];
        vector<int> in_degree(n, 0);
        vector<int> ans;
        
        // building graph and indegree array for topological sort
        for(auto v : prerequisites)
        {
            graph[v[1]].push_back(v[0]);
            in_degree[v[0]]++;
        }
        

        queue<int> q;
        
        // pushing vertex with indegree 0 as the starting vertex
        for(int i = 0; i < n; i++)
            if (in_degree[i] == 0)
                q.push(i);
                
        if (q.empty()) return {};
        
        // Doing BFS to find the path
        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            
            ans.push_back(curr);
            
            for(auto v : graph[curr])
            {
                in_degree[v]--;
                
                if (in_degree[v] == 0)
                    q.push(v);
            }
        }
        
        if (ans.size() == n)
            return ans;
        else
            return {};
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends