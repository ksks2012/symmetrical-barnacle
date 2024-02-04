class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        n = len(word)
        initial_state = word
        current_state = word
        steps = 0

        while steps * k <= n:
            current_state = current_state[k:]

            ns = len(current_state)
            steps += 1

            if(current_state == initial_state[:ns]):
                return steps
        
        return steps