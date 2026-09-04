class Solution {
public:

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<pair<int,int>, int>> q;

        q.push({{entrance[0], entrance[1]}, 0});

        // Mark entrance visited
        maze[entrance[0]][entrance[1]] = '+';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Outside
                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Wall or visited
                if(maze[nr][nc] == '+')
                    continue;

                // Exit
                if(nr == 0 || nr == m-1 ||
                   nc == 0 || nc == n-1)
                {
                    return dist + 1;
                }

                // Mark visited
                maze[nr][nc] = '+';

                q.push({{nr, nc}, dist + 1});
            }
        }

        return -1;
    }
};