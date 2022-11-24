class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans = 0;
        int n = roads.size();
        vector<int>endeg(n + 1, 0), people(n + 1, 1);
        people[0] = 0;
        vector<vector<int>>graph(n + 1);
        for(auto &it : roads)
        {
            int s = it[0];
            int e = it[1];
            graph[s].push_back(e);
            graph[e].push_back(s);
            endeg[s]++;
            endeg[e]++;
        }
        queue<int>q;
        for(int i = 1; i <= n; i++)
        {
            if(endeg[i] == 1)q.push(i);
        }
        while(q.size())
        {
            int sz = q.size();
            for(int o = 0; o < sz; o++)
            {
                auto city = q.front();
            q.pop();
            if(city == 0)break;
            ans += people[city] / seats;
            endeg[city] = 0;
            if(people[city] % seats != 0)ans++;
            for(auto &neighbour : graph[city])
            {
                endeg[neighbour]--;
                people[neighbour] += people[city]; 
                if(endeg[neighbour] == 1)q.push(neighbour);
            }    
            }
            
        }
        return ans;
    }
};