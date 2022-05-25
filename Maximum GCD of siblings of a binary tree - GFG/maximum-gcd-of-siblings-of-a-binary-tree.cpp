// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        // code here
        int max_gcd = 0;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); i++)
            if (i+1 < arr.size() && arr[i][0] == arr[i+1][0])
                max_gcd = max(max_gcd, __gcd(arr[i][1], arr[i+1][1]));
        
        return max_gcd;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends