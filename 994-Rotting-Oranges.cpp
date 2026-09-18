class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n =grid.size() ; 
        int m = grid[0].size() ;
        int ans = 0 ; //time

        queue <pair<pair<int, int>, int>> q ;
        vector<vector<bool>> vis(n, vector<bool>(m, 0)) ; 

        for(int i = 0 ; i<n ; i++){
            for(int j=0 ;j<m ; j++){
                if(grid[i][j]==2) q.push({{i,j} , 0}) ; 
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front().first ;
            int t = q.front().second ; 
            q.pop() ; 

            ans = max(ans,t) ; 

            if(i-1>=0 && grid[i-1][j]==1 && vis[i-1][j]==0){//bottom
                vis[i-1][j] = 1;
                q.push({{i-1,j} , t+1}) ;
            }
            if(i+1<n && grid[i+1][j]==1 && vis[i+1][j]==0){ // top
                vis[i+1][j] = 1;
                q.push({{i+1,j} , t+1}) ;
            }
            if(j-1>=0 && grid[i][j-1]==1 && vis[i][j-1]==0){//left
                vis[i][j-1] = 1;
                q.push({{i,j-1} , t+1}) ;
            }
            if(j+1 <m && grid[i][j+1]==1 && vis[i][j+1]==0){ // left
                vis[i][j+1] = 1;
                q.push({{i,j+1} , t+1}) ;
            }
        }

        // check fresh orange && it is not viisted
         for(int i = 0 ; i<n ; i++){
            for(int j=0 ;j<m ; j++){
                if(grid[i][j]==1 && vis[i][j]==0)return -1 ; 
            }
        }
        return ans; 
    }
};