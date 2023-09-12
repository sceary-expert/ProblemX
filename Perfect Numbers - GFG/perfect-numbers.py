#User function Template for python3

class Solution:
    def isPerfectNumber(self, N):
        # code here 
        
        n = N
        tot = 0
        div = 2
        n = N ** 0.5
        while div <= n:
            
            if N % div == 0:
                tot += div
                div2 = N / div
                # print(div, div2)
                if div != div2:
                    tot += div2
                    
                
            div += 1
        # print("tot ", tot, )  
        if N != 1:
            tot += 1
        if tot == N:
            return 1
        return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        
        ob = Solution()
        print(ob.isPerfectNumber(N))
# } Driver Code Ends