class Solution {
public:
    
    int findPath(int x, int y, vector<vector<int>>& dp)
    {
        if(x == 0 && y == 0)return 1;
        if(x < 0 || y < 0)return 0;
        if(dp[x][y] != -1)return dp[x][y];
        return dp[x][y] = (findPath(x - 1, y, dp) + findPath(x, y - 1, dp));      
            
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return findPath(m - 1, n - 1, dp);
    }
};