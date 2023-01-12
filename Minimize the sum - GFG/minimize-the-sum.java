//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;


// } Driver Code Ends
//User function Template for Java

class Solution {
    long minimizeSum(int n, int arr[]) {
        // code here
        long prev = 0, ans = 0;
        PriorityQueue<Integer>pq = new PriorityQueue<Integer>();
        for(int i = 0; i < n; i++)
        {
            pq.add(arr[i]);
        }
        while(pq.size() > 1)
        {
            int top = pq.peek();
            pq.remove(top);
            int top2 = pq.peek();
            pq.remove(top2);
            pq.add(top + top2);
            // System.out.println(top + top2);
            prev += (top + top2);
            
        }
        return prev;
    }
}

//{ Driver Code Starts.

public class GFG
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        while (t-- > 0)
        {
            int n = sc.nextInt();
            int A[] = new int[n];
            
            for (int i = 0; i < n;i++)
            {
                A[i] = sc.nextInt();
            }
            Solution obj = new Solution();
            long ans = obj.minimizeSum(n, A);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends