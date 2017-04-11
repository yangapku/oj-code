class Solution(object):
    def binarySearch(self, array, value, left, right):
        if left>right:
            return -1
        mid=(left+right)//2
        mid_value=array[mid][0]
        if mid_value==value:
            return mid
        elif mid_value>value:
            return self.binarySearch(array, value, left, mid-1)
        else:
            return self.binarySearch(array, value, mid+1, right)

    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_id=zip(nums,range(len(nums)))
        sorted_nums=sorted(nums_id,key=lambda x: x[0])
        for i in range(len(sorted_nums)-1):
            remain=target-sorted_nums[i][0]
            j=self.binarySearch(sorted_nums, remain, i+1, len(sorted_nums)-1)
            if j>=0:
                return [sorted_nums[i][1], sorted_nums[j][1]]
