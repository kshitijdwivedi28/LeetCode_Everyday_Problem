// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    char profession(int level, int pos){
        // code here
        // If you are your parent's second child (i.e your index is even) 
        // then you will have the opposite profession as your parent). 
        // And similarly, odd index means your profession is same as your parent. 
        // pos's parent is (pos+1)/2, We use a bool flip to keep check on 
        // how many opposite professions we encounter 
        // while going till engineer ancestor. 
        // If flip is true, then our answer is DOCTOR, else it is ENGINEER.
        
        // Thus we will be moving up as we look for 1st position which is an engineer
        // And use flip to keep check on alternate profession we encounter
        
        bool flip = false;
        
        while(pos != 1)
        {
            if (pos%2 == 0) flip = !flip;
            pos = (pos+1)/2;
        }
        
        return flip ? 'd' : 'e';
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    }
    return 0;
}  // } Driver Code Ends