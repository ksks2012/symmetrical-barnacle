class Solution:
    def earliestSecondToMarkIndices(self, nums: List[int], changeIndices: List[int]) -> int:             
        def is_possible(k):
            nums1 = nums.copy()
            count = 0
            need = 0
            
            for j in range(k, -1, -1):
                i = changeIndices[j] - 1
                if nums1[i] == -1:
                    if need:
                        need -= 1
                else:
                    need += nums1[i]
                    nums1[i] = -1
                    count += 1
            
            if not need and count == len(nums1):
                return True
            
            ans = 0
            return ans
        
        l, r = 0, len(changeIndices)-1
        while l < r:
            m = (l + r) // 2
            if is_possible(m):
                r = m
            else:
                l = m + 1
        if not is_possible(l):
            return -1
        return l + 1
