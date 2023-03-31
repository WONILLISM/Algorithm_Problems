# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getListSize(self, head: ListNode) -> int:
        size = 0
        while head:
            size += 1
            head = head.next
        return size
    def getNewListNode(self, head: ListNode, d:int) -> ListNode:
        ret = ListNode()
        tmp = ret
        while 1:
            tmp.val = 0
            d -= 1
            if d == 0:
                tmp.next = head
                break
            else:
                tmp.next = ListNode()
            tmp = tmp.next
        return (ret)

    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        sizeA = self.getListSize(headA)
        sizeB = self.getListSize(headB)

        d = sizeA - sizeB
        if d > 0 :
            headB = self.getNewListNode(headB, abs(d))
        elif d < 0 :
            headA = self.getNewListNode(headA, abs(d))
        while headA and headB:
            # print(f"nodeA: {headA.val}\nnodeB: {headB.val}\n")
            if headA == headB:
                return headA
            headA = headA.next
            headB = headB.next
        return None



# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#class Solution:
#    def getListSize(self, head: ListNode) -> int:
#        size = 0
#        while head:
#            size += 1
#            head = head.next
#        return size

#    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
#        sizeA = self.getListSize(headA)
#        sizeB = self.getListSize(headB)

#        d = sizeA - sizeB
#        if d > 0:
#            d = abs(d)
#            while d:
#                headA = headA.next
#                d -= 1
#        elif d < 0:
#            d = abs(d)
#            while d:
#                headB = headB.next
#                d -= 1

#        while headA and headB:
#            if headA == headB:
#                return headA
#            headA = headA.next
#            headB = headB.next
#        return None
