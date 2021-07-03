class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        answer = []
        i = 0
        j = 0
        nums1.sort()
        nums2.sort()
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                answer.append(nums1[i])
                i+=1
                j+=1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1

        return answer

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        answer = []
        tmp = dict(Counter(nums1))
        for num in nums2:
            if num in tmp and tmp[num] != 0:
                answer.append(num)
                tmp[num] -= 1
        return answer
