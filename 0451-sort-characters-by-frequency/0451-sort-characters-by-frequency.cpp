class Solution {
public:
    string frequencySort(string s) {
        vector<int>freq(256);
        for(auto c : s)freq[c]++;
        sort(s.begin(), s.end(), [&](char a, char b){
            if(freq[a] == freq[b])return a < b;
            else return freq[a] > freq[b];
        });
        return s;
        
    }
};