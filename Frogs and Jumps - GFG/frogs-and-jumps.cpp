//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int l, int frogs[]) {
        // Code here
        sort(frogs, frogs + N);
        vector<bool>v(l + 1, false);
        int ans = 0;
        for(int i = 0; i < N; i++)
        {
            int f = frogs[i];
            int k = f;
            if(f == 1)
            {
                return 0;
            }
            if(v[f] == true)continue;
            while(f <= l)
            {
                v[f] = true;
                f += k;
            }
        }
        // int ans = 0;
        for(int i = 1; i <= l; i++)
        {
            if(v[i] == false)ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends