//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        long long int mx = LLONG_MAX, mn = 0, ans = mx;
        sort(arr.begin(), arr.end());
        map<int, int>mp;
        long long int res = 0;
        for(auto &it : arr)
        {
            while(mp[it])it++, res++;
            mp[it]++;
        }
        return res;
        // while(mn <= mx)
        // {
        //     long long int mid = (mx + mn) / 2;
            
            
        // }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends