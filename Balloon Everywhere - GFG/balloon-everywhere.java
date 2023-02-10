//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

// Position this line where user code will be pasted.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String s = br.readLine().trim();
            Solution ob = new Solution();
            int ans = ob.maxInstance(s);
            out.println(ans);
        }
        out.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int maxInstance(String s) {
        int []arr = new int[26];
        Arrays.fill(arr, 0);
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            char c = s.charAt(i);
            arr[c - 'a']++;
        }
        arr['o' - 'a'] /= 2;
        arr['l' - 'a'] /= 2;
        int mn = Integer.MAX_VALUE;
        mn = Math.min(mn, arr['b' - 'a']);
        mn = Math.min(mn, arr['a' - 'a']);
        mn = Math.min(mn, arr['l' - 'a']);
        mn = Math.min(mn, arr['o' - 'a']);
        mn = Math.min(mn, arr['n' - 'a']);
        return mn;
        
    }
}