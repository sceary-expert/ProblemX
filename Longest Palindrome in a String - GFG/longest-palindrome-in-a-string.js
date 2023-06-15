//{ Driver Code Starts
//Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((string) => {
      return string.trim();
    });

  main();
});

function readLine() {
  return inputString[currentLine++];
}


function main() {
  let t = parseInt(readLine());
  let i = 0;
 
  for (; i < t; i++) {
    let S = readLine().trim();    
    let obj = new Solution();
    let res = obj.longestPalin(S);
    console.log(res);
  }

}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {string} S
 * @return {string} 
*/

class Solution {
  longestPalin(S){
    var s = "";
    s += S[0];
    var maxLen = 1;
    var n = S.length;
    // console.log(n);
    for(let i = 0; i < n; i++)
    {
        //odd length
        // console.log(i);
        var curr = "";
        var len = 1;
        for(let j = 1; j < n; j++)
        {
            let l = i - j, r = i + j;
            if(l < 0 || r >= n || S[l] != S[r])
            {
                for(let p = l + 1; p < r; p++)
                {
                    curr += S[p];
                }
                if(len > maxLen)
                {
                    maxLen = len;
                    s = curr;
                }
                break;
            }
            len += 2;
        }
        curr = "";
        len = 0;
        for(let j = 1; j < n; j++)
        {
            let l = i - j + 1, r = i + j;
            if(l < 0 || r >= n || S[l] != S[r])
            {
                for(let p = l + 1; p < r; p++)curr += S[p];
                if(len > maxLen)
                {
                    maxLen = len;
                    s = curr;
                }
                break;
            }
            len += 2;
        }

    }
    return s;
  }
}