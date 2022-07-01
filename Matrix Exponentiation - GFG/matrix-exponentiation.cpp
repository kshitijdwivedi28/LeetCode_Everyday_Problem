// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int M = 1000000007;
    vector<vector<long long int>> multi(vector<vector<long long int>> &a, vector<vector<long long int>> &b) {
        vector<vector<long long int>> c = {{0,0},{0,0}};
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    c[i][j] += ((a[i][k]%M)*(b[k][j]%M))%M;
                }
            }
        }
        return c;
    }

    int FindNthTerm(long long int n) {
        vector<vector<long long int>> mat = {{1,1},{1,0}};
        vector<vector<long long int>> res = {{1,1},{1,0}};
        n--;
        while(n) {
            if(n%2 == 1) 
                res = multi(mat,res);
    
            mat = multi(mat,mat);
            n = n>>1;
        }
        return res[0][0]%M;
    }
    
    
    // int FindNthTerm(long long int n) {
        
    //     int mod=1e9+7;
    //     long long int arr[n+1];
       
    //     arr[0]=arr[1]=1;
       
    //     for(int i=2;i<=n;i++){
    //         arr[i]=(arr[i-1]%mod+arr[i-2]%mod)%mod;
    //     }
       
    //   return arr[n];
    // }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends