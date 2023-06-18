//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        int s = 1, e = N;
        while(s < e)
        {
            s += K;
            // cout<<s<<" "<<e<<endl;
            if(s >= e)
            {
                return e ;
            }
            e -= K;
            // cout<<s<<" "<<e<<endl;
            if(e <= s)
            {
                return s;
            }
        }
        return 1;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends