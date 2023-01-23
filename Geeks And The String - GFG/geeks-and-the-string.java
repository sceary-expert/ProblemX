//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            String s; 
            s = br.readLine();
            
            Solution obj = new Solution();
            String res = obj.removePair(s);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static String removePair(String s) {
        Stack<Character>stack = new Stack<>();
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            char c = s.charAt(i);
            if(stack.size() == 0)
            {
                stack.push(c);
                continue;
            }
            if(c == stack.peek())stack.pop();
            else stack.push(c);
        }
        String ans = "";
        if(stack.isEmpty() == true)return "-1";
        while(stack.isEmpty() == false)
        {
            ans += stack.peek();
            stack.pop();
        }
        // System.out.println("--" + ans + "--");
        String reverse = new StringBuilder(ans).reverse().toString();
        return reverse;
    }
}
        
