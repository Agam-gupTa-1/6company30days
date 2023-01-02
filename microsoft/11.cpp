#define ll long long
#define pll pair<ll, ll>
class Solution {
    int M = 1000000007;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj[n];
        for(auto &e: roads){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<ll> dist(n, LONG_MAX), ways(n, 0);
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        dist[0] = 0; ways[0] = 1;
        // {dis, node}
        pq.push({0, 0});

        while(!pq.empty()){ 
            auto[dis, node] = pq.top(); pq.pop();
            
            if(dis > dist[node]) continue;
            for(auto &e: adj[node]){
                long long weight = e[1], adjNode = e[0];
                if(dis + weight < dist[adjNode]){
                    dist[adjNode] = dis + weight;
                    ways[adjNode] = ways[node]%M;
                    pq.push({dist[adjNode], adjNode});
                }
                else if(dis + weight == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%M;
                }
            }
        }
        return ways[n-1];
    }
};