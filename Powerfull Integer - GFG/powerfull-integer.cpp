//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        // Code here
        int mx = 0;
        for(auto interval : intervals)
        {
            if(interval[1] > mx)mx = interval[1];
            
        }
        vector<int>frequency(mx + 5, 0);
        for(auto &interval : intervals)
        {
            int start = interval[0], end = interval[1];
            frequency[start]++;
            frequency[end + 1]--;
        }
        int sum = 0, answer = -1;
        for(int i = 0; i <= mx; i++)
        {
            sum += frequency[i];
            if(sum >= k )answer = max(answer, i);
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends