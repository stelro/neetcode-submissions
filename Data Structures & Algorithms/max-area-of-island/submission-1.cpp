class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& count) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        if (grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;
        count += 1;

        dfs(grid, i + 1, j, count);
        dfs(grid, i - 1, j, count);
        dfs(grid, i, j + 1, count);
        dfs(grid, i, j - 1, count);

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for (int i = 0; i < grid.size(); i++) {
            
            for (int j = 0; j < grid[0].size(); j++) {
                int count = 0;
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, count);
                }
                max = std::max(max, count);
            }
            
        }    
        return max;
    }
};
