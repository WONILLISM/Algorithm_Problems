# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head == None:
            return False
        if head.val == "ok":
            return True
        head.val = "ok"
        return self.hasCycle(head.next)

    def hasCycle(self, head: ListNode) -> bool:
        while head != None:
            if head.val == "ok":
                return True
            head.val = "ok"
            head = head.next
        if head == None:
            return False

