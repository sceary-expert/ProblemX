class Solution {
public:
    bool foundTarget = false;
    vector<vector<int>>dp;
    void helper(int ind, int t, vector<int>&nums)
    {
        if(t < 0 )return;
        if(dp[ind][t] != -1)return;
        dp[ind][t] = 1;
        if(foundTarget== true)return;
        if(t == 0){
            foundTarget = true;
            return;
        }
        if(ind >= nums.size())return;
        helper(ind + 1, t - nums[ind], nums);
        helper(ind + 1, t, nums);
        return;
    }
    bool isTargetSumPossible(vector<int>&nums, int target)
    {
        helper(0, target, nums);
        return foundTarget;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &n : nums)sum += n;
        if(sum % 2)return false;
        int target = sum / 2;
        int n = nums.size();
        dp.resize(n + 1, vector<int>(sum + 1, - 1));
        return isTargetSumPossible(nums, target);
        
    }
};