class Solution {
public:

    vector<vector<string>> ans;
    bool isSafe(int row,int col,vector<string> board,int n)
    {

        // 1. Check the column up to this row
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        for(int r=row,c=col;r>=0 && c>=0;r--,c--)
        {
            if(board[r][c]=='Q')
            {
                return false;
            }
        }

        // 3. Check upper-right diagonal
        for (int r = row, c = col; r >= 0 && c < n; r--, c++) {
            if (board[r][c] == 'Q') return false;
        }

        return true;
    }

    void solve(int row,vector<string> board,int n)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
            for(int col=0;col<n;col++)
            {
                if(isSafe(row,col,board,n))
                {
                    board[row][col]='Q';

                    solve(row+1,board,n);

                    board[row][col]='.';
                }
            }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n,string(n,'.'));
        solve(0,board,n);
        return ans;
    }
};