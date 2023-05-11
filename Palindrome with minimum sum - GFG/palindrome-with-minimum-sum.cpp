//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPalindrome(string &s)
    {
        int p1 = 0, p2 = s.size() - 1;
        while(p1 < p2)
        {
            if(s[p1] == s[p2])
            {
                p1++;
                p2--;
                continue;
            }
            if(s[p1] == '?' || s[p2] == '?')
            {
                if(s[p1] == '?')s[p1] = s[p2];
                else s[p2] = s[p1];
                p1++;
                p2--;
                
            }
            else return false;
        }
        return true;
    }
    int minimumSum(string s) {
        // code here
        if(isPalindrome(s) == false)
        {
            return -1;
        }
        // cout<<s<<endl;
        char prev = 'A';
        int ans = 0;
        for(auto it : s)
        {
            if(it < 'a' || it > 'z')continue;
            if(prev != 'A')
            {
                ans += abs(prev - it);
            }
            prev = it;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends