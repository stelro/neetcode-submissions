class Solution {
public:
void dfs(std::vector<std::vector<char>>& board, int i, int j) {
	if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
		return;
	}

	if (board[i][j] != 'O') {
		return;
	}

	board[i][j] = 'S';

	dfs(board, i + 1, j);
	dfs(board, i - 1, j);
	dfs(board, i, j + 1);
	dfs(board, i, j - 1);
}

void solve(std::vector<std::vector<char>>& board) {
	if (board.empty()) return;

	int rows = board.size();
	int cols = board[0].size();

	// Mark all 'O's connected to the boarder
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) && board[i][j] == 'O') {
				dfs(board, i, j);
			}
		}
	}

	// Flip surrounded 'O' to 'X', restore 'S' to 'O'
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = (board[i][j] == 'S') ? 'O' :
				(board[i][j] == 'O') ? 'X' : board[i][j];
		}
	}
}
};
