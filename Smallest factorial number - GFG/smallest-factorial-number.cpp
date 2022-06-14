// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
        //complete the function here
            int s = 1, e = 5*n;
            
            while(s < e)
            {
                int m = (s+e)/2;
                
                int count = 0;
                
                for(int i = 5; i <= m; i*=5)
                    count += (m/i);
                
                if (count < n)
                    s = m+1;
                else
                    e = m;
            }
            
            return s;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends