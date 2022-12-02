class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        //1. Length of both the string should be same
        int n1 = word1.size(), n2 = word2.size();
        if(n1 != n2)return false;
        
        //2. in sorted manner if they are same return true
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());
        if(word1 == word2)return true;
        
        //3. if occurances of all number matches return true
        vector<int>freq1, freq2;
        set<char>st1, st2;
        for(int i = 0; i < n1; i++)
        {
            st1.insert(word1[i]);
            if(i + 1 < n1 && word1[i + 1] == word1[i])
            {
                int sz = 1;
                while(i + 1 < n1 && word1[i + 1] == word1[i])
                {
                    sz++;
                    i++;
                }
                freq1.push_back(sz);
                i--;
            }
            else{
                freq1.push_back(1);
            }
        }
        for(int i = 0; i < n1; i++)
        {
            st2.insert(word2[i]);
            if(i + 1 < n1 && word2[i + 1] == word2[i])
            {
                int sz = 1;
                while(i + 1 < n1 && word2[i + 1] == word2[i])
                {
                    sz++;
                    i++;
                }
                freq2.push_back(sz);
                i--;
            }
            else freq2.push_back(1);
        }
        if(st1 != st2)return false;
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        n1 = freq1.size(), n2 = freq2.size();
        for(int i = 0; i < n1; i++)
        {
            if(freq1[i] != freq2[i])return false;
        }
        return true;
    }
};