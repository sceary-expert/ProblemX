//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  #define ll long long
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        priority_queue<ll>aodd, aeven, bodd, beven;
        ll  asum = 0, bsum = 0;
        for(auto &a : A)
        {
            asum += a;
            if(a % 2)
            {
                aodd.push(a);
            }
            else aeven.push(a);
        }
        for(auto &b : B)
        {
            bsum += b;
            if(b % 2)
            {
                bodd.push(b);
            }
            else beven.push(b);
        }
        if(asum != bsum)return -1;
        // cout<<aeven.size() <<" "<<aodd.size()<<endl;
        // cout<<beven.size() <<" "<<bodd.size()<<endl;
        if(aodd.size() != bodd.size() || aeven.size() != beven.size())
        return -1;
        ll answer = 0;
        while(aodd.size())
        {
            ll a = aodd.top(), b = bodd.top();
            aodd.pop(); bodd.pop();
            answer += abs(a - b);
            // cout<<a<<" "<<b<<endl;
        }
        // cout<<"--"<<endl;
        while(aeven.size())
        {
            ll a = aeven.top(), b = beven.top();
            aeven.pop(); beven.pop();
            
            answer += abs(a - b);
            // cout<<a<<" "<<b<<endl;
        }
        // cout<<answer<<endl;
        if(answer % 4)return -1;
        return answer / 4;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends