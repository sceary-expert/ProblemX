// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        int diff = 0;
        
        int l=0,r=n-1,lm=0,rm=n-1;
        
        while(l<n && r>=0 && l<r) {
            if(ht[l]<=ht[r]) {
                if(ht[l]>ht[lm]) {
                    lm = l;
                }
                
                else
                    diff+=(ht[lm]-ht[l]);
                l++;
            }
            
            else {
                if(ht[r]>ht[rm]) {
                    rm = r;
                    r--;
                }
                
                else {
                    diff+=(ht[rm]-ht[r]);
                    r--; 
                }
            }
        }
        
        return diff;
        
    }
};