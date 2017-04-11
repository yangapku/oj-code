class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int result=0;
        int len=s.length();
        int record[len+1][len+1];
        for(int i=0;i<=len;i++){
            record[i][0]=0;
            record[0][i]=0;
        }
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                int temp=record[i-1][j]>record[i][j-1]?record[i-1][j]:record[i][j-1];
                if(s[i-1]==s[len-j]){
                    temp=temp>(record[i-1][j-1]+1)?temp:(record[i-1][j-1]+1);
                }
                record[i][j]=temp;
                result=temp>result?temp:result;
            }
        }
        return result;
    }
};
