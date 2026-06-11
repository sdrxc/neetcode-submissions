class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        st = set()
        for x in nums: 
            st.add(x)

        n = len(nums)

        for i in range(1,n+2):
            if i not in st:
                return i
        
        return n+1
        