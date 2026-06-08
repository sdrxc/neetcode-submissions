# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head):
        nodes = []
        curr = head

        while curr:
            nodes.append(curr)
            curr = curr.next

        left, right = 0, len(nodes) - 1

        while left < right:
            nodes[left].next = nodes[right]
            left += 1

            if left == right:
                continue

            nodes[right].next = nodes[left]
            right -= 1

        nodes[left].next = None