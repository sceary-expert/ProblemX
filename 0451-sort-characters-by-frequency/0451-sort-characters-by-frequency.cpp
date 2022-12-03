class Solution {
public:
    string frequencySort(string s) {
        // vector<int>freq(256);
        // for(auto c : s)freq[c]++;
        // sort(s.begin(), s.end(), [&](char a, char b){
        //     if(freq[a] == freq[b])return a < b;
        //     else return freq[a] > freq[b];
        // });
        // return s;
        vector<int> count(256);
        for(auto c : s)
            count[c]++;
        sort(s.begin(), s.end(), [&](char a, char b)
             {
                 if(count[a] == count[b])
                     return a < b;
                 return count[a] > count[b];
             });
        return s;
        
    }
};