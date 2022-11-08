class Solution {
    public:
    bool isUpper(char c)
    {
        if(c >= 'A' && c <= 'Z')return true;
        else return false;
    }
    bool areSame(char c1, char c2)
    {
        bool u1 = isUpper(c1);
        bool u2 = isUpper(c2);
        int ind1, ind2;
        
        if(u1 == true)ind1 = c1 - 'A';
        else ind1 = c1 - 'a';
        if(u2 == true)ind2 = c2 - 'A';
        else ind2 = c2 - 'a';
        
        if(ind1 == ind2 && u1 != u2)return true;
        return false;
    }
    string makeGood(string s) {
        stack<char>st;
        st.push('$');
        for(auto &c : s)
        {
            //cout<<c<<" "<<st.top()<<endl;
            if(areSame(c, st.top()))
            {
                //cout<<"true"<<endl;
                st.pop();
            }
            else st.push(c);
        }
        
        string ans = "";
        while(st.size() > 1)
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }


    
};