// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(long long s, long long n, long long x, long long a[])
    {
        // code here
        long long total = s ;
        int stop_idx = n-1 ;
        for(int i=0 ; i<n ; i++){
            a[i] += total ;
            total += a[i] ;
            if(a[i]>= x){
                stop_idx = i ;
                break ;
            }
        }
        
        int i=stop_idx ;
        while(i>=0){
            if(x >= a[i])
                x -= a[i] ;
            i-- ;
        }
        if(x == 0 || x == s)
            return 1 ;
            
        return 0 ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends