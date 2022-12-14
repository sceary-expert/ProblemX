//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        //1 ----> -1
        
        vector<int>v;
        int mx = INT_MIN, currMax = 0, start = 0, l = -1, r = -1;
        for(int i = 0; i < n; i++)
        {
            char c = str[i];
            if(c == '1')
            {
                currMax -= 1;
                if(currMax < 0)
                {
                    start = i + 1;
                    currMax = 0;
                }
                
                
            }
            else{
                currMax += 1;
                if(currMax > mx)
                {
                    mx = currMax;
                    l = start;
                    r = i;
                }
            }
        }
        
        if(l == -1 && r == -1)return {-1};
        else return {l + 1, r + 1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends