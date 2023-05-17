//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int mx_x = 0, mn_x = 0;
        int mx_y = 0, mn_y = 0;
        map<char, vector<int>>mp;
        mp['L'] = {0, -1};
        mp['R'] = {0,  1};
        mp['D'] = {-1, 0};
        mp['U'] = {1,  0};
        int x = 0, y = 0;
        for(auto it : s)
        {
            auto v = mp[it];
            x += v[0];
            y += v[1];
            mn_x = min(mn_x, x);
            mn_y = min(mn_y, y);
            mx_y = max(mx_y, y);
            mx_x = max(mx_x, x);
        }
        int dx = abs(mn_x - mx_x);
        int dy = abs(mn_y - mx_y);
        // cout<<dx<<" "<<dy<<endl;
        return dx < n && dy < m;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends