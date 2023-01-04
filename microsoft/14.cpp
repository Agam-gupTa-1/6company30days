class Solution {
    int M = 1000000007;
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd = numsDivide[0], n = numsDivide.size();
        for(int i = 1; i < n; i++){
            gcd = __gcd(gcd, numsDivide[i])%M;
        }
        // find numbers smaller than gcd
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            if(gcd%nums[i] == 0 && nums[i] < ans){
                ans = nums[i];
            }
        }
        if(ans == INT_MAX) return -1;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < ans) cnt++;
        }
        return cnt;
    }
};