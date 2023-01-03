class Solution {
    bool dfs(int node, int p, int time, vector<int> &reachedTime, vector<int> adj[]){
        reachedTime[node] = time;
        if(node == 0) return true;
        for(auto &adjNode: adj[node]){
            if(adjNode != p){
                if(dfs(adjNode, node, time+1, reachedTime, adj)) return true;
            }
        }
        reachedTime[node] = 1e9;
        return false;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size()+1;
        vector<int> adj[n];
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // finding bob's path
        vector<int> reachedTime(n, 1e9);
        dfs(bob, -1, 0, reachedTime, adj);
        
        // now explore alice paths
        queue<vector<int>> q;
        vector<bool> vis(n, false);
        // {src, time, amount}
        q.push({0, 0, 0});
        vis[0] = true;
        int ans = INT_MIN;
        while(!q.empty()){
            int node = q.front()[0], time = q.front()[1], amt = q.front()[2];
            q.pop();
            // amount calculation
            if(reachedTime[node] == 1e9){
                // bob not reached here
                amt += amount[node];
            }else{
                if(time < reachedTime[node]){
                    amt += amount[node];
                }
                else if(time == reachedTime[node]){
                    amt += amount[node]/2;
                }
            }
            // leaf node
            if(adj[node].size() == 1 && node != 0) {
                ans = max(ans, amt);
            }
            // explore adjnodes
            for(auto &adjNode: adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode] = true;
                    q.push({adjNode, time+1, amt});
                }
            }
        }
        return ans;
    }
};