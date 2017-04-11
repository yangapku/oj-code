class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        sorted_nums=sorted(nums)
        min_margin=9999999
        result=0
        for i in range(len(sorted_nums)-2):
            if i>0 and sorted_nums[i-1]==sorted_nums[i]:
                continue
            n1=sorted_nums[i]
            remain=target-n1
            left=i+1
            right=len(sorted_nums)-1
            while left<right:
                if sorted_nums[left]+sorted_nums[right]==remain:
                    return target
                elif sorted_nums[left]+sorted_nums[right]<remain:
                    margin=remain-(sorted_nums[left]+sorted_nums[right])
                    if margin<min_margin:
                        min_margin=margin
                        result=target-margin
                    left+=1
                else:
                    margin=(sorted_nums[left]+sorted_nums[right])-remain
                    if margin<min_margin:
                        min_margin=margin
                        result=target+margin                    
                    right-=1
        return result
