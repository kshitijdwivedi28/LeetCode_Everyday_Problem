// 273. Integer to English Words
// Hard

// Convert a non-negative integer num to its English words representation.

// Example 1:

// Input: num = 123
// Output: "One Hundred Twenty Three"
// Example 2:

// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"
// Example 3:

// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

// Constraints:

// 0 <= num <= 2^31 - 1

class Solution {
public:
    string nums_to_string(int n)
    {
        vector<string> ones {"", "One", "Two", "Three", "Four", "Five", "Six",
        "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
        
        vector<string> tens {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
        "Seventy", "Eighty", "Ninety"};
        
        if (n < 20)
            return ones[n];
        else if (n < 100)
            return tens[n/10] + " " + nums_to_string(n%10);
        else if (n < 1000)
            return nums_to_string(n/100) + " Hundred " + nums_to_string(n%100);
        else if (n < 1000000)
            return nums_to_string(n/1000) + " Thousand " + nums_to_string(n%1000);
        else if (n < 1000000000)
            return nums_to_string(n/1000000) + " Million " + nums_to_string(n%1000000);
        else
            return nums_to_string(n/1000000000) + " Billion " + nums_to_string(n%1000000000);

    }
    
    string numberToWords(int num) {
        
        if (num == 0)
            return "Zero";

        string ans = "";
        
        stringstream ss = (stringstream)nums_to_string(num);
        string n;
        
        while(getline(ss, n, ' '))
            if (n.size())
                ans += n + " ";
        
        ans.pop_back();
        
        return ans;
    }

};