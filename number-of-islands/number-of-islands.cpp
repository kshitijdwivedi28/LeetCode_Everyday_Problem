class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        // bfs to count islands
        int island_count = 0;
        
        vector<int> directions = {0, 1, 0, -1, 0};
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    island_count++;
                    
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while(!q.empty())
                    {
                        auto v = q.front();
                        q.pop();

                        for(int c = 0; c < directions.size() - 1; c++)
                        {
                            int x = v.first + directions[c], y = v.second + directions[c+1];

                            if (x >= 0 and x < grid.size() and y >= 0 and y < grid[i].size() and grid[x][y] == '1')
                            {
                                grid[x][y] = '0';
                                q.push({x, y});
                            }
                        }
                    }
                } 
            }
        }
        
        return island_count;
        
    }
};