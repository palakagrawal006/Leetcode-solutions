class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();

        // arrange in order of units-  decreasing order
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int maxUnits = 0;

        for (int i = 0; i < n; i++) {
            int box = boxTypes[i][0] ; 
            int unit = boxTypes[i][1] ; 
            if(box <= truckSize ){
                truckSize -= box; 
                maxUnits += unit*box; 
            }
            else { //box > truck size
                maxUnits += unit*truckSize;
                truckSize = 0 ;
                break ;
            }
        }
        return maxUnits ; 
    }
};