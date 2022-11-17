class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        map<pair<int, int>, int>vis;
        int ans = 0;
        for(int x = ay1; x < ay2; x++)
        {
            for(int y = ax1; y < ax2; y++)
            {
                vis[{y, x}]++;
                ans++;
            }
        }
        for(int x = by1; x < by2; x++)
        {
            for(int y = bx1; y < bx2; y++)
            {
                if(vis[{y, x}] == 0)
                ans++;
            }
        }
        
        return ans;        
    }
};