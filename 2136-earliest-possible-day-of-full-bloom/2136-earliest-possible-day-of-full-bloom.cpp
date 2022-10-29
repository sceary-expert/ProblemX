class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int pt = 0;
        int ans = 0;
        int n = plantTime.size();
        priority_queue<pair<int, int>>pq;
        for(int i = 0; i < n; i++)
        {
            pq.push({growTime[i], plantTime[i]});
        }
        //for(auto &ptm : plantTime)
        //for(int i = 0; i < plantTime.size(); i++)
        while(pq.size())
        {
            
            int ptm = pq.top().second;//plantTime[i];
            pt += ptm;
            int curr = pt + pq.top().first;//growTime[i];
            if(curr > ans)ans = curr;       
            pq.pop();
        }
        return ans;
        
    }
};