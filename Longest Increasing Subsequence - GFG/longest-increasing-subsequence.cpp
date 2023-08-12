//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
      vector<int>v;
      for(int i = 0; i < n; i++)
      {
          int a = arr[i];
          auto it = std::lower_bound(v.begin(), v.end(), a);
          if(it == v.end())v.push_back(a);
          else
          {
              int ind = it - v.begin();
              v[ind] = a;
          }
          
      }
      return v.size();
    // return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends