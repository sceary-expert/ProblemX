class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        priority_queue<int>pq;
        for(auto &n : nums)
        {
            pq.push(n);
        }
        int mx = pq.top(); pq.pop();
        int mx2 = pq.top(); pq.pop();
        int mx3 = pq.top(); pq.pop();
        while(pq.size() && mx2 + mx3 <= mx)
        {
            mx = mx2;
            mx2 = mx3;
            mx3 = pq.top(); pq.pop();
            
            
        }
        
        if(mx2 + mx3 <= mx)return 0;
        return mx + mx2 + mx3;
    }
};