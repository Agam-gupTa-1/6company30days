class Solution {
    long long distance(vector<int> &a, vector<int> &b){
        long long x = a[0]-b[0], y = a[1]-b[1];
        return x*x+y*y;
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int cnt = 0;
        int n = points.size();
        for(int i = 0; i < n; i++){
            unordered_map<long long, int> mp;
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                long long dist = distance(points[i], points[j]);
                if(mp.find(dist) != mp.end()){
                    cnt += 2*mp[dist];
                    mp[dist]++;
                }
                else{
                    mp[dist] = 1;
                }
            }
        }
        return cnt;
    }
};