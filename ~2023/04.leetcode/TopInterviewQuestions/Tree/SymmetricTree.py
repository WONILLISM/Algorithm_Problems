from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        answer = False

        q = deque()
        if root:
            q.append((q.left, q.right))
        while q:
            left = q.popleft()[0]
            right = q.popleft()[1]
            print(left, right)
            if left.val == right.val:
                answer == true
            #if
