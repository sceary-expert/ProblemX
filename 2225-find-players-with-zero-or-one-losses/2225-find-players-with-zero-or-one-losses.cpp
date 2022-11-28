class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans(2);
        map<int, int>mp;
        set<int>players;
        for(auto &it : matches)
        {
            
            int winner = it[0], looser = it[1];
            players.insert(winner);
            players.insert(looser);
            mp[looser]--;
        }
        for(auto &player : players)
        {
            int score = mp[player];
            //int player = it.first, score = it.second;
            if(score == 0)ans[0].push_back(player);
            else if(score == -1)ans[1].push_back(player);            
        }
        return ans;
    }
};