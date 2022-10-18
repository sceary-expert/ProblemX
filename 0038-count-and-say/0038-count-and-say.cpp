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
                        //if(prev == "21")cout<<"c : "<<c<<endl;
                        while(p < n && prev[p] == c)
                        {
                                f++;
                                p++;
                        }
                        ans += to_string(f);
                        ans += c;
                        //if(prev == "21")cout<<"f : "<<f<<endl;
                }
                return ans;               
                
        }
    string countAndSay(int n) {
        if(n == 1)return "1";
            string prev = countAndSay(n - 1);
            //cout<<"prev : "<<prev<<endl;
            string ans = convert(prev);
            //cout<<"ans : "<<ans<<endl;
            return ans;
    }
};