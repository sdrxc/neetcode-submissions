class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        um = {}

        for i,x in enumerate(nums):
            if x in um and abs(um[x] - i) <=k:
                return True
            
            um[x] = i
        
        return False