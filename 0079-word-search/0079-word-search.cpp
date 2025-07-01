class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    
    bool solve(int i, int j, int k, vector<vector<char>>& board, string& word) {
        if (k == word.size()) return true;
        
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';  // mark visited

        for (vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (solve(new_i, new_j, k + 1, board, word))
                return true;
        }

        board[i][j] = temp; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (solve(i, j, 0, board, word)) // start from k=0 to include first character
                    return true;
            }
        }
        return false;
    }
};
