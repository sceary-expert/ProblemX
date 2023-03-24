//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        int n = S.size();
        map<char, int>mp;
        
        bool swp = false;
        map<int, int>badIndx;
        int p1 = 0, p2 = n - 1;
        map<int, int>freq;
        for(auto &it : S)freq[it]++;
        while(p1 < p2)
        {
            if(!swp)
            {
                if(freq[S[p1]] > 1)
                {
                    freq[S[p1]]--;
                    swp = true;
                    badIndx[p1]++;
                }
                p1++;
                
            }
            else{
                if(freq[S[p2]] > 1)
                {
                    freq[S[p2]]--;
                    swp = false;
                    badIndx[p2]++;
                }
                p2--;
            }
            
        }
        
        string ans = "";
        if(swp)
        {
            for(int i = n - 1; i >= 0; i--)
            {
                if(badIndx[i])continue;
                ans += S[i];
            }
        }
        else{
            for(int i = 0; i < n; i++)
            {
                if(badIndx[i])continue;
                ans += S[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends