class Solution {
public:
    int minimumNumbers(int num, int k) {
        
        if (num == 0) return 0;
        if (k > num) return -1;
        if (k == num || num%10 == k) return 1;
        if (k == 0) return -1;
        
        int ans = 0;
        bool check = false;
        
        for(int i = num; i >= 0; i-=k)
        {
            ans++;
            if (i%10 == k)
            {
                check = true;
                break;
            }
        }
        
        return check == false ? -1 : ans;
    }
};