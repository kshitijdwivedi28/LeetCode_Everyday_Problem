// 997. Find the Town Judge
// Easy

// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

// Example 1:

// Input: n = 2, trust = [[1,2]]
// Output: 2
// Example 2:

// Input: n = 3, trust = [[1,3],[2,3]]
// Output: 3
// Example 3:

// Input: n = 3, trust = [[1,3],[2,3],[3,1]]
// Output: -1
 

// Constraints:

// 1 <= n <= 1000
// 0 <= trust.length <= 104
// trust[i].length == 2
// All the pairs of trust are unique.
// ai != bi
// 1 <= ai, bi <= n
// Accepted
// 220,760
// Submissions
// 439,991


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
//         unordered_map<int, int> town;
//         unordered_map<int, int> trust2;
        
//         for(auto value : trust)
//             trust2[value[0]] = value[1];
        
//         for(int i = 1; i <= n; i++)
//             town[i] = 0;

//         for(auto value : trust)
//             town[value[1]]++;

//         for(auto value : town)
//             if (value.second == n-1)
//                 if (trust2.find(value.first) == trust2.end())
//                     return value.first;
        
//         return -1;
        
        // Modifiy
//         unordered_map<int, int> trustor, trustee;
        
//         for(auto value : trust)
//         {
//             trustor[value[0]]++;
//             trustee[value[1]]++;
//         }

//         for(int i = 1; i <= n; i++)
//             if (trustor[i] == 0 && trustee[i] == n-1)
//                 return i;
        
//         return -1;
        
        
        
        // without using maps and using graph concept of indegree and outdegree (Hint : Graph)
        vector<int> in(n+1), out(n+1);
        
        for(auto value : trust) 
        {
            in[value[1]]++;
            out[value[0]]++;
        }
        
        for(int i=1; i<=n; ++i)
            if(in[i] == n-1 && out[i] == 0)
                return i;
        
        return -1;

    }
};