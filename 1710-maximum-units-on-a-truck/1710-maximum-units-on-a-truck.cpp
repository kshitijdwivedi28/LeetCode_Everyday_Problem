class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        auto comp = [](vector<int>&a, vector<int>&b){
          return a[1] > b[1]; 
        };
        
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        int total_units = 0, total_boxes = 0;
        for(auto v : boxTypes)
        {
            if (total_boxes + v[0] < truckSize)
            {
                total_units += (v[0] * v[1]);
                total_boxes += v[0];
                
            }
            else
            {
                int req_boxes = truckSize - total_boxes;
                total_units += req_boxes * v[1];
                break;
            }
        }
        
        return total_units;
    }
};