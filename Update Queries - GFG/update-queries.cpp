//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            vector<vector<int>>add(N + 1, vector<int>());
            vector<vector<int>>sub(N + 1, vector<int>());
            vector<int>ans(N);
            // return ans;
            for(auto &q : U)
            {
                int l = q[0], r = q[1], x = q[2];
                
                add[l - 1].push_back(x);
                sub[r].push_back(x);
            }
            // return ans;
            int bit = 0;
            // set<int>st;
            map<int, int>mp;
            
            for(int i = 0; i < N; i++)
            {
                if(add[i].size())
                {
                    for(auto &it : add[i])
                    {
                        // st.insert(it);
                        mp[it]++;
                        bit |= it;
                    }
                }
                if(sub[i].size())
                {
                    for(auto &it : sub[i])
                    {
                        // st.erase(it);
                        mp[it]--;
                    }
                    bit = 0;
                    for(auto &it : mp)
                    {
                        if(it.second > 0)bit |= it.first;
                    }
                }
                ans[i] = bit;
            }
            
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends