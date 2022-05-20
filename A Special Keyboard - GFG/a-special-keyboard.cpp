// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) 
    {
        // code here
        int ans = 0;
        
        unordered_map<char, int> m;
        
        for(int i = 0; i < S1.size(); i++)
            m[S1[i]] = i;
            
        ans += m[S2[0]];
        
        for(int i = 1; i < S2.size(); i++)
            ans += abs(m[S2[i-1]] - m[S2[i]]);

            
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends