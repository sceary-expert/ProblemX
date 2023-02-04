//{ Driver Code Starts
//Initial Template for Java



import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            int n = Integer.parseInt(br.readLine().trim());
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().findMaxSum(arr, n);
            out.println(ans);
        }
        out.close();
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    int findMaxSum(int arr[], int n) {
        int []DP = new int[n];
        for(int i = 0; i < n; i++)
        {
            int j = i - 2, k = i - 3;
            DP[i] = arr[i];
            int max = 0;
            if(j >= 0 && max < DP[j])max = DP[j];
            if(k >= 0 && max < DP[k])max = DP[k];
            DP[i] += max;
            
        }
        int ans = DP[n - 1];
        if(n - 2 >= 0 && DP[n - 2] > ans)ans = DP[n - 2];
        return ans;
    }
}