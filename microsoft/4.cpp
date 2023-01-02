class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            res += (i*nums[i]);
        }
        int ans = res;
        for(int i = 1; i < n; i++){
            res += sum - n*nums[n-i];
            ans = max(ans, res);
        }
        return ans;
    }
};