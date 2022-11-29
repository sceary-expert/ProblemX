class Solution {
    public int maximalSquare(char[][] matrix) {
        int m = matrix.length, n = matrix[0].length, ans = 0;
        // List<List<int>>DP(m, vector<int>(n, 0));
        int [][]DP = new int[m][n];
        for(int i = 0; i < m; i++)
        {
            DP[i][n - 1] = matrix[i][n - 1] - '0';
            if(DP[i][n - 1] == 1)ans = 1;
        }
        for(int i = 0; i < n; i++)
        {
            DP[m - 1][i] = matrix[m - 1][i] - '0';
            if(DP[m - 1][i] == 1)ans = 1;
        }
        for(int i = m - 2; i >= 0; i--)
        {
            for(int j = n - 2; j >= 0; j--)
            {
                if(matrix[i][j] == '0')continue;
                DP[i][j] = 1 + Math.min(DP[i + 1][j + 1], Math.min(DP[i + 1][j], DP[i][j + 1]));
                ans = Math.max(DP[i][j], ans);
                
            }
        }
//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
                
//                 cout<<DP[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        return ans * ans;
    }
}