/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        int res = 0;
        res += root->val;
        if(root->right == NULL && root->left == NULL && res == sum){
            return true;
        }
        bool LeftData = hasPathSum(root->left,sum-res);
        bool RightData = hasPathSum(root->right,sum-res);
        if(LeftData == true || RightData == true)
            return true;
        else
            return false;
    }
};