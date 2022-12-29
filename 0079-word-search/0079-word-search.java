class Solution {
    int N, M;
    int [][]dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    boolean isValid(int i, int j)
    {
        if(i >= N || j >= M || i < 0 || j < 0)return false;
        return true;
    }
    boolean DFS(char[][]board, String word, int i, int j, int ind)
    {
        if(ind == word.length())return true;
        char temp = board[i][j];
        board[i][j] = '#';
        char w = word.charAt(ind);
        for(int o = 0; o < 4; o++)
        {
            int new_i = i + dir[o][0];
            int new_j = j + dir[o][1];
            if(isValid(new_i, new_j) && board[new_i][new_j] == w)
            {
                boolean f = DFS(board, word, new_i, new_j, ind + 1);
                if(f == true)return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        int row = board.length, col = board[0].length;
        N = row;  M = col;
        char c = word.charAt(0);
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(board[i][j] != c)continue;
                boolean f = DFS(board, word, i, j, 1);
                if(f == true)return true;
            }
        }
        return false;
    }
}