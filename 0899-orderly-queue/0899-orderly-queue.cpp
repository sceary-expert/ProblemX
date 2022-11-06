class Solution {
public:
    string lexoSmall(string s)
    {
        // "string"
        string ans = s;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
        s += s[0];
        s.erase(s.begin());
        if(s < ans) ans = s;        
            
        }
        return ans;
    }
    string smallestLexo(string s)
    {
        string ans = "";
        map<char, int>mp;
        for(auto &c : s)mp[c]++;
        for(auto &it : mp)
        {
            int freq = it.second;
            char c = it.first;
            for(int i = 0; i < freq; i++)ans += c;

        }
        return ans;
    }
    
    string orderlyQueue(string s, int k) {
        if(k == 1)return lexoSmall(s);
        else return smallestLexo(s);
    }
};