class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int n = arr.size() ; 
        int m = arr[0].size() ; 
        int count = 0; 

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(arr[i][j] == 0) continue; //doesnt matter if it is side or middle
                if(i>0 && j > 0){
                    arr[i][j] += min({arr[i-1][j], arr[i][j-1], arr[i-1][j-1]});   
                }
                count += arr[i][j] ; 
            }
        }
        return count ; 
    }
};