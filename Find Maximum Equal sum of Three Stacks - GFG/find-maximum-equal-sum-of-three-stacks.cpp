//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,
    vector<int> &S1,
    vector<int> &S2,
    vector<int> &S3){
        int sum1 = accumulate(S1.begin(), S1.end(), 0);
        int sum2 = accumulate(S2.begin(), S2.end(), 0);
        int sum3 = accumulate(S3.begin(), S3.end(), 0);
        
        int p1 = 0, p2 = 0, p3 = 0;
        
        while(sum1 != sum2 || sum2 != sum3)
        {
            while(sum1 > sum2 || sum1 > sum3)
            {
                sum1 -= S1[p1];
                p1++;
            }
            while(sum2 > sum1 || sum2 > sum3)
            {
                sum2 -= S2[p2];
                p2++;
            }
            while(sum3 > sum1 || sum3 > sum2)
            {
                sum3 -= S3[p3];
                p3++;
            }
            if(sum1 == 0 || sum2 == 0 || sum3 == 0)return 0;
        }
        return sum1;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends