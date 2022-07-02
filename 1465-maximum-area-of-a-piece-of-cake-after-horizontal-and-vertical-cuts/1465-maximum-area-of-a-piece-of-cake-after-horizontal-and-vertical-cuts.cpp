class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
    {
        // APPROACH - 
        // Calculate maximum difference between two cuts in horizontal array and vertical array
        // and then multiply them to get the maximum area.
        
        // sorting to get all the cuts in proper format ordered.
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        // finding max length among initial and final pieces by horizontal cuts
        int max_horizontal_cut = max(horizontalCuts[0], h - horizontalCuts.back());
        
        // finding max breath among initial and final pieces by vertical cuts
        int max_vertical_cut = max(verticalCuts[0], w - verticalCuts.back());
        
        // Calculating max length among all horizontal cuts
        for(int i = 1; i < horizontalCuts.size(); i++)
            max_horizontal_cut = max(max_horizontal_cut, horizontalCuts[i] - horizontalCuts[i-1]);
        
        // Calculating max breadth among all vertical cuts
        for(int i = 1; i < verticalCuts.size(); i++)
            max_vertical_cut = max(max_vertical_cut, verticalCuts[i] - verticalCuts[i-1]);

        // Calculating and returning max area mod 1e9+7
        return (int)((long)max_horizontal_cut * max_vertical_cut % 1000000007);
        
        
        // NOTE - Converting to long first to prevent overflow of values 
        // First convert into long and then to int as required

    }
};