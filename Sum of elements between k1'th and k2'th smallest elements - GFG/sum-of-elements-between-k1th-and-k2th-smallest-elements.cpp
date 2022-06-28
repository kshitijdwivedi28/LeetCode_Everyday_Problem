// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(long long i = 0; i < N; i++)
        {
            pq.push(A[i]);
        }
        
        long long count = 0, num1 = 0, num2 = 0;
        while(!pq.empty())
        {
            long long v = pq.top(); pq.pop();
            
            count++;
            
            if (count == K1)
            {
                num1 = v;
            }
            if (count == K2)
            {
                num2 = v;
            }
            
            if (num1 > 0 && num2 > 0)
                break;
        }

        long long sum = 0;
        
        for(long long i = 0; i < N; i++)
        {
            if (A[i] > num1 and A[i] < num2)
                sum += A[i];
        }
        
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends