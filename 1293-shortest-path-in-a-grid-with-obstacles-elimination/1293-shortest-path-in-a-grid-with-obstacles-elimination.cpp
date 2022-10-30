class Solution {
public:
    #define pii pair<int, pair<int, int>>
    bool isValid(int ni, int  nj, int m, int  n)
    {
        if(ni < 0 || nj < 0 || ni >= m || nj >= n )return false;
        return true;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), steps = 0;
       // bool vis[m + 1][n + 1][k + 1];
        vector<vector<vector<bool>>>vis(m + 1,  vector<vector<bool>>(n + 1, vector<bool>(k + 1, false)));
        queue<pii>q;
        
        q.push({0, {0, k}});
        vis[0][0][k] = true;
        vector<vector<int>>dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(q.size())
        {
            int sz = q.size();
            for(int o = 0; o < sz; o++)
            {
                pii t = q.front();
                q.pop();     
                
                int i = t.first;
                int j = t.second.first;
                int l = t.second.second;
                if(i == m - 1 && j == n - 1 && l >= 0)return steps;
                for(auto &d : dir)
                {
                    int ni = i + d[0];
                    int nj = j + d[1];
                    int nl = l;
                    
                    if(isValid(ni, nj, m, n))
                    {
                        nl -= grid[ni][nj];
                        if(nl >= 0 && vis[ni][nj][nl] == false)
                        {
                            vis[ni][nj][nl] = true;
                            q.push({ni, {nj, nl}});
                        }
                        
                    }
                }
                
                
                
                
            }
            steps++;
           
            
            
        }
        return -1;
        
    }
};