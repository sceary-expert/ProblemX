class Solution {
public:
    vector<int>par;
    void DSU(int n)
    {
        par.resize(n);
        for(int i = 0; i < n; i++)
        {
            par[i] = i;
        }
    }
    void mergeSet(int i, int j)
    {
      par[i] = j;  
    }
    int findParent(int i)
    {
        if(par[i] == i)return i;
        return par[i] = findParent(par[i]);
    }
    bool canJoint(int i, int j)
    {
        int parent_of_i = findParent(i);
        int parent_of_j = findParent(j);
        if(parent_of_i == parent_of_j)return false;
        mergeSet(parent_of_i, parent_of_j);
        return true;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), ans = 0;
        DSU(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    if(canJoint(i, j))ans++;
                }
            }
        }
        return ans;
    }
};