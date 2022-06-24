class Solution {
public:
    bool isPossible(vector<int>& target) {
        
//         int64_t sum = 0;
//         priority_queue<int> pq;

//         for(auto v : target)
//         {
//             pq.push(v);
//             sum += v;
//         }

//         while(pq.top() > 1)
//         {
//             int target_max = pq.top();
            
//             int sum_diff = pq.top() % (sum - pq.top());
            
//             if (sum_diff >= 1) pq.push(sum_diff);
//             else return false;
            
//             sum = sum - (target_max - sum_diff);
            
//             pq.pop();
//         }
        
//         return sum == target.size() ? true : false;
        
        // Above code shows TLE for cases like [1, 1000000]
        // since here after subtraction the current value stays highest
        // so the loop runs 1000000 times thus TLE
        
        // optimizing using mod operator
        
        
        int64_t sum = 0;
        priority_queue<int> pq;

        for(auto v : target)
        {
            pq.push(v);
            sum += v;
        }

        while(pq.top() != 1)
        {
            int target_max = pq.top();
            pq.pop();
            
            // getting remaining sum after removing the maximum element
            int64_t remaining_sum = sum - target_max;
            
            // if diff = target_max - remaining_sum <= 1 or remaining_sum < 1 then not possible
            if (target_max <= remaining_sum || remaining_sum < 1)
                return false;
            
            // add remaining sum + mod value instead of subtraction 
            sum = remaining_sum + target_max % remaining_sum;
            // if case mod value turns to 0 push remaining sum
            pq.push(target_max % remaining_sum ? target_max % remaining_sum : remaining_sum);

        }
        
        return true;
        
        
    }
};