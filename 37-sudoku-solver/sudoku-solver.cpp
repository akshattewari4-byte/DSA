class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {

        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num)
                return false;
        }

        // Check 3x3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        // Find empty cell
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {

                    // Try 1 to 9
                    for (char num = '1'; num <= '9'; num++) {

                        if (isSafe(board, i, j, num)) {

                            // Choose
                            board[i][j] = num;

                            // Explore
                            if (solve(board))
                                return true;

                            // Backtrack / Undo
                            board[i][j] = '.';
                        }
                    }

                    // No number worked
                    return false;
                }
            }
        }

        // No empty cell -> Sudoku solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};