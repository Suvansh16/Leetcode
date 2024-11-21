class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Initialize the grid with 'l' (unguarded)
        vector<vector<char>> temp(m, vector<char>(n, 'l'));

        // Mark walls in the grid
        for (int i = 0; i < walls.size(); i++) {
            int a = walls[i][0];
            int b = walls[i][1];
            temp[a][b] = '#';
        }

        // Mark guards in the grid
        for (int i = 0; i < guards.size(); i++) {
            int a = guards[i][0];
            int b = guards[i][1];
            temp[a][b] = 'G'; // Guard's position
        }

        // Mark guarded areas for each guard
        for (int i = 0; i < guards.size(); i++) {
            int a = guards[i][0];
            int b = guards[i][1];
            int x = a, y = b;

            // Downward direction
            x++;
            while (x < m && temp[x][b] != '#' && temp[x][b] != 'G') {
                temp[x][b] = 'o';
                x++;
            }

            // Upward direction
            x = a - 1;
            while (x >= 0 && temp[x][b] != '#' && temp[x][b] != 'G') {
                temp[x][b] = 'o';
                x--;
            }

            // Leftward direction
            x = a;
            y = b - 1;
            while (y >= 0 && temp[x][y] != '#' && temp[x][y] != 'G') {
                temp[x][y] = 'o';
                y--;
            }

            // Rightward direction
            y = b + 1;
            while (y < n && temp[x][y] != '#' && temp[x][y] != 'G') {
                temp[x][y] = 'o';
                y++;
            }
        }

        // Count unguarded cells
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (temp[i][j] == 'l') {
                    count++;
                }
            }
        }

        return count;
    }
};
