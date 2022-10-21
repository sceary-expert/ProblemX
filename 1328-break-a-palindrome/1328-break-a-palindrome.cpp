class Solution {
public:
    string breakPalindrome(string p) {
        string ans = "";
        int n = p.size(), k = n / 2;
        bool odd = n % 2;
        for(int i = 0; i < n; i++)
        {
            if(i == k && odd)continue;
            char c = p[i];
            if(c != 'a')
            {
                p[i] = 'a';
                    return p;
            }
                
        }
        
        if(n > 1)
        {
            char c = p[n - 1];//'z'
            int ind = c - 'a';//'25'
            p[n - 1] = 'a' + (ind + 1) % 26;
            return p;
                
        }
        return ans;
        
    }
};