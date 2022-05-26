// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void reArrange(int arr[], int N) {
        // code here
        int last_odd = N-1, last_even = N-2;
        if (N & 1)
        {
            last_odd = N-2;
            last_even = N-1;
        }
        
        for(int i = 0; i < N; i++)
        {
            if((arr[i] & 1) && !(i & 1))
            {
                while(arr[last_odd] & 1)
                    last_odd -= 2;
                
                swap(arr[i], arr[last_odd]);
                last_odd -= 2;
            }
            else if (!(arr[i] & 1) && (i & 1))
            {
                while(!(arr[last_even] & 1))
                    last_even -= 2;
                
                swap(arr[i], arr[last_even]);
                last_even -= 2;

            } 
        }
    }
};

// { Driver Code Starts.

int check(int arr[], int n)
{
    int flag = 1;
    int c=0, d=0;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            if(arr[i]%2)
            {
                flag = 0;
                break;
            }
            else
                c++;
        }
        else
        {
            if(arr[i]%2==0)
            {
                flag = 0;
                break;
            }
            else
                d++;
        }
    }
    if(c!=d)
        flag = 0;
        
    return flag;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        ob.reArrange(arr,N);
        
        cout<<check(arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends