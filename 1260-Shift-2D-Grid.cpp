class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int tot = m*n; 
        k = k % (tot);

        vector<int> v;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v.push_back(grid[i][j]);
            }
        }

        reverse(v.begin(), v.begin() + tot - k);
        reverse(v.begin() + tot - k, v.end());
        reverse(v.begin(), v.end());

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
               grid[i][j] = v[i*n+j];
            }
        }

        return grid;
    }
};