class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // TOO LONG - BASIC + GREEDY O(n^2)
        
//         map<int,int> mp;
        
//         for(auto value : numbers)
//             mp[value]++;
        
        
//         for(int i = 0; i < numbers.size(); i++)
//         {
//             if (mp.find(target - numbers[i]) != mp.end())
//             {
//                 ans.push_back(i+1);
                
//               //  cout << i+1 << " " << numbers[i] << endl;
                
//                 int idx2 = find(numbers.begin(), numbers.end(), (target - numbers[i])) - numbers.begin();
                
//               //  cout << idx2+1 << " " << numbers[idx2] << endl;
                
//                 if (numbers[idx2] == numbers[i])
//                     ans.push_back(idx2+2);
//                 else
//                     ans.push_back(idx2+1);
                
//                 break;
//             }
//         }
        
        
        // O(n) using two pointer
        // Taking the benefit of sorted array
        
        int idx1 = 0, idx2 = numbers.size()-1;
        
        while(idx1 < idx2)
        {
            if (numbers[idx1] + numbers[idx2] == target)
                break;
            
            else if (numbers[idx1] + numbers[idx2] < target)
                idx1++;
            else
                idx2--;
        }
        
        return {idx1+1, idx2+1};
        
    }
};