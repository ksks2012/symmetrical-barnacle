class Solution:
    def encrypt(self, x):
        # Find the largest digit in x
        largest_digit = max(int(digit) for digit in str(x))
        # Construct the encrypted number by repeating the largest digit
        encrypted_number = int(str(largest_digit) * len(str(x)))
        return encrypted_number

    def sumOfEncryptedInt(self, nums: List[int]) -> int:
        # Initialize the sum
        total_sum = 0
        # Iterate through each number in nums
        for num in nums:
            # Add the encrypted number to the sum
            total_sum += self.encrypt(num)
        return total_sum