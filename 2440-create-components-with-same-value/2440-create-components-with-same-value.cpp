class Solution {
public:
    int DFS(map<int, vector<int>>&mp, vector<int>&nums, int curr, int  par, int target )
    {
        int total = nums[curr];
        for(auto &e : mp[curr])
        {
            if(e == par)continue;
            total += DFS(mp, nums, e, curr, target);
        }
        
        if(total == target)return 0;
        return total;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        map<int, vector<int>>mp;
        for(auto &it :edges){
            int c1 = it[0], c2 = it[1];
            mp[c1].push_back(c2);
            mp[c2].push_back(c1);            
        }
        
        int mx = -1, sum = 0;
        for(auto &it : nums)
        {
            if(it > mx)mx = it;
            sum += it;
        }
        int ans = 0;
        for(int x = mx; x <= sum; x++)
        {
            //can I make a total of sum / x componemnt by deleting 
            if(sum % x != 0)continue;
            if(DFS(mp, nums, 0, -1, x) == 0)
            {
                ans = max(ans, (sum/x) - 1);
            }
        }
            
        
         return ans;   
    }
};