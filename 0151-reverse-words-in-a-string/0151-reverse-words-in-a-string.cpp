class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int n = s.size();
        string temp = "";
        for(int i = 0; i <= n; i++)
        {
            if(s[i] == ' ' || i == n)
            {
               if(temp != "") st.push(temp);
                temp = "";
            }
            else temp += s[i];
        }
        string ans = "";
        while(st.size())
        {
           // cout<<"--"<<st.top()<<"--"<<endl;
           
                ans += st.top();
                if(st.size() > 1)ans += " ";
                
           
            
            st.pop();
        }
        return ans;
    }
};