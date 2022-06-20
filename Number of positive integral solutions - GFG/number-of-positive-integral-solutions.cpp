// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long posIntSol(string s)
    {
        int n = 0, k = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            int j = i;
            
            while(s[j] >= 'a' and s[j] <= 'z')
                j++;
            
            n++;
            
            if (s[j] == '=')
            {
                k = stoi(s.substr(j + 1, n - 1 - j));
                break;
            }
            
            i = j;
        }
        
        if (k < n)
            return 0;

        long ans = 1;
        
        for(int i = 1; i < n; i++)
            ans *= (k - i);
            
        for(int i = 1; i < n; i++)
            ans /= (n - i);
            
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends