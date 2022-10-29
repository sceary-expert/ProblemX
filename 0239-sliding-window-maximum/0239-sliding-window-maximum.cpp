class Solution {
public:
    #define pii pair<int, int>
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pii>pq;
        int p = 0;
        
        for(; p < k - 1; p++)
        {
            //cout<<p<<endl;
            pq.push({nums[p], p});
        }
        //cout<<p<<endl;
        vector<int>ans;
        int n = nums.size();
        while(p < n)
        {
            //cout<<p<<endl;
            //cout<<"INITIAL TOP : "<<pq.top().first<<" INDEX : "<<pq.top().second<<endl;
            while(pq.size() && pq.top().second <= p - k)// p = 3
            {
                pq.pop();
            }
            pq.push({nums[p], p});
            int currTop = pq.top().first;
            //cout<<p<< " CURRTOP : "<<currTop<<endl;
            ans.push_back(currTop);
            p++;
            
        }
        
        
        return ans;
        
    }
};