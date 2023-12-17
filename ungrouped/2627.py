from typing import List

class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        import bisect

        nums.sort()

        def check_pali(int_str):
            return str(int_str) == str(int_str)[::-1]

        if len(nums) % 2 == 0:
            mid = nums[len(nums) // 2] + nums[len(nums) // 2 - 1]
            
        mid = nums[len(nums) // 2]
        mid_tmp = mid
        minus_check = -1
        minus_ans = 0

        while minus_check == -1:
            if check_pali(mid_tmp):
                for i in range(len(nums)):
                    minus_ans += abs(nums[i] - mid_tmp)
                minus_check = 1
                break
            mid_tmp -= 1

        mid_tmp = mid
        add_check = -1
        add_ans = 0
        while add_check == -1:
            if check_pali(mid_tmp):
                for i in range(len(nums)):
                    add_ans += abs(nums[i] - mid_tmp)
                add_check = 1
            mid_tmp += 1

        return min(minus_ans, add_ans)
