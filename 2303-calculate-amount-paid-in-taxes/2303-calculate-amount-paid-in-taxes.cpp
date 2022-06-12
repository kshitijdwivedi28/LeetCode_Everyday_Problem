class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        
        double ans = 0;
        int prev = 0;
        
        for(auto b : brackets)
        {
            int upper = b[0];
            int curr = min(upper - prev, income);
            
            ans += (curr * b[1]/100.0);
            
            income -= curr;
            prev = upper;
        }
        
        return ans;
    }
};