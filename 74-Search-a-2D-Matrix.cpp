
// binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size() ; 
        int m =  mat[0].size() ;

        int lo = 0 , hi = n*m -1; 

        while(lo<=hi){
            int mid = lo + (hi-lo)/2 ; 
            int i = mid/m ; //row
            int j = mid % m ; // col 

            if(mat[i][j] == target) return true; 
            else if(mat[i][j] < target) lo= mid+1;  
            else hi = mid-1; 
        }
        return false; 
    }
};

// // staircase prob 
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& mat, int target) {
//         int n = mat.size() ; 
//         int m =  mat[0].size() ;

//         int i = 0 , j = m-1; 

//         while(i<n && j>=0){
//             if(mat[i][j] == target) return true; 
//             else if(mat[i][j] < target) i++; 
//             else j--; 
//         }
//         return false; 
//     }
// };