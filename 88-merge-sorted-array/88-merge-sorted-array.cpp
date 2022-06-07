class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
//         if (n == 0)
//             return;
//         else if (m == 0)
//         {
//             for(int i = 0; i < n; i++)
//                 nums1.push_back(nums2[i]);
            
//             return;
//         }
//         else
//         {
//             for(int i = 0; i < n; i++)
//             {
//                 nums1[m+i] = nums2[i];
//             }
            
//             sort(nums1.begin(), nums1.end());
            
//             return;

//         }
        
        
        
        for(int i = 0; i < n; i++)
            nums1[m+i] = nums2[i];
            
        sort(nums1.begin(), nums1.end());
         
        
    }
};