class Solution {
public:
    vector<vector<int>>memo;
    int maxi(vector<int>&jB, int curr, int n)
    {
        int mx = jB[curr];
        for(int i = curr + 1; i < n; i++)
        {
            int t = jB[i];
            if(t > mx)mx = t;
        }
        
        return mx;
    }
    int helper(int curr, int n, int d, vector<int>&jB)
    {
        if(memo[curr][d] != -1)return memo[curr][d];
        if(d == 1)
        {
            return memo[curr][d] = maxi(jB, curr, n);
            // return *max_element(begin(jB)+curr, end(jB));
        }
        int ans = INT_MAX;
        int currMax = INT_MIN;
        for(int i = curr; i <= n  - d ; i++ )
        {
            
            int t = jB[i];
            if(t > currMax)currMax = t;
            int temp = currMax + helper(i + 1, n, d - 1, jB);
            if(temp < ans)ans = temp;
        }
        return memo[curr][d] = ans;
        
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d)return -1;
            vector<vector<int>>dp(n + 1, vector<int>(d + 1, -1));
            memo = dp;
        return helper(0, n, d, jobDifficulty);
        
    }
};