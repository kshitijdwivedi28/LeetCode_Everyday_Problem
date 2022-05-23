class Solution {
public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
        
//         vector<pair<int, int>> vp;
        
//         for(auto s : strs)
//         {
//             int count_ones = 0, count_zeroes = 0;
            
//             for(auto c : s)
//                 if (c == '0') count_zeroes++;
//                 else count_ones++;
            
//             vp.push_back({count_zeroes, count_ones});
//         }
        
//         sort(vp.begin(), vp.end());
        
//         int i = 0;
//         for(; i < vp.size(); i++)
//         {
//             bool zero = false, one = false;
//             if (m > 0 && n > 0)
//             {
//                 m -= vp[i].first;
//                 n -= vp[i].second;
//             }
//             else
//                 break;
//         }
        
//         if (m == 0 && n == 0)
//             return i;
        
//         else 
//             return i-1;
        
        
        
//     }
    pair<int,int> get(string &s)
    {
        int zero=0;
        int one=0;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='0')
                ++zero;
            else
                ++one;
        }
        return make_pair(one,zero);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vec;
        //get the count of number of 1's and number of 0's in each of the string and store them in a vec of pairs
        for(int i=0;i<strs.size();++i)
            vec.push_back(get(strs[i]));
        //sort that vector of pairs according to the number of 1's in increasing order (one can also go the other way of sorting according to the number of zeros)
        sort(vec.begin(),vec.end());
        /*( ----------> NOTE  <--------------)
if we have chosen a string then we will save the count of number of zeros of the string so that in future if we find a string that we cannot add beacuse we don't have enough zeros left then we will check wheather the number of zeros in this current string is smaller then the number of zeros in any of the previous choosen string , if this is the case then we will use this string instead of that previously choosen string and will increase the count of remaining zeros 
remaining zeros += number of zeros of a previosly choosen string in which the number of zeros are greater then the number of zeros in the current string(we can easily get this using map) - number of zeros of current string 

so there are 3 cases:
case 1: if we have enough zeros and ones remaining to capture the current string then we take the string and update remaining zeros and ones
case 2: if we dont have enough ones to capture the current string then we just break the loop beacuse we have already sorted our array in increasing order of number of ones so if we cant take this string then we cant take the future string beacuse they will definatly have more 1's then current string
case 3: if we dont have enough zero to capture the current string then we will check if we have a previously chosen string that is having more number of zeros then the current string then we will discard that string and use this string insted of that and update the remaining counts accordingly
*/
        map<int,int>map;
        int maxi=0;
        for(int i=0;i<vec.size();++i)
        {
            if(n<vec[i].first)//case 2
                break;
            else
            {
                if(m>=vec[i].second)//case 1
                {
                    m=m-vec[i].second;
                    n=n-vec[i].first;
                    map[vec[i].second]++;
                    maxi++;
                }
                else
                {
                    if(map.size()!=0)//case 3
                    {
                        auto it = --map.end();
                        if(it->first>vec[i].second)
                        {
                        m = m + it->first - vec[i].second; 
                        it->second = it->second-1;
                        if(it->second==0)
                            map.erase(it->first);
                        }
                    }
                }
            }
        }
        return maxi;
    }
};