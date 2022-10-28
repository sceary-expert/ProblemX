class Solution {
public:
    string getBit(string s)
    {
        // int bit = 0;
        // for(auto &c : s)
        // {            
        //     int j = c - 'a';
        //     bit |= (1<<j);            
        // }       
        // return bit;        
        string bit = s;
        sort(bit.begin(), bit.end());
        return bit;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string, vector<string>>mp;      
        for(auto &s : strs)
        {
            string bit = getBit(s);
            mp[bit].push_back(s);
        }
        for(auto &it : mp)
        {
            auto v = it.second;
            ans.push_back(v);
        }
        
        
        return ans;
    }
};