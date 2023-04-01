//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minOperations(int N) {
        // Code here
        long long int ans = 0, hmel;
        // for(int i = 0; i < N; i++)cout<<2 * i + 1<<" "; cout<<endl;
        if(N % 2 == 1)
        {
            hmel = (long long int)(N)/ 2;
            ans = (long long int)hmel * (hmel + 1);
            
        }
        else{
            hmel = N / 2;
            ans = (long long int) (hmel * (hmel + 1)) - hmel;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperations(n) << endl;
    }
    return 0;
}
// } Driver Code Ends