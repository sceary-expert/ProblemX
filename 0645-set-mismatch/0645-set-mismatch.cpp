class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n + 1, 0);
        for(auto &it : nums)
        {
            v[it]++;
            
        }
        int t, d;
        for(int i = 1; i <= n; i++)
        {
            if(v[i] == 2)t = i;
            if(v[i] == 0)d = i;
        }
        return {t, d};
    }
};