class Solution {
public:
    int mod = 1e9 + 7;
    vector<int>DP;
    int score(int i, int z, int o)
    {
        if(i < 0)return 0;
        if(i == 0)return 1;
        if(DP[i] != -1)return DP[i];
        long long ans = 0;
        
        ans = (ans + score(i - z, z, o) + score(i - o, z, o))%mod;
        return DP[i] = ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        
        DP.resize(high + 5, -1);
        int ans = 0;
        for(int i = low; i <= high; i++)
        {
            ans = (ans + score(i, zero, one)) % mod;
            
        }
        return ans;
        
    }
};