//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
    bool isHappy(int N, map<int, bool>&vis)
    {
        while(vis[N] == false)
        {
            vis[N] = true;
            int sum = 0;
            while(N)
            {
                int m = N % 10;
                sum += (m * m);
                N /= 10;
            }
            N = sum;
            if(sum == 1)return true;
        }
        return false;
    }
    int nextHappy(int N){
        map<int, bool>vis;
        while(isHappy(N + 1, vis) == false)
        {
            N++;
        }
        return N + 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends