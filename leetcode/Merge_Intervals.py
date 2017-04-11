# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        record=list()
        for item in intervals:
            record.append((item.start,'b'))
            record.append((item.end,'e'))
        record=sorted(record,key=lambda x:x[0])
        result=list()
        cnt_b=0
        cnt_e=0
        cmax=-1
        cmin=-1
        for i in range(len(record)):
            if record[i][1]=='b':
                if cnt_b==0:
                    cmin=record[i][0]
                cnt_b+=1
            else:
                cnt_e+=1
                if cnt_e==cnt_b:
                    cmax=record[i][0]
                    if len(result)>0 and result[-1].end==cmin:
                        result[-1]=Interval(result[-1].start,cmax)
                    else:
                        result.append(Interval(cmin,cmax))
                    cnt_b=0
                    cnt_e=0
        return result
                    
        
