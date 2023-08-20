class Solution {
    bool isSafe(int row, int col, vector<string> &board, int n) { // TC: O(n)
        // check for same row
        int x = row;
        int y = col;
        while(y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            y--;
        }

        // check for digonals

        // check for LU diagonal
        x = row;
        y = col;
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }
        // check for LD diagonal
        x = row;
        y = col;
        while(x < n && y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, int n, vector<vector<string>> &ans) {
        // base case
        if(col == n) {
            ans.push_back(board);
            return;
        }

        // solve 1 case and rest recurssion will take care
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n)) { // isSafe func() --> TC: O(n)
                board[row][col] = 'Q';
                solve(col+1, board, n, ans);
                // backtrack
                board[row][col] = '.';
            }
        }
    }

    public:
    vector<vector<string>> solveNQueens(int n) {
        // write your code here

        vector<string> board(n, string(n, '.')); // SC: O(n*n)
        vector<vector<string>> ans; // SC: O(n*n*n)

        solve(0, board, n, ans);

        return ans;
    }
};