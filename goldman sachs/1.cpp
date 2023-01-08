class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        // slope concept
        // determine how many points falling on same line if we start the line from ith index
        int maxi = 2;
        for(int i = 0; i < n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            unordered_map<double, int> mp;
            for(int j = 0; j < n ;j++){
                if(i == j) continue;
                double dy = points[j][1]-y1;
                int dx = points[j][0]-x1;
                double m = 0;
                if(dx == 0) m = 1e9;
                else m = dy/dx;
                mp[m]++;
                maxi = max(maxi, mp[m]+1);
            }
        }
        return maxi;
    }
};