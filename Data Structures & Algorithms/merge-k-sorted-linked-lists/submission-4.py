import heapq

class Solution:
    def mergeKLists(self, lists):
        heap = []

        # Push the head of every list
        for node in lists:
            if node:
                heapq.heappush(heap, (node.val, id(node), node))

        dummy = ListNode(0)
        tail = dummy

        while heap:
            _, _, node = heapq.heappop(heap)

            tail.next = node
            tail = tail.next

            if node.next:
                heapq.heappush(heap, (node.next.val, id(node.next), node.next))

        return dummy.next