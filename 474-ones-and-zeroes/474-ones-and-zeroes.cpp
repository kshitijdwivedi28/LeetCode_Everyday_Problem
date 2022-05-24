class Solution {
public:

    int findMaxForm(vector<string>& strs, int m_zeroes, int n_ones) 
    {
        
        vector<pair<int, int>> vp;
        
        for(auto s : strs)
        {
            int count_ones = 0, count_zeroes = 0;
            
            for(auto c : s)
                if (c == '0') count_zeroes++;
                else count_ones++;
            
            vp.push_back({count_zeroes, count_ones});
        }
        
        sort(vp.begin(), vp.end());
        
        map<int, int> m;
        
        int ans = 0;
        
        for(int i = 0; i < vp.size(); i++)
        {
            if (m_zeroes < vp[i].first) break;
            
            else
            {
                if (n_ones >= vp[i].second)
                {
                    m_zeroes -= vp[i].first;
                    n_ones -= vp[i].second;
                    
                    ans++;
                    
                    m[vp[i].second]++;
                }
                
                else
                {
                    if (m.size())
                    {
                        auto itr = --m.end();
                    
                        if (itr->first > vp[i].second)
                        {
                            n_ones += itr->first - vp[i].second;
                            
                            m[itr->first]--;
                            
                            if (itr->second == 0)
                                m.erase(itr->first);
                        }
                    }
                }
            }
        }
        
        return ans;

    }
};