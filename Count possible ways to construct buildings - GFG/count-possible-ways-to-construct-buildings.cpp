// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
        int mod = 1e9 + 7;
	    
	    vector<long long> fib(N+3, 0);
	    fib[0] = 0, fib[1] = 1;
	    
	    for(int i = 2; i < N+3; i++)
	        fib[i] = fib[i-1]%mod + fib[i-2]%mod;

	    return (fib[N+2] * fib[N+2])%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends