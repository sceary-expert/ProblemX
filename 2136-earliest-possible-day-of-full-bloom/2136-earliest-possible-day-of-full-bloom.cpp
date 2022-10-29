class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        vector<pair<int, int>> seed(n);
        int maxDay = 0;
        
        for(int i = 0; i<n; i++){
            seed[i] = {growTime[i],plantTime[i]};
        }
        
        sort(seed.begin(), seed.end());
        int sum = 0;
        
        for(int i = n - 1; i>= 0; i--){
            sum += seed[i].second;
            maxDay = max(maxDay, sum + seed[i].first);
        }
        
        return maxDay;
    }
    
    // bool static cmp(pair<int, int> p1, pair<int, int> p2){
    //     return p1.second>=p2.second;
    // }
};