class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int s = -1, n = nums.size(), e = n;
        // for start --> last peak from right
        int mini = INT_MAX;
        for(int i = n-1; i >= 0; i--){
            mini = min(mini, nums[i]);
            if(nums[i] > mini) s = i;
        }
        // for end --> last trough
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            if(nums[i] < maxi) e = i;
        }
        if(s == -1) return 0;
        return e-s+1;
    }
};