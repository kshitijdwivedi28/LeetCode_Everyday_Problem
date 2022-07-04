class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> dead_set(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        
        int steps = 0;
        
        if (dead_set.count("0000")) return -1;
        if (target == "0000") return 0;
        
        queue<string> q({"0000"});
        
        while(!q.empty())
        {
            int sz = q.size();
            
            for(int i = 0; i < sz; i++)
            {
                auto curr = q.front(); q.pop();
            
                if (curr == target) return steps;
                
                // generate all turns
                for(int i = 1; i <= 8; i++)
                {
                    string next_turn = "";
                    switch(i)
                    {
                        case 1 : next_turn = curr.substr(0, 3);
                                 if (curr[3] - '0' == 9)
                                     next_turn += "0";
                                 else
                                     next_turn += to_string(curr[3] - '0' + 1);
                                 break;
                            
                        case 2 : next_turn = curr.substr(0, 3);
                                 if (curr[3] - '0' == 0)
                                     next_turn += "9";
                                 else
                                     next_turn += to_string(curr[3] - '0' - 1);
                                 break;
                            
                        case 3 : next_turn = curr.substr(0, 2);
                                 if (curr[2] - '0' == 9)
                                     next_turn += "0";
                                 else
                                     next_turn += to_string(curr[2] - '0' + 1);
                                 next_turn += curr.substr(3);
                            
                                 break;
                            
                        case 4 : next_turn = curr.substr(0, 2);
                                 if (curr[2] - '0' == 0)
                                     next_turn += "9";
                                 else
                                     next_turn += to_string(curr[2] - '0' - 1);
                                 next_turn += curr.substr(3);
                            
                                 break;
                            
                        case 5 : next_turn = curr.substr(0, 1);
                                 if (curr[1] - '0' == 9)
                                     next_turn += "0";
                                 else
                                     next_turn += to_string(curr[1] - '0' + 1);
                                 next_turn += curr.substr(2);
                            
                                 break;
                            
                        case 6 : next_turn = curr.substr(0, 1);
                                 if (curr[1] - '0' == 0)
                                     next_turn += "9";
                                 else
                                     next_turn += to_string(curr[1] - '0' - 1);
                                 next_turn += curr.substr(2);
                            
                                 break;
                            
                        case 7 : 
                                 if (curr[0] - '0' == 9)
                                     next_turn += "0";
                                 else
                                     next_turn += to_string(curr[0] - '0' + 1);
                                 next_turn += curr.substr(1);
                            
                                 break;
                            
                        case 8 : 
                                 if (curr[0] - '0' == 0)
                                     next_turn += "9";
                                 else
                                     next_turn += to_string(curr[0] - '0' - 1);
                                 next_turn += curr.substr(1);
                            
                                 break;
                    }
                    
                    if (dead_set.find(next_turn) != dead_set.end())
                        continue;

                    if (visited.find(next_turn) == visited.end() )
                    {
                        q.push(next_turn);
                        visited.insert(next_turn);
                    }
                }
                // end
            }
            
            steps++;
        }
        
        return -1;

    }
};