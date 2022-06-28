class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> f(26, 0);
        for(auto c : s)
            f[c - 'a']++;
        
        int ans = 0;
        set<int> st;
        for(int i = 0; i < 26; i++)
        {
            if (st.find(f[i]) != st.end())
            {
                bool check = false;
                for(int j = f[i]; j >= 0; j--)
                {
                    if (st.find(j) == st.end())
                    {
                        check = true;
                        ans += (f[i] - j);
                        st.insert(j);
                        break;   
                    }
                }
                
                if(!check)
                    ans += f[i];
            }
            else
                st.insert(f[i]);
        }
        
        return ans;
        
    }
};