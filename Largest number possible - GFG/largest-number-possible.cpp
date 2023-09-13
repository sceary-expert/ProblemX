//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // if(S == 0)return "-1";
        string s = "";
        while(N)
        {
            int mn = min(S, 9);
            N--;
            S -= mn;
            s += to_string(mn);
        }
        if(S > 0 || (s.size() > 1 && s[0] == '0'))return "-1";
        return s;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends