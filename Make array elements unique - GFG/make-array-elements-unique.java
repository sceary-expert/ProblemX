//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while (t-- > 0) {

            
            int i = 0;
            int N = Integer.parseInt(br.readLine().trim());
        
            int arr[] = new int[(int)(N)];
            
            String inputLine2[] = br.readLine().trim().split(" ");
            for ( i = 0; i < N; i++) {
                arr[i] = Integer.parseInt(inputLine2[i]);
            }
        
            Solution ob = new Solution();
            System.out.println(ob.minIncrements(arr,N));
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
   long isPos( int []arr, int n)
    {
        long ans = 0;
        HashMap<Integer, Integer>map = new HashMap<>();
        for(int i = 0; i < n; i++)
        {
            int ex = 0;
            while(map.containsKey(arr[i] + ex))
            {
                // System.out.println("dfghj" + arr[i]);    
                ex++;
                ans++;
                // if(mid < 0)return false;
            }
            // System.out.println(arr[i]);
            map.put(arr[i] + ex, 1);
        }
        return ans;
        
        
    }
    public long minIncrements(int[] arr, int N) {
        Arrays.sort(arr);
        // long mx = Long.MAX_VALUE, mn = 0;
        long ans = isPos(arr, N);
        return ans;
        
        // while(mn <= mx)
        // {
        //     long mid = (mn + mx) / 2;
        //     if(isPos(mid, arr, N))
        //     {
        //         // if(mid == 0)System.out.println("mid " );
        //         ans = Math.min(ans, mid);
        //         mx = mid - 1;
        //     }
        //     else {
        //         mn = mid + 1;
        //     }
        // }
        // return ans;
    }
}