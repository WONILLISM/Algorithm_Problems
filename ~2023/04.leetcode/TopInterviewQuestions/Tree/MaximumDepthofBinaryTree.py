# Definition for a binary tree node.
class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right

class Solution:
	#def maxDepth(self, root: TreeNode) -> int:
	#	if root == None:
	#		return 0
	#	return max(maxDepth(root.left), maxDepth(root.right)) + 1

	def maxDepth(self, root: TreeNode) -> int:
		answer = 0
		st = []
		deq = []

		if root:
			deq.append([root, 1])
			#st.append([root, 1])
		while deq:
			cur = deq.pop(0)
			#cur = st.pop()
			answer = max(answer, cur[1])
			if cur[0].left is not None:
				deq.append([cur[0].left, cur[1] + 1])
				#st.append([cur[0].left, cur[1] + 1])
			if cur[0].right is not None:
				deq.append([cur[0].right, cur[1] + 1])
				#st.append([cur[0].right, cur[1] + 1])
		return answer
