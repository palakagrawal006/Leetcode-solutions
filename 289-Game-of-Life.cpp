class Solution {
public:
    void gameOfLife(vector<vector<int>>& arr) {
        int  n = arr.size() ; 
        int m = arr[0].size() ; 

        int dx[] = {-1, -1, -1 , 0 , 1 , 1, 1, 0}; 
        int dy[] = {-1, 0, 1 , 1 , 1 , 0, -1, -1}; 



        for(int i = 0 ; i<n ; i++){
            for(int j =0;j<m ; j++){

                // count live
                int live = 0 ; 
                for(int d = 0 ; d<8; d++){
                    int ni = i+dx[d] , nj = j + dy[d] ; 

                    if(ni<n && ni>=0 && nj<m && nj>=0  && (arr[ni][nj] == 1 || arr[ni][nj] == -1)) live++ ; 
                }

                // apply rules
                if(arr[i][j] == 1 && (live <2 || live>3)) arr[i][j] = -1; 
                else if(arr[i][j] == 0 && (live ==3)) arr[i][j] = 2; 

            }
        }

        for(int i = 0 ; i<n ; i++){
            for(int j =0;j<m ; j++){
                arr[i][j] = (arr[i][j]<=0) ? 0 : 1 ;
            }
        }
    }
};