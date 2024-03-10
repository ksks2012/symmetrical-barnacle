class Solution:
    m = {}
    def shortestSubstrings(self, arr: List[str]) -> List[str]:
        self.m = {}
        sub = []
        for s in arr:
            sub.append(self.cut(s))

        ans = [""] * len(arr)
        for i in range(len(sub)):
            for j in range(len(sub[i])):
                if self.m[sub[i][j]] == 1 and len(ans[i]) == 0:
                    ans[i] = sub[i][j]
                elif self.m[sub[i][j]] == 1 and len(ans[i]) > len(sub[i][j]):
                    ans[i] = sub[i][j]
                    
        return ans
    
    def cut(self, s: str):
        results = []
        flag = set()
        for x in range(len(s)):
            for i in range(len(s) - x):
                tmp = s[i:i + x + 1]
                results.append(tmp)
                if tmp not in self.m:
                    self.m[tmp] = 0
                if tmp not in flag:
                    self.m[tmp] += 1
                    flag.add(tmp)
                
        results.sort()
        return results