class Solution {
public:

    string longestPalindrome(string s) {
    
        // expanding around center 
        
        int begin = 0, end = 0, ans_start = 0, max_length = 1;
        
        for(int i = 1; i < s.size(); i++)
        {
            // even length substrings
            begin = i-1;
            end = i;
            
            while(begin >= 0 && end < s.size() && s[begin] == s[end] )
                begin--, end++;
            
            begin++, end--;
            
            if (s[begin] == s[end] && end-begin+1 > max_length)
                ans_start = begin, max_length = end-begin+1;
            
            // odd length substrings
            begin = i-1;
            end = i+1;
            
            while(begin >= 0 && end < s.size() && s[begin] == s[end] )
                begin--, end++;
            
            begin++, end--;
            
            if (s[begin] == s[end] && end-begin+1 > max_length)
                ans_start = begin, max_length = end-begin+1;
            
        }
        
        return s.substr(ans_start, max_length);
    }
};


// TRYING TO SHORTEN THE CODE

// class Solution {
// public:

//     pair<int,int> find_substring(string s, int begin, int end, int ans_start, int max_length)
//     {
//         while(begin >= 0 && end < s.size() && s[begin] == s[end] )
//             begin--, end++;
            
//         begin++, end--;
            
//         if (s[begin] == s[end] && end-begin+1 > max_length)
//             ans_start = begin, max_length = end-begin+1;
        
//         return make_pair(ans_start, max_length);
//     }
    
//     string longestPalindrome(string s) {
    
//         // expanding around center 

//         pair<int,int> ans_pair;
        
//         for(int i = 1; i < s.size(); i++)
//         {
//             // even length substrings
//             ans_pair = find_substring(s, i-1, i, 0, 1); 
//             // odd length substrings
//             ans_pair = find_substring(s, i-1, i+1, ans_pair.first, ans_pair.second); 
//         }
        
//         return s.substr(ans_pair.first, ans_pair.second);
//     }
// };




    
    