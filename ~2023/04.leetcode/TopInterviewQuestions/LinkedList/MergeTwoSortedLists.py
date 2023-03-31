# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 != None and l2 == None:
            return l1
        elif l1 == None and l2 != None:
            return l2
        elif l1 == None and l2 == None:
            return None
        ret = ListNode()
        if l1.val < l2.val:
            ret.val = l1.val
            ret.next = self.mergeTwoLists(l1.next, l2)
        else:
            ret.val = l2.val
            ret.next = self.mergeTwoLists(l1, l2.next)
        return ret

    def mergeTwoLists2(self, l1: ListNode, l2: ListNode) -> ListNode:
        answer = ListNode()
        cur = answer
        while l1 != None and l2 != None:
            if l1.val <= l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        if l1 != None:
            cur.next = l1
        if l2 != None:
            cur.next = l2
        return answer.next

    def mergeTwoLists3(self, l1: ListNode, l2: ListNode) -> ListNode:
        answer = None
        lst = []
        while l1:
            lst.append(int(l1.val))
            l1 = l1.next
        while l2:
            lst.append(int(l2.val))
            l2 = l2.next
        lst.sort()
        cur = None
        for val in lst:
            if answer == None:
                answer = ListNode(val)
                cur = answer
            else:
                cur.next = ListNode(val)
                cur = cur.next
        return answer


