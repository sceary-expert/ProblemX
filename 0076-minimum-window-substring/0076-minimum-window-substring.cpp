class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int p1 = 0, p2 = 0;
        map<char, int>mapForT;
        map<char, int>mapForS;
        for(auto &c : t)mapForT[c]++;
        string ans = "";
        int l = 0, r = -1;
        int mx = n + 1, score = 0;
        while(p2 < n)
        {
            char c = s[p2];
            mapForS[c]++;
            if(mapForS[c] <= mapForT[c])score++;
            
            while(score == m)
            {
                if(p2 - p1 < mx)    
                {
                    mx = p2 - p1;
                    l  = p1, r = p2;
                }
                
                char c1 = s[p1];
                mapForS[c1]--;
                if(mapForS[c1] < mapForT[c1])score--;
                    p1++;
            }
            
            p2++;
        }
        for(int i = l; i <= r; i++)
        {
            ans += s[i];
        }
        return ans;
    }
};