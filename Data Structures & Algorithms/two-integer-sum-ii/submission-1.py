class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        
        um = {}

        for i in range(len(numbers)):
            rem = target - numbers[i]
            if rem in um:
                return [(um[rem]+1),(i+1)]
            
            um[numbers[i]] = i


        return [-1,-1]