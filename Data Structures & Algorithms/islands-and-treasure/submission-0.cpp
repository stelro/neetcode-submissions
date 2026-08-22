class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int inf = 2147483647;

	int rows = grid.size();
	int cols = grid[0].size();

	std::queue<std::pair<int, int>> q;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] == 0) {
				q.push({i, j});
			}
		}
	}

	std::vector<std::vector<int>> dir {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	while (!q.empty()) {
		auto [row, col] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int r = row + dir[i][0];
			int c = col + dir[i][1];

			if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != inf) {
				continue;
			}

			grid[r][c] = grid[row][col] + 1;
			q.push({r, c});
		}
	}
    }
};
