//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int b5 = 0, b10 = 0, b20 = 0;
        for(auto &bill : bills)
        {
           if(bill == 5)
           {
               b5++;
           }
           else if(bill == 10)
           {
               if(b5 == 0)return false;
               b5--;
               b10++;
           }
           else{
               if(b5 == 0)return false;
               if(b10 != 0)
               {
                   b10--;
                   b5--;
                   b20++;
               }
               else{
                   if(b5 < 3)return false;
                   b5 -= 3;
                   b20++;
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
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends