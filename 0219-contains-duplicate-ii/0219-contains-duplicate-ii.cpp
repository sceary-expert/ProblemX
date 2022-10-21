class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        queue<int>q;
        map<int, int>mp;
        for(auto &it : nums)
        {
            q.push(it);
            mp[it]++;
            if(q.size() > k + 1)
            {
                mp[q.front()]--;
                q.pop();                
            }
            if(mp[it] >= 2)return true;
        }
        return false;
    }
};