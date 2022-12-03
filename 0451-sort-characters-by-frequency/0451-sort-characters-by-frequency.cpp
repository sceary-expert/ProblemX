class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, int>>pq;
        map<char, int>mp;
        for(auto &c : s)mp[c]++;
        for(auto &it : mp)
        {
            char c = it.first;
            int f = it.second;
            for(int o = 0; o < f; o++)pq.push({f, c});
        }
        string ans = "";
        while(pq.size())
        {
            ans += pq.top().second;
            pq.pop();
        }
        return ans;
    }
};