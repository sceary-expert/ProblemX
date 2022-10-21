class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f = INT_MAX, s = INT_MAX, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int c = nums[i];
            if(c < f)
            {
                f = c;
            }
            else if(c > f && c < s)
            {
                s = c;
            }
            else if(c > f && c > s)
            {
                return true;
            }
            else{
                continue;
            }
        }
        return false;
    }
};