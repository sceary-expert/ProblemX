//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool canImakeMidSpaces(vector<int>&stalls, int mid, int n, int k)
    {
        //cout<<"Can I make Mid : "<<mid<<endl;
        int p = stalls[0];
        for(int i = 1; i < n; i++)
        {
            int d = stalls[i] - p;
            if(d >= mid)
            {
                p = stalls[i];
                k--;
            }
        }
        return k <= 1;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(), stalls.end());
        int mx = stalls[n - 1] - stalls[0], mn = 0;
        int ans = 0;
        //cout<<mn<<" "<<mx<<endl;
        while(mn <= mx)
        {
            int mid = mn + (mx - mn) / 2;
            //cout<<"Mid : "<<mid<<endl;
            if(canImakeMidSpaces(stalls, mid, n, k)){
                // cout<<"Mid is Poss : ";
                // cout<<mid<<endl;
             ans = mid;
             mn = mid + 1;
            }
            else mx = mid - 1;
        }
        return ans;
        
        
    }
};




//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends