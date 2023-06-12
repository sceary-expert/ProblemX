//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  vector<int>cache;
    int FindMaxValue(int price[], int n)
    {
        if(cache[n] != -1)return cache[n];
        int MaxValue = 0;
        for(int left = 1; left <= n; left++)
        {
            int CurrValue = price[left - 1] + FindMaxValue(price, n - left);
            MaxValue = max(MaxValue, CurrValue);
        }
        return cache[n] = MaxValue;
    }
    int cutRod(int price[], int n) {
        cache.resize(n + 1, -1);
        cache[0] = 0;
        return FindMaxValue(price, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends