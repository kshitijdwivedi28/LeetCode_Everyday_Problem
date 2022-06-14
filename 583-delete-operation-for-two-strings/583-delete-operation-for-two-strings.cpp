class Solution {
public:

        
//         vector<int> freq_word1(26, 0);
//         vector<int> freq_word2(26, 0);
//         int diff_count = 0;
        
//         for(auto c : word1) freq_word1[c-'a']++;
//         for(auto c : word2) freq_word2[c-'a']++;
        
//         for(int i = 0; i < 26; i++)
//             diff_count += abs(freq_word1[i] - freq_word2[i]);
        
//         return diff_count;
        
        int lcs(string X, string Y,int m,int n){
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(X[i-1]==Y[j-1]) dp[i][j]= 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
    int minDistance(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        return m+n-2*lcs(s1,s2,m,n) ;
    
    }
};