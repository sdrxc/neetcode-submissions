class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        # Convert absolute value to string, reverse it, convert back
        reversed_str = str(abs(x))[::-1]
        result = sign * int(reversed_str)
        
        if result < -2**31 or result > 2**31 - 1:
            return 0
        return result