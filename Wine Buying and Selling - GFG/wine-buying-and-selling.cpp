//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  #define d(x) cout<<#x<<" " <<x<<endl;
  #define ll long long int 
  long long int wineSelling(vector<int>& Arr, int N){
      ll ans = 0;
      
      int b = -1, s = -1;
      
      for(int i = 0; i < N; i++)
      {
          if(Arr[i] < 0 && b == -1)b = i;
          if(Arr[i] > 0 && s == -1)s = i;
      }
      
    //   d(b);
    //   d(s);
      
      while(b < N && s < N)
      {
          int mn = min(abs(Arr[b] ), Arr[s]);
        //   d(Arr[b]); d(Arr[s]);
        //   d(b); d(s);
          Arr[b] += mn;
          Arr[s] -= mn;
        //   d(Arr[b]); d(Arr[s]);
        //   d(mn);
          ans += (mn * abs(b - s) * 1L);
          
          while(b < N && Arr[b] >= 0)b++;
          while(s < N && Arr[s] <= 0)s++;
        //   d(b); d(s);
      }
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends