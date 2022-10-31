class Solution {
public:
    vector<vector<bool>>vis;
    bool isValid(int i, int j, int m, int n)
    {
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] == true)return false;
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>>q;
        q.push({m - 1, 0});
        vis.resize(m + 1, vector<bool>(n + 1, false));
        while(q.size())
        {
            int sz = q.size();
            int x = q.front().first, y = q.front().second;
            int curr = matrix[x][y];
            for(int o = 0; o < sz; o++)
            {
                auto t = q.front();
                q.pop();
                int i = t.first, j = t.second;
                if(matrix[i][j] != curr)return false;
                //up ans down;
                if(isValid(i - 1, j, m , n))
                {
                    q.push({i - 1, j});
                    vis[i - 1][j] = true;
                }
                if(isValid(i , j + 1, m , n))
                {
                    vis[i][j + 1] = true;
                    q.push({i , j + 1});
                }
                
            }
        }
        return true;        
    }
};