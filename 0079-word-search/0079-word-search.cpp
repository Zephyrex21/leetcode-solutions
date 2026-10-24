class Solution {
private:
    bool dfs(int row, int col, int index,
             vector<vector<char>>& board,
             string& word,
             vector<vector<bool>>& visited) {

        // All letters matched
        if (index == word.size()) {
            return true;
        }

        // Check grid boundaries
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size()) {
            return false;
        }

        // Wrong letter or cell already used
        if (visited[row][col] ||
            board[row][col] != word[index]) {
            return false;
        }

        // Mark the current cell
        visited[row][col] = true;

        // Search in all four directions
        bool found =
            dfs(row + 1, col, index + 1, board, word, visited) ||
            dfs(row - 1, col, index + 1, board, word, visited) ||
            dfs(row, col + 1, index + 1, board, word, visited) ||
            dfs(row, col - 1, index + 1, board, word, visited);

        // Backtrack: make the cell available again
        visited[row][col] = false;

        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) {
            return true;
        }

        if (board.empty() || board[0].empty()) {
            return false;
        }

        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(
            n, vector<bool>(m, false)
        );

        // Try every cell as the starting point
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (dfs(i, j, 0, board, word, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};