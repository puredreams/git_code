/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if(pre.empty() || vin.empty()) return NULL;
    //建立根节点
    int rootval = pre[0];
    TreeNode* root = new TreeNode(rootval);
    //找出根节点在中序遍历中的位置，确定左右节点子树个数
    int pos = 0;
    for(; pos < vin.size(); ++pos){
        if(vin.at(pos) == root->val) break;
    }
    //如果中序没有根节点
    //if (vin[pos] == vin.end()) break;
    //vector的拷贝构造函数，后续递归调用时需要用到的四个左右子树vector区间
    vector<int> left_pre(pre.begin()+1, pre.begin()+pos+1);
    vector<int> left_vin(vin.begin(), vin.begin()+pos);
    vector<int> right_pre(pre.begin()+pos+1, pre.end());
    vector<int> right_vin(vin.begin()+pos+1, vin.end());
    //递归构造左右子树
    root->left = reConstructBinaryTree(left_pre, left_vin);
    root->right = reConstructBinaryTree(right_pre, right_vin);
    return root;
    }
};