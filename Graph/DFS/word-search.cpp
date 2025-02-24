// https://leetcode.com/problems/word-search/


class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int idx, int i, int j,
               vector<vector<bool>>& vis) {

        if (idx >= word.length())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            vis[i][j])
            return false;

        if (word[idx] != board[i][j])
            return false;

        vis[i][j] = true;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (solve(board, word, idx + 1, nx, ny, vis))
                return true;
        }
        vis[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size() + 1,
                                 vector<bool>(board[0].size() + 1, false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && solve(board, word, 0, i, j, vis))
                    return true;
            }
        }
        return false;
    }
};