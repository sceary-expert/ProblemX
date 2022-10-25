class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        map<int, int>mp;
        //mp[sum]++;
        for(auto &n : nums)
        {
            sum += n;
            
            ans += mp[sum - k];           
            mp[sum]++;
            if(sum == k)ans++;
        }
        return ans;
        
    }
};