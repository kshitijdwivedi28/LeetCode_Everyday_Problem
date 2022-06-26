class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        
        if (k == cp.size()) return accumulate(cp.begin(), cp.end(), 0);
        
        int n = cp.size();
        for(int i = 1; i < cp.size(); i++)
            cp[i] += cp[i-1];
        
        int max_sum = max(cp[k-1], (cp[n-1] - cp[n-k-1]));
    
        for(int i = 0; i < k-1; i++)
        {
            int frontsum = cp[i];
            int backsum = (cp[n-1] - cp[n-k+i]);
            
            max_sum = max(max_sum, (frontsum + backsum));
        }

        return max_sum;
    }
};