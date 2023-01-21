//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int b1 = __builtin_popcount(b), ans = 0;
        if(b1 == 0)return ans;
        for(int i = 31; i >= 0; i--)
        {
            
            if((a & (1<<i)) != 0)
            {
                b1--;
                ans |= (1<<i);
                if(b1 == 0)return ans;
            }
        }
        for(int i = 0; i < 32; i++)
        {
            if(b1 && (ans & (1 << i)) == 0)
            {
                ans |= (1 << i);
                b1--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends