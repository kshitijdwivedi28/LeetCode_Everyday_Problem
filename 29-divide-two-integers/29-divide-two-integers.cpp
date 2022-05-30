class Solution {
public:
    int divide(int dividend, int divisor) 
    {  
//         if(dividend == INT_MIN && divisor == -1) 
//             return INT_MAX;
        
//         return dividend/divisor;

        
        // without /, *, % operator
        
        
        int count = 0, multiplier = 1;
        
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            multiplier = -1;
        
        
        if (dividend > 0)
            dividend = -1 * dividend;    
        
        if (divisor > 0)
            divisor = -1 * divisor;        

        while (divisor >= dividend)
        {
            int multiple = -1;
            int sum = divisor;
            
            while (sum >= dividend - sum)
            {
                multiple += multiple;
                sum += sum;
            }
            
            count += multiple;
            dividend -= sum;
        }
        
        if (count == INT_MIN)
        {
            if (multiplier == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        
        count = -1 * count;
        
        return count * multiplier;

    }
};