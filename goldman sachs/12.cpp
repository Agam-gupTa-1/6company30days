class Solution {
    void solve(TreeNode *root, vector<int> &arr){
        if(!root) return;
        solve(root->left, arr);
        arr.push_back(root->val);
        solve(root->right, arr);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        solve(root1, arr1);
        solve(root2, arr2);
        // merge two sorted arrays
        int n = arr1.size(), m = arr2.size();
        vector<int> num(n+m, 0);
        int i = 0, j = 0, ind = 0;
        while(i < n && j < m){
            if(arr1[i] <= arr2[j]){
                num[ind++] = arr1[i++];
            }
            else{
                num[ind++] = arr2[j++];
            }
        }
        while(i < n) num[ind++] = arr1[i++];
        while(j < m) num[ind++] = arr2[j++];
        return num;
    }
};