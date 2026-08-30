bool cmp (vector<int>& a , vector<int> & b){ //start time
    return a[0]<b[0] ; 
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size() ; 
        sort(arr.begin() , arr.end() , cmp) ; 
        int ans = 0;
        int lastEndTime = arr[0][1] ;  

        for(int i = 1 ; i<n ; i++){
            if(lastEndTime > arr[i][0]) {
                ans++; 
                lastEndTime = min(lastEndTime , arr[i][1]) ; 
            }
            else lastEndTime = arr[i][1] ; 
        }
        return ans; 
    }
};
// bool cmp (vector<int>& a , vector<int> & b){ //end time
//     return a[1]<b[1] ; 
// }
// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& arr) {
//         int n = arr.size() ; 
//         sort(arr.begin() , arr.end() , cmp) ; 
//         int ans = 0;
//         int lastEndTime = arr[0][1] ;  

//         for(int i = 1 ; i<n ; i++){
//             if(lastEndTime > arr[i][0]) ans++; 
//             else lastEndTime = arr[i][1] ; 
//         }
//         return ans; 
//     }
// };