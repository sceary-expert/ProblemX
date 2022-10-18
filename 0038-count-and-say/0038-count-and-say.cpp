class Solution {
public:
        string convert(string prev)
        {
                string ans = "";                
                int f = 0, p = 0, n = prev.size();
                while(p < n)
                {
                        char c = prev[p];//2
                        f = 0;
                        while(p < n && prev[p] == c)
                        {
                                f++; p++;
                        }
                        ans += to_string(f);ans += c;                       
                }
                return ans;                               
        }
    string countAndSay(int n) {
        if(n == 1)return "1";
            string prev = countAndSay(n - 1);            
            string ans = convert(prev);            
            return ans;
    }
};