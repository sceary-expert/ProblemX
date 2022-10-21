class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>mp;
        int mxFreq = 0;
        for(auto &s : words)
        {
            mp[s]++;
            if(mp[s] > mxFreq)mxFreq = mp[s];
        }
        vector<string>ans;
        
        
        vector< vector<string>>pm(mxFreq + 1);
        for(auto &it : mp)
        {
            int f = it.second;
            string s = it.first;
            
            
            
            pm[f].push_back(s);
        }
        
        
        for(int i = mxFreq; i > 0; i--)
        {
            auto v = pm[i];
            sort(v.begin(), v.end());
            for(auto &s : v)
            {
                ans.push_back(s);
                k--;
                if(k <= 0)
                {
                    //reverse(ans.begin(), ans.end());
                    return ans;
                }
            }
        }
            return {};
    }
};