//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        vector<int>LeftPart;
        for(int i = 0; i < (n / 2); i++)
        {
            int a = arr[i];
            LeftPart.push_back(a);
        }
        sort(LeftPart.begin(), LeftPart.end());
        int answer = 0;
        for(int i = (n / 2); i < n; i++)
        {
            int a = arr[i];
            int Atleast = a * 5;
            auto itr = lower_bound(LeftPart.begin(), LeftPart.end(), Atleast);
            answer += (LeftPart.end() - itr);
            // if(itr == LeftPart.end())continue;
            // ans += itr - LeftPart.begin();
        }
        return answer;
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
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends