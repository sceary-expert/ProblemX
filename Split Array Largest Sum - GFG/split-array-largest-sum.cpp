//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  #define d(x) cout<<#x<<" " <<x<<endl;
    //   priority_queue<int>mxh;
    //     priority_queue<int, vector<int>, greater<int>>mnh;
    // multiset<int>pq;
  bool isPosMid(int mid, int arr[], int  k, int n)
  {
      //is it possible to obtain max sum less than or equal to mid
      int p = 0;
      for(int o = 0; o < k; o++)
      {
          int sum = 0;
          while(sum <= mid)
          {
              if(p >= n)return true;
            sum += arr[p];
            p++;
          }
          p--;
      }
      if(p < n)return false;
      return true;
      
  }
      
    int splitArray(int arr[] ,int n, int K) {
        int sum = 0, mn = 0;
    
        for(int i = 0; i < n; i++)
        {
            int it = arr[i];
            // pq.insert(it);
            sum += it;
            mn = max(mn, it);
        }
        
        int mx = sum;
        // d(mx); d(mn);
        int ans = INT_MAX;
        while(mn <= mx)
        {
            int mid = (mn + mx) / 2;
            if(isPosMid(mid, arr, K, n))
            {
                ans = min(ans, mid);
                mx = mid - 1;
            }
            else mn = mid + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends