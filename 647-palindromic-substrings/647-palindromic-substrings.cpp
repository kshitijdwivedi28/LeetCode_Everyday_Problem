class Solution {
public:
    
    void enter_palindrome(string s, int start, int end, vector<string> &ans)
    {
        while(start >= 0 && end < s.size() && s[start] == s[end])
        {
            ans.push_back(s.substr(start, end-start+1));
            start--;
            end++;
        }
    }
    
    
    int countSubstrings(string s) {
        
        vector<string> ans;
        
        for(int i = 0; i < s.size(); i++)
        {
            enter_palindrome(s, i, i, ans);
            enter_palindrome(s, i, i+1, ans);
        }
        
        return ans.size();
        
    }
};