class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if k==0:
            for i in range(len(nums)):
                if nums[i]!=0:
                    return False
            if len(nums)>=2:
                return True
            else:
                return False
        record=[set() for i in range(len(nums))]
        record_pre=[-1 for i in range(len(nums))]
        for i in range(len(nums)):
            record_pre[i]=nums[i]%k
            if i>0:
                for remain in record[i-1]:
                    record[i].add((remain+nums[i])%k)
                record[i].add((record_pre[i-1]+nums[i])%k)
            if 0 in record[i]:
                return True
        return False
                        
        
