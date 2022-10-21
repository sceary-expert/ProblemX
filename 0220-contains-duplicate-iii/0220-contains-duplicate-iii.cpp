class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int iD, int vD) {
        queue<int>q;
        // map<int, int>mp;
        set<int>st;
        for(auto &it : nums)
        {
            q.push(it);
            //mp[it]++;
            //st.insert(it);
            while(q.size() > iD + 1)
            {
                //mp[q.front]--;
                st.erase(q.front());
                q.pop();
            }
            auto itr= st.upper_bound(it);
            if(itr != st.end() && abs(*itr - it)  <= vD)
            {
                //cout<<*itr<<endl;
                return true;
            }
            if(itr != st.begin())
            {
                itr--;
                if(abs(*itr- it) <= vD)
                {
                    //cout<<*itr<<endl;
                    return true;
                }
            }
            st.insert(it);
        }
        return false;
    }
};