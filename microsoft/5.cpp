class Solution {
    // length of longest divisible subset
//     int solve(int i, int p, vector<int> &nums, vector<vector<int>> &dp){
//         if(i == nums.size())
//             return 0;
//         if(dp[i][p+1] != -1) return dp[i][p+1];
        
//         int pick = 0;
//         if(p == -1 || nums[i]%nums[p] == 0){
//             pick = 1 + solve(i+1, i, nums, dp);
//         }
//         // not pick
//         int npick = 0 + solve(i+1, p, nums, dp);
//         return dp[i][p+1] = max(pick, npick);
//     }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<int> dp(n, 1), hash(n, 0);
        
        int len = 0, lastInd = -1;
        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int j = 0; j < i; j++){
                if(nums[i]%nums[j] == 0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i] > len){
                len = dp[i];
                lastInd = i;
            }
        }
        vector<int> ans;
        while(hash[lastInd] != lastInd){
            ans.push_back(nums[lastInd]);
            lastInd = hash[lastInd];
        }
        ans.push_back(nums[lastInd]);
        return ans;
    }
};