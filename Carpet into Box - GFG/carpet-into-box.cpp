//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void foldMin(int &a, int &b)
    {
        if(a <= b)
        {
            a /= 2;
        }
        else b/= 2;
    }
    void foldMax(int &a, int &b)
    {
        if(a >= b)
        {
            a /= 2;
        }
        else b /= 2;
    }
    int carpetBox(int A, int B, int C, int D){
        //code here
        int cnt = 0;
        while(min(A, B) > min(C, D) || max(A, B) > max(C, D) )
        {
            if(max(A, B) > max(C, D))
            {
                foldMax(A, B);
                cnt++;
            }
            else if(min(A, B) > min(C, D))
            {
                foldMin(A, B);
                cnt++;
            }
            
            
        }
        return cnt;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends