// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    // just checking if partition is possible or not
    bool check(vector<int>&A, int start, int N, int K, int M)
    {
        if (start >= N) return true;
        
        for(int i = start + K - 1; i < N; i++)
            if (A[i] > (A[start] + M)) return false;
            else if (check(A, i+1, N, K, M)) return true;
        
        return false;
    }
    
    bool partitionArray(int N, int K, int M, vector<int> &A)
    {
        // code here
        sort(A.begin(), A.end());
        
        return check(A, 0, N, K, M);
        
        
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends