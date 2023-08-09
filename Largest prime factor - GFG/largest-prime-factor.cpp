//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
#define ll long long int
ll ans;
    // vector<ll>primes;
    vector<ll>divisors;
    void get_all_divisor_of(int n)
    {
        for(int i = 2; i <= n; i++)
        {
            ans = i;
            while(n % i == 0)
            {
                n /= i;
            }
        }
    }
    
    void GetPrimeTill(ll n)
    {
        vector<bool>isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i * i <= n; i++)
        {
            if(isPrime[i] == false)continue;
            if(n % i == 0)ans = i;
            for(int m = 2; i * m <= n; m++ )
            {
                isPrime[i * m] = false;
            }
            
        }
        
    }
    long long int largestPrimeFactor(int N){
        // find all primes 
        // find the maximum prime that is divisible
        ans = 0;
        // GetPrimeTill(N);
        get_all_divisor_of(N);
        
        return ans;
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
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends