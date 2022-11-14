class Solution {
public:
    int DFS(vector<vector<int>>&stones, vector<int>&vis, int ind, int n)
    {
        vis[ind]++;
        int x = stones[ind][0], y = stones[ind][1], ans = 1;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                if(stones[i][0] == x || stones[i][1] == y)
                {
                    ans += DFS(stones, vis, i, n);
                }
            }
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        int ans =  1, n = stones.size();
        vector<int>vis(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)ans += (DFS(stones, vis, i, n) - 1);
        }
        return ans - 1;
    }
};