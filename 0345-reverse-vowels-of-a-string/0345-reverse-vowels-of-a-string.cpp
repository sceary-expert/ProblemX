class Solution {
public:
    bool isVowel(char c)
    {
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return true;
        return false;
    }
    string reverseVowels(string s) {
        stack<char>st;
        for(auto &c : s)
        {
            if(isVowel(c))st.push(c);
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(isVowel(s[i])){s[i] = st.top(); st.pop();}
        }
        return s;
    }
};