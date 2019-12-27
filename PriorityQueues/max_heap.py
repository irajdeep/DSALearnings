#https://leetcode.com/problems/last-stone-weight
import heapq
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = [ -x for x in stones ]
        heapq.heapify(heap)
        
        while len(heap) > 1:
            x , y = heapq.heappop(heap) , heapq.heappop(heap)
            if x == y:
                continue
            val = -abs(abs(x) - abs(y))
            heapq.heappush(heap,val)
        
        if len(heap) == 0:
            return 0
        return -heap[0]
        
