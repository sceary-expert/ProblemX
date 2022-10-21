class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = grid[0][0];
           
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)continue;
                     int left = (i - 1 >= 0 && j >= 0)? dp[i - 1][j] : INT_MAX;
                     int up = (i >= 0 && j - 1 >= 0)?dp[i][j - 1] : INT_MAX;
                int curr = grid[i][j] + min(left, up);
                dp[i][j] = min(dp[i][j], curr);
                
                
            }
        }
        return dp[m - 1][n - 1];
    }
};