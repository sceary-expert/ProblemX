class Solution {
public:
    string removeDuplicates(string str) {
        stack<char>st;
        st.push('$');
        for(auto &c : str)
        {
            if(c == st.top())while(st.top() == c)st.pop();
            else st.push(c);
        }
        string s = "";
        while(st.size() > 1)
        {
            s = st.top() + s;
            st.pop();
        }
        return s;
        
        
    }
};