class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        
        for(auto v : prerequisites)
        {
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++)
            if (!indegree[i]) q.push(i);
        
        if (!q.size()) return false;
        
        while(!q.empty())
        {
            int vertex = q.front(); q.pop();
            
            for(auto v : adj[vertex])
            {
                if (--indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        
        return accumulate(indegree.begin(), indegree.end(), 0) == 0 ? true : false;
        
    }
};