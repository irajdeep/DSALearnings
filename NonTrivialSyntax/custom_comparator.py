# https://leetcode.com/problems/relative-sort-array/description/
import functools

class Solution:        
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        pos = dict()
        for n , val in enumerate(arr2):
            pos[val] = n 
            
        def customCmp(a , b):
            if a in pos and b in pos:
                if pos[a] < pos[b]:
                    return -1
                else:
                    return 1
            elif a not in pos and b in pos:
                return 1
            elif a in pos and b not in pos:
                return -1
            elif a < b:
                return -1
            else:
                return 1
                
        ans = sorted(arr1 , key=functools.cmp_to_key(customCmp))   
        return ans
