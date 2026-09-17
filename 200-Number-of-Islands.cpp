class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis,
             int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0' ||
            vis[i][j] == 1)
            return;

        vis[i][j] = 1; // visit it

        dfs(i + 1, j, grid, vis, n, m); // top
        dfs(i - 1, j, grid, vis, n, m); // bottom
        dfs(i, j + 1, grid, vis, n, m); // right
        dfs(i, j - 1, grid, vis, n, m); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int island = 0;

        // check for every node = count number of component
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, grid, vis, n, m);
                    island++;
                }
            }
        }
        return island;
    }
};