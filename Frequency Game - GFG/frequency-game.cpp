//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        sort(arr, arr + n);
        map<int, int>hashMap;
        for(int i = 0; i < n; i++)
        {
            hashMap[arr[i]]++;
        }
        int minFreq = INT_MAX;
        for(auto &itr : hashMap)
        {
            int freq = itr.second;
            if(freq < minFreq)minFreq = freq;
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(hashMap[arr[i]] == minFreq)return arr[i];
        }
        return -1;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends