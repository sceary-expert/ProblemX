//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<int>s1, s2;
        int p1 = 0, p2 = 0;
        while(p1 < N)
        {
            if(s1.size() && s1.top() == color[p1] && s2.top() == radius[p1])
            {
                s1.pop();
                s2.pop();
            }
            else 
            {
                s1.push(color[p1]);
                s2.push(radius[p1]);
            }
            p1++; p2++;
        }
        return s1.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends