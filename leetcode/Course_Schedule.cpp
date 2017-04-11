class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int fixed=0;
        list<int> g[numCourses];
        list<int> g_rev[numCourses];
        queue<int> q=queue<int>();
        for(int i=0;i<prerequisites.size();i++){
            g[prerequisites[i].second].push_back(prerequisites[i].first);
            g_rev[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        for(int i=0;i<numCourses;i++){
            if(g_rev[i].empty()){
                q.push(i);
                fixed++;
            }
        }
        if(fixed==numCourses){
            return true;
        }
        while(!q.empty()){
            int cs=q.front();
            q.pop();
            for(list<int>::iterator iter=g[cs].begin();iter!=g[cs].end();iter++){
                int cd=*iter;
                if(cd!=-1){
                    *iter=-1;
                    g_rev[cd].remove(cs);
                    if(g_rev[cd].empty()){
                        q.push(cd);
                        fixed++;
                        if(fixed==numCourses){
                            return true;
                        }
                    }                    
                }
            }
        }
        return false;
    }
};
