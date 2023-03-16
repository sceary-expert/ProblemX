//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
         vector<int>v(D, 0);
         int s = S;
         if(D * 9 < S)return "-1";
        // for(int i = 0; i < D; i++)
        // {
        //     if(s <= 0)break;
        //     v[i]++;
        //     s--;
            
        // }
        v[0]++;
        s--;
        for(int i = D - 1; i >= 0; i--)
        {
            int diff = 9 - v[i];
            int mn = min(diff, s);
            v[i] += mn;
            s -= mn;
            if(s <= 0)break;
        }
        // int p1 = D - 1, p2 = -1;
        bool f = false;
        // for(int i = 0; i < D; i++)
        // {
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        for(int i = D - 1; i > 0; i-- )
        {
            
            if(v[i] != v[i -1] )
            {
                v[i]--;
                v[i - 1]++;
                f = true;
                break;
            }
            
            
        }
        // for(int i = 0; i < D; i++)
        // {
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        
        if(!f)return "-1";
        string ans = "";
        for(auto &it : v)
        {
            ans += (it + '0');
        }
        return ans;
/*
Your Code's output is: 
269
It's Correct output is: 
188
        */
         
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends