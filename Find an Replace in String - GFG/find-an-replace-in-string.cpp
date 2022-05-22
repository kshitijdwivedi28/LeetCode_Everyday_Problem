// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string s ,int Q, int index[], string sources[], string targets[]) {
        // code here
        // unordered_map<int, vector<string>> m;
        
        // for(int i = 0; i < Q; i++)
        // {
        //     if (S.substr(index[i], sources[i].size()) == sources[i])
        //     {
        //          m[index[i]].push_back(sources[i]);
        //          m[index[i]].push_back(targets[i]);
        //     }
        // }
        
        // string ans = "";
        
        // for(int i = 0; i < S.size(); i++)
        // {
        //     if (m.find(i) != m.end())
        //     {
        //         ans += m[i][1];
        //         i += m[i][0].size() - 1;
        //     }
        //     else
        //         ans += S[i];
        // }
        
        // return ans;
        
        string ans = "";
        
        int i = 0, j = 0;
        
        while(i < s.size())
        {
            if( i == index[j])
            {
                if(s.substr(i,sources[j].size()) == sources[j])
                {
                    ans += targets[j];
                    i += sources[j].size();
                }
                
                j++;
            }
            else
            {
                ans += s[i];
                i++;
            }
        }
        
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends