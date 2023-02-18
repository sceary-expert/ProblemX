//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  #define ll long long
  vector<ll>v;
    long long solve(int N, int K, vector<long long> GeekNum) {
        v.resize(N + 1, -1);
        for(int i = 0; i < K; i++)
        {
            v[i] = GeekNum[i];
        }
        
        for(int i = K; i <= N; i++)
        {
            ll sum = 0;
            for(int j = 1; j <= K; j++)
            {
                sum += v[i - j];
            }
            v[i] = sum;
        }
        return v[N - 1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends