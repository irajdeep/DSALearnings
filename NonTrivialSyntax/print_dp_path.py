# lc 931
class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        R = len(A)
        if R == 0:
            return 0
        C = len(A[0])
        
        DP = {}
        path = {}
        s = ()
        
        def dp(r, c):
            if r == R:
                return 0
            
            if (r, c) in DP:
                return DP[(r, c)]
            
            o0, o1, o2 = sys.maxsize, sys.maxsize, sys.maxsize
            
            o0 = dp(r + 1, c)
            
            if c + 1 < C:
                o1 = dp(r + 1, c + 1)
            if c - 1 >= 0:
                o2 = dp(r + 1, c - 1)
            
            mini = min(o0, o1, o2)
            DP[(r, c)] = A[r][c] + mini
            
            if o0 == mini:
                n = (r + 1, c)
            elif o1 == mini:
                n = (r + 1, c + 1)
            else:
                n = (r + 1, c - 1)
            
            path[(r, c)] = n
            
            return DP[(r, c)]
        
        ans = sys.maxsize
        
        for c in range(C):
            if dp(0, c) < ans:
                ans = dp(0, c)
                s = (0, c)
        
        
        while True:
            if s[0] >= R:
                break
            print(A[s[0]][s[1]])
            s = path[(s[0], s[1])]
            
            
        return ans
