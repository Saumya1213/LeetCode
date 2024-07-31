/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool solve(TreeNode*root, long long int lb, long long int ub){
        if(root==NULL) return true;
        if((root->val<ub && root->val>lb)&&(solve(root->left,lb,root->val)&&solve(root->right,root->val,ub))) return true;
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long int lb=-2147483649;
        long long int ub=2147483649;
        bool ans = solve(root,lb,ub);
        return ans;
    }
};