// class WordFilter {
// public:
//     vector<string> w;
    
//     WordFilter(vector<string>& words) {
        
//         w = words;
//     }
    
//     int f(string prefix, string suffix) {
        
//         int max_ind = INT_MIN;
        
//         for(int i = 0; i < w.size(); i++)
//         {
//             if (w[i].substr(0, prefix.size()) == prefix && w[i].substr(w[i].size() - suffix.size(), w.size()) == suffix)
//                 max_ind = max(max_ind, i);
//         }
        
//         return max_ind == INT_MIN ? -1 : max_ind;
//     }
// };

class WordFilter {
   private:
    unordered_map<string, int> hashMap;

   public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int wordSize = word.size();
            for (int j = 1; j <= wordSize; j++) {
                string p = word.substr(0, j);
                for (int k = 0; k < wordSize; k++) {
                    string s = word.substr(k, wordSize);
                    hashMap[p + "|" + s] = i + 1;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string s = prefix + "|" + suffix;
        return hashMap[s] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */