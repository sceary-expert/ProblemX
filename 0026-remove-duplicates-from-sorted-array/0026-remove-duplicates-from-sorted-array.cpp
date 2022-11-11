class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(auto&it :nums)
        {
            st.insert(it);
        }
        int ind = 0;
        vector<int>newNums;
        for(auto &it : st)
        {
            newNums.push_back(it);
            
        }
        int n = st.size();
        for(int i = n; i < nums.size(); i++)
        // {
        //     nums[i] = '_';
        // }
            nums = newNums;
        return n;
    }
};