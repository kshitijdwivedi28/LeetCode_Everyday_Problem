// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    // // just checking if partition is possible or not
    bool check(vector<int>&A, int start, int N, int K, int M)
    {
        // if the entire array is traversed and we didn't find any non-obeying pair condition
        if (start >= N) return true;
        
        // traverse the array to find if the difference between the pairs > M or not
        for(int i = start + K - 1; i < N; i++)
            // if the differnce is > M condition not obeyed, partition not possible
            if (A[i] > (A[start] + M)) return false;
            // if the current pair follows check for the next pair
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