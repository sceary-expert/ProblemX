//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        //frequency of a[i] from i to n - 1
        vector<int>v(N, 0);
        map<int, int>mp;
        for(int i = N - 1; i >= 0; i--)
        {
            
            mp[A[i]]++;
            v[i] = mp[A[i]];
        }
        vector<int>ans;
        for(auto q: Q)
        {
            int l = q[0], r = q[1], k = q[2];
            int res = 0;
            for(int i = l; i <= r; i++)
            {
                if(v[i] == k)res++;
            }
            ans.push_back(res);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends