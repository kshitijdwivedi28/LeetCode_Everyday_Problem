// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        long limit = max(M, L);
        
        // using arithmetic progression concept, finding maximum hours taken to reach max_limit
        long hours = 0;
        
        for(long i = 0; i < N; i++)
        {
            hours = ((limit - A[i])/H[i]) ? max(hours, (limit - A[i])/H[i] + 1) : max(hours, (limit - A[i])/H[i]);
        }
        
        int l = 0, r = hours;
        
        while(l <= r)
        {
            int mid = (l+r)/2;
            
            long sum = 0;
            
            for(long i = 0; i < N; i++)
                if (H[i] + A[i]*mid >= L)
                    sum += H[i] + A[i]*mid;
                    
            if (sum >= M)
                r = mid-1;
            else
                l = mid+1;
        }
        
        return l;
    }

};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends