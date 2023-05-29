//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, 
    vector<string> Dictionary, 
    string pattern) {
        vector<string>answer;
        int p = 0, n = pattern.size();
        for(auto &str : Dictionary)
        {
            p = 0;
            string s = "";
            for(auto &c : str)
            {
                if(c >= 'A' && c <= 'Z')
                {
                    if(pattern[p] == c)
                    {
                        p++;
                        s += c;
                        if(s.size() == n)break; 
                    }
                    else break;
                }
                
            }
            if(s.size() == n)
            {
               answer.push_back(str); 
            }
        }
        if(answer.size() != 0)return answer;
        return {"-1"};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends