class Solution {
public:
    int longestValidParentheses(string s) {
        
//         stack<char> temp_stack;
//         deque<char> dq;
//         int max_length = 0, ans = INT_MIN;
        
//         for( int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == '(')
//                 dq.push_front(s[i]);
                
//             else 
//             {
//                 if (dq.front() == '(')
//                 {
//                     max_length++;
//                     dq.pop_front();
//                 }
//             }
            
//             ans = max(ans, max_length);
//         }
        
//         return ans*2;
        
        // using two pointer approach
        // 2 time traversals
        // left to right and right to left
        
        int l,r,ans;
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