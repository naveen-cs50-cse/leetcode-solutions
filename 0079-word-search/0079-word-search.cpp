class Solution {
public:

    void check(vector<vector<char>>& board,
               int r, int c,
               string word,
               int count,
               int i, int j,
               vector<vector<int>>& vis,
               int& x)
    {
        // Out of bounds
        if (i < 0 || j < 0 || i >= r || j >= c)
        {
            return;
        }

        // Already visited
        if (vis[i][j])
        {
            return;
        }

        // Character doesn't match
        if (board[i][j] != word[count])
        {
            return;
        }

        // Entire word found
        if (count == word.size() - 1)
        {
            x = 1;
            return;
        }

        // Mark current cell
        vis[i][j] = 1;

        // Go in all 4 directions
        check(board, r, c, word, count + 1, i - 1, j, vis, x);
        check(board, r, c, word, count + 1, i + 1, j, vis, x);
        check(board, r, c, word, count + 1, i, j - 1, vis, x);
        check(board, r, c, word, count + 1, i, j + 1, vis, x);

        // Backtrack
        vis[i][j] = 0;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int r = board.size();
        int c = board[0].size();

        vector<vector<int>> vis(r, vector<int>(c, 0));

        int x = 0;

        // Try every cell as starting point
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == word[0])
                {
                    check(board, r, c, word, 0, i, j, vis, x);

                    if (x == 1)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};