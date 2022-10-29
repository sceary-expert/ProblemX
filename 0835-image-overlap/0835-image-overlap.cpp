class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>>v1;
        vector<pair<int, int>>v2;
        int n = img1.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(img1[i][j] == 1)v1.push_back({i, j});
                if(img2[i][j] == 1)v2.push_back({i, j});
            }
        }
        map<pair<int, int>, int>mp;
        int ans = 0;
        for(auto [x, y] : v1)
        {
            for(auto [i, j] : v2)
            {
                mp[{x - i, y - j}]++;
                ans = max(ans, mp[{x - i, y - j}]);
            }
        }
        return ans;
        
    }
};