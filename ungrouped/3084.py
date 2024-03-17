class Solution:
    def countSubstrings(self, s: str, c: str) -> int:
        count = 0
        n = len(s)
        # Iterate through the string s
        for i in range(n):
            # If the current character is equal to c
            if s[i] == c:
                # Count the number of substrings that start and end with c
                count += s[i:].count(c)
        return count
