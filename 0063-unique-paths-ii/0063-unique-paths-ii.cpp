class Solution {
public:
    int findPath(int x, int y, vector<vector<int>>&dp, vector<vector<int>>& grid)
    {
        if(x < 0 || y < 0 ||grid[x][y] ==  1)return 0;
        if(x == 0 && y == 0)return 1;
        if(dp[x][y] !=  -1)return dp[x][y];
                
        int up = findPath(x, y - 1, dp, grid);
        int left = findPath(x - 1, y, dp, grid);
        //cout<<"UP : "<<up<<" left : "<<left<<endl;
        //(grid[x][y - 1] == -1 || grid[x - 1][y] == -1) return dp[x][y] = 0;
        
        return dp[x][y] = up + left;
        
        
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
        return findPath(m - 1, n - 1, dp, obstacleGrid);
        
    }
};