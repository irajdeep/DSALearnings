# https://leetcode.com/contest/biweekly-contest-16/problems/sum-of-mutated-array-closest-to-target/
# using bisect_left

import bisect
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort()
        sum = 0
        for n in arr:
            sum += n
        if sum <= target:
            return arr[-1]
        
        psum = [0] * len(arr)
        psum[0] = arr[0]
        mini = abs(sum - target)
        
        for i in range(1 , len(arr)):
            psum[i] = arr[i] + psum[i - 1]
        
        for val in range(0 , 100001):
            pos = bisect.bisect_left(arr , val)
            if pos == 0:
                tmp = len(arr) * val
            else:
                tmp = psum[pos - 1] + (len(arr) - pos) * val

            if abs(tmp - target) < mini:
                ans = val
                mini = abs(tmp - target)
        
        return ans
            
            
            
