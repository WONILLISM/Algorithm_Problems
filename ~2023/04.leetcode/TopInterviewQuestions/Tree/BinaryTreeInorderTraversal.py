from typing import List
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
	def inorderTraversal(self, root: TreeNode) -> List[int]:
		if root == None:
			return []
		ret = []
		ret += self.inorderTraversal(root.left)
		ret += [root.val]
		ret += self.inorderTraversal(root.right)
		return ret
