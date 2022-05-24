class Solution {
public:
    int longestValidParentheses(string s) {
        
        if (s.empty()) return 0;
        
        // using stack to store index instead of parentheses like in valid parentheses
        // bcoz length is required.
        // So, will subtract starting index of last parentheses with the current parentheses
        // to get the longest length
        
//         stack<int> st;
//         int ans = INT_MIN;
        
//         // to handle the case of '()'
//         st.push(-1);
        
//         for(int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == '(') st.push(i);
//             else
//             {
//                 st.pop();
//                 if (st.empty()) st.push(i);
//                 else ans = max(ans, (i - st.top()));
//             }
//         }
        
//         return ans == INT_MIN ? 0 : ans;
        
        // using two pointer approach
        // 2 time traversals
        // left to right and right to left
        
        int l, r, ans;
        l = r = ans = 0;
        
        for(auto value : s)
        {
            if(value == '(')
                l++;
            else
                r++;
            
            if (l == r)
                ans = max(ans, 2*l);
                
            else if (r > l)
                l = r = 0;
        }
        
        l = r = 0;
        
        for(int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == '(')
                l++;
            else
                r++;
            
            if (l == r)
                ans = max(ans, 2*l);
                
            else if (l > r)
                l = r = 0;
        }
        
        return ans;
        
    }
};