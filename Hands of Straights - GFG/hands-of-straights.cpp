//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, 
    int groupSize, vector<int> &hand){
        map<int, int>mp;
        sort(hand.begin(), hand.end());
        for(auto &it : hand)
        {
            mp[it]++;
        }
        vector<bool>vis(N, false);
        for(int i = 0; i < N; i++)
        {
            int currentHand = hand[i];
            if(vis[i] == false)
            {
                
                int fr = mp[currentHand];
                if(fr == 0)continue;
                for(int j = 0; j < groupSize; j++)
                {
                    mp[currentHand + j] -= fr;
                    if(mp[currentHand + j] < 0)return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends