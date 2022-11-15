class Solution {
public:
    bool isPalindrome(string s, int i, int j)
    {
        while(j >= i)
        {
            if(s[i] != s[j])return false;
            i++; j--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                int len = (j - i) + 1;
                if(len > k + 1)continue;
                if(len >= k && isPalindrome(s, i, j))
                {
                    ans++;
                    i = j;
                    break;
                }
            }
        }
        return ans;
    }
};