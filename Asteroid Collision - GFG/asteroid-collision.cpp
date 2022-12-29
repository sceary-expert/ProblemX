//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // If negative then goes to left
        
        stack<int>st;
        
        for(auto &it : asteroids)
        {
            if(st.size() == 0 || it > 0 || st.top() < 0)
            {
                st.push(it);
                continue;
            }
            
            // stack is not empty and 
            // the left one is negative
            // it is negative
            
            //while the left one is positive and less than it destroy / pop top
            
            while(st.size() && st.top() > 0 && st.top() < (-1 * it))
            {
                st.pop();
            }
            
            // if stack size is 0 or left one is negative push it
            
            if(st.size() == 0 || st.top() < 0)
            {
                st.push(it);
                continue;
            }
            
            // if both same destroy or pop the top element
            
            if(st.top() == (-1 * it))
            {
                st.pop();
                continue;
            }
            
            // if left positive one is bigger then don't push it
            
            
        }
        vector<int>ans;
        while(st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends