class Solution {
public:
    struct Node{
        bool flag;
        int prev;
        Node(){
            this->flag=false;
            this->prev=-1;
        }
    };
    int lengthOfLongestSubstring(string s) {
        Node record[300];
        int result=0;
        int temp=0;
        for(int i=0;i<s.length();i++){
            if(record[s[i]].flag){
                result=temp>result?temp:result;
                int cid=s[i];
                while(cid!=-1){
                    record[cid].flag=false;
                    int r=record[cid].prev;
                    record[cid].prev=-1;
                    temp--;
                    cid=r;
                }
                for(int j=0;j<300;j++){
                    if(record[j].prev==s[i]){
                        record[j].prev=-1;
                    }
                }
            }
            record[s[i]].flag=true;
            temp++;
            if(temp>1){
                record[s[i]].prev=s[i-1];
            }
        }
        result=temp>result?temp:result;
        return result;
    }
};
