# Question: https://leetcode.com/problems/top-k-frequent-elements/
# Theory: https://docs.python.org/3/library/heapq.html
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = dict()
        
        for n in nums:
            if n in count:
                count[n] += 1
            else:
                count[n] = 1
        
        heap = []
        for n in count:
            if len(heap) < k:
                heapq.heappush(heap , (count[n] , n))
            elif count[n] > heap[0][0]:
                heapq.heapreplace(heap , (count[n] , n))
        
        ans = []
        
        for e in heap:
            ans.append(e[1])
        return ans
        
