class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        sorted_nums=sorted(nums)
        result=set()
        for t in range(len(sorted_nums)-2):
            if t>0 and sorted_nums[t-1]==sorted_nums[t]:
                continue
            if sorted_nums[t]<0:
                n1=sorted_nums[t]
                target=-n1
                left=t+1
                right=len(sorted_nums)-1
                while left<right:
                    if sorted_nums[left]+sorted_nums[right]==target:
                        result.add((n1,sorted_nums[left],sorted_nums[right]))
                        while left<right and sorted_nums[left]==sorted_nums[left+1]:
                            left+=1
                        while left<right and sorted_nums[right]==sorted_nums[right-1]:
                            right-=1
                        left+=1
                        right-=1
                    elif sorted_nums[left]+sorted_nums[right]<target:
                        left+=1
                    else:
                        right-=1
            elif sorted_nums[t]==0:
                if sorted_nums.count(0)>=3:
                    result.add((0,0,0))
                break
            else:
                break
        return [list(item) for item in result]
