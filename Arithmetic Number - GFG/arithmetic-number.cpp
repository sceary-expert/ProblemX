//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int a, int b, int c){
        if(b < a && c > 0)return 0;
        if(b > a && c < 0)return 0;
        if(c == 0 && a != b)return 0;
        b-= a;
        
        if(b== c || b % c == 0)return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends