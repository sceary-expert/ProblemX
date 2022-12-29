class Solution {
public:
    int M, N;
    bool isValid(int i, int j)
    {
        if(i < 0 || j < 0 || i >= M || j >= N)return false;
        return true;
    }
    vector<vector<int>>dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool DFS(vector<vector<char>>& board, string word, int ind, int i, int j)
    {
        if(ind == word.size())return true;
        char temp = board[i][j];
        board[i][j] = '#';
        for(auto &d : dir)
        {
            int new_i = i + d[0];
            int new_j = j + d[1];
            
            if(isValid(new_i, new_j) && board[new_i][new_j] == word[ind])
            {
                bool f = DFS(board, word, ind + 1, new_i, new_j);
                if(f == true)return true;
            }
        }
        board[i][j] = temp;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        M = m, N = n;
        char w = word[0];
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == w)
                {
                    bool f = DFS(board, word, 1, i, j);
                    if(f == true)return true;
                }
            }
        }
        return false;
    }
};