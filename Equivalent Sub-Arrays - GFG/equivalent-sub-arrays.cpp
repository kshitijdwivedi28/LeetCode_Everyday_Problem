// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_set<int> st;
        for(int i = 0; i < n; i++) st.insert(arr[i]);
        
        
        unordered_map<int, int> m;
        int s = 0, e = 0, ans = 0, sz = st.size();
        
        while(e < n)
        {
            m[arr[e]]++;
            
            while(s <= e and m.size() == sz)
            {
                ans += (n - e);
                m[arr[s]]--;
                if (m[arr[s]] == 0)
                {
                    m.erase(arr[s]);
                }
                s++;
            }
            e++;
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends