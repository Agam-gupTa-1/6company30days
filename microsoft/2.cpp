class Solution {
    vector<vector<int>> ans;
    vector<int> t;
    void solve(int k, int prev, vector<bool> &vis, int n){
        if(k == 0){
            if(n == 0) ans.push_back(t);
            return;
        }
        for(int i = prev+1; i <= 9; i++){
            if(!vis[i] && n-i >= 0){
                t.push_back(i);
                vis[i] = true;
                solve(k-1, i, vis, n-i);
                vis[i] = false;
                t.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n < k || n > 45) return {};
        vector<bool> vis(10, false);
        solve(k, 0, vis, n);
        return ans;
    }
};