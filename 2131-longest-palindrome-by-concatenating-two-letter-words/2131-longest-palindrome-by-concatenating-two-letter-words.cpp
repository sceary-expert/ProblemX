class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int>mp;
        bool mid = false;
        int ans = 0;
        for(auto &c : words)
        {
            mp[c]++;
        }
        for(auto it : mp)
        {
            int freq = it.second;
            string s = it.first;
            
            if(s[0] == s[1])
            {
                //s is a palindrome
                if(freq % 2)
                {
                    mid = true;
                    ans += freq - 1;
                }
                else ans += freq;
            }
            else if(s[0] < s[1]){ 
                int freq2 = mp[{s[1], s[0]}];
                ans += 2 * min(freq, freq2);
            }
            
        }
        if(mid)ans += 1;
        return 2 * ans;
    }
    
};