//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    #define ll long long 
    
    
    ll N, n;
    vector<bool>sieve;
    vector<int>primeTillNow;
    void calculatePrime()
    {
        //creating sieve
        sieve.resize(N + 5, true);
        primeTillNow.resize(N + 5, 0);
        
        for(ll i = 2; i * i <= N; i++)
        {
            if(sieve[i] == false)continue;
            primeTillNow[i * i]++;
            for(ll mul = 2; mul * i <= N; mul++)
            {
                sieve[i * mul] = false;
            }
        }
        
        int sum = 0;
        for(auto &it : primeTillNow)
        {
            sum += it;
            it = sum;
        }
        
        
    }
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        N = 0;
        for(auto it : query)
        N = max(it, N);
        
        //n = 1L * sqrt(N);
        calculatePrime();
        
        vector<int>ans;
        
        for(auto it : query)
        {
            ans.push_back(primeTillNow[it]);
        }
        
        
        return ans;
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends