class Solution {
    long long cnt = 0;
    void Merge(int s, int m, int e, vector<int> &nums, int &diff){
        int left = s, right = m+1;
        while(left <= m && right <= e){
            if(nums[left] <= nums[right]+diff){
                cnt += (e-right+1);
                left++;
            }
            else{
                right++;
            }
        }
        sort(nums.begin()+s, nums.begin()+e+1);
    }
    void mergeSort(int s, int e, vector<int> &nums, int &diff){
        if(s >= e)
            return;
        int mid = (s+e)/2;
        mergeSort(s, mid, nums, diff);
        mergeSort(mid+1, e, nums, diff);
        Merge(s, mid, e, nums, diff);
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> nums(n, 0);
        for(int i = 0; i < n; i++){
            nums[i] = nums1[i]-nums2[i];
        }
        for(auto &it: nums){
            cout << it << " ";
        }
        cout << endl;
        // reverse pair logic __ Merge Sort
        mergeSort(0, n-1, nums, diff);
        for(auto &it: nums)
            cout << it << " ";
        return cnt;
    }
};