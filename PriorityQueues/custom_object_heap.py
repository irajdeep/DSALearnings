# https://leetcode.com/problems/k-closest-points-to-origin/
import heapq

class Point:
        def __init__(self , x , y):
            self.dist = (x * x) + (y * y)
            self.x = x
            self.y = y
        def __lt__(self , other):
            return self.dist < other.dist
class Solution:    
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        heap = []
        
        for point in points:
            obj = Point(point[0] , point[1])
            heap.append(obj)
        
        heapq.heapify(heap)
        cnt = 0
        ans = []
        while cnt < K:
            tmp = heapq.heappop(heap)
            ans.append([tmp.x , tmp.y])
            cnt += 1
            
        return ans
