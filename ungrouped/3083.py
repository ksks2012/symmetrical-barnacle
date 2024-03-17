class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        # def has_mirror_substring(s):
        n = len(s)
        # Iterate through the string s
        for i in range(n - 1):
            # Check if the substring of length 2 is present in the reverse of s
            if s[i : i + 2] in s[::-1]:
                return True
        return False
