class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
  int result = 0;
	std::queue<std::pair<int, int>> q;
	int fresh_oragnes = 0;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 2) {
				q.push({i, j});
			}
			if (grid[i][j] == 1) {
				fresh_oragnes++;
			}
		}
	}

	int n = grid.size();
	int m = grid[0].size();
	
	while (!q.empty()) {

		int size = q.size();

		for (int i = 0; i < size; i++) {

			auto [x,y] = q.front();
			q.pop();

			if ((x - 1 >= 0) && (grid[x-1][y] == 1)) {
				q.push({x-1, y});
				grid[x-1][y] = 2;
				fresh_oragnes--;
			}
			if ((y - 1 >= 0) && (grid[x][y - 1] == 1)) {
				q.push({x, y - 1});
				grid[x][y - 1] = 2;
				fresh_oragnes--;
			}
			if ((x + 1 < n) && (grid[x+1][y] == 1)) {
				q.push({x+1, y});
				grid[x+1][y] = 2;
				fresh_oragnes--;
			}
			if ((y + 1 < m) && (grid[x][y + 1] == 1)) {
				q.push({x, y + 1});
				grid[x][y + 1] = 2;
				fresh_oragnes--;
			}
		}
		result++;
	}

    if (fresh_oragnes > 0) return -1;
    return std::max(0, result - 1);

    }
	
};
