import heapq
from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        freq = Counter(nums)
        heap = []

        for nums, count in freq.items():
            heapq.heappush(heap,(count, nums))

            if len(heap) > k:
                heapq.heappop(heap)

        res = []

        while heap:
            res.append(heapq.heappop(heap)[1])

        return res

        