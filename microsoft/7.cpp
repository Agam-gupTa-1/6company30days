class Solution {
public:
    bool canFinish(int courses, vector<vector<int>>& prerequisites) {
        // if we able to find the topo logical sort
        vector<int> adj[courses];
        vector<int> indegree(courses, 0);
        for(auto &p: prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        int cnt = courses;
        for(int i = 0; i < courses; i++)
        {
            if(!indegree[i]){
                cnt--;
                q.push(i);
            } 
        }
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(auto &child: adj[node]){
                indegree[child]--;
                if(!indegree[child])
                {
                    q.push(child);
                    cnt--;
                }
            }
        }
        if(!cnt) return true;
        return false;
    }
};