// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void help(vector<pair<int,int> > &ans,int N,int b1,int b2,int b3){
       if(N>0){
           help(ans,N-1,b1,b3,b2);
           ans.push_back({b1,b3});
           help(ans,N-1,b2,b1,b3);
       } 
   }
   vector<int> shiftPile(int N, int n){
       // code here
       vector<pair<int,int> > ans;
       vector<int> u;
       help(ans,N,1,2,3);
       u.push_back(ans[n-1].first);
       u.push_back(ans[n-1].second);
       return u;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends