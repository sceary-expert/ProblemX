class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long int prevSum = 0, currSum = 0;
        map<int, int>mp;
        currSum += nums[0];
        for(int i = 0; i < n - 1; i++)
        {
            currSum += nums[i + 1];
            prevSum += nums[i];
            int mod = currSum % k;
            if(mp[mod] > 0 || currSum % k == 0)
            {
                return true;
            }     
            
            mp[prevSum % k]++;
        }
        return false;
    }
};