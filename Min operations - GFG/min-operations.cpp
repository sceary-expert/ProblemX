//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool is_pow_of_two(int k)
  {
      int cnt = __builtin_popcount(k);
      return cnt == 1;
  }
  bool check(int big, int small)
  {
      if(big == 0 || small == 0)return true;
      //   if(big % small == 0 && is_pow_of_two(big / small))return true;
      bool flag = true;
      for(int i = 0; i < 32; i++)
      {
          //if the it's bit of small is set but not for big then turn flag = false, break;
          if((small & (1<<i)) != 0 && (big & (1 << i)) == 0)
          {
              flag = false;
              break;
          }
      }
    
      return flag;
  }
    int solve(int a, int b) {
        // code here
        if(a  == b)return 0;
        bool flag = false;
        if(a > b)
        {
            flag = check(a, b);
        }
        else flag = check(b, a);
        if(flag == false)return 2;
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends