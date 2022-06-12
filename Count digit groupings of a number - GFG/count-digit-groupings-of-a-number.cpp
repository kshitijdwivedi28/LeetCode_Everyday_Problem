// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int helper(int ind, int preSum, string s, vector<vector<int>>& dp){
	    if(ind < 0) return 1;
	    if(dp[ind][preSum] != -1) return dp[ind][preSum];
	    int res = 0, curSum = 0;
	    for(int i = ind; i >= 0; i--){
	        curSum += s[i] - '0';
	        if(curSum <= preSum){
	            res += helper(i - 1, curSum, s, dp);
	        }
	    }
	    return dp[ind][preSum] = res;
	}
	
	int TotalCount(string str){
	    int n = str.size();
	    int sum = 0;
	    for(char c : str){
	        sum += c - '0';
	    }
	    vector<vector<int>> dp(n, vector<int>(sum + 2, -1));
	    helper(n - 1, sum + 1, str, dp);
	    return dp[n - 1][sum + 1];
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends