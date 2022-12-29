//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        map<int, int>mp;
        for(auto it : nums)
        {
            int mod = it % k;
            if(mod == 0 && mp[0])
            {
                mp[0]--;
            }
            else if(mp[k - mod])
            {
                mp[k - mod]--;
                
            }
            else mp[mod]++;//0, 0
        }
        for(auto it : mp)
        {
            if(it.second > 0)return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends