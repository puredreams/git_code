/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    //层遍历两个树是否相等
    bool checkTree(TreeNode* pRoot1, TreeNode* pRoot2) {
        queue<TreeNode*> q1,q2;
        q1.push(pRoot1);
        q2.push(pRoot2);
        while(!q2.empty()){
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();
            q1.pop(); 
            q2.pop();
            //如果树1或者树2不存在或根节点值不相等
            if(node1 == NULL || node1->val != node2->val) return false;
            //如果存在还要判断树2的左右节点是否还有根节点
            if(node2->left) q1.push(node1->left), q2.push(node2->left);
            if(node2->right) q1.push(node1->right), q2.push(node2->right);
        }
        return true;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2) return false;
        queue<TreeNode*> q;
        q.push(pRoot1);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            //如果左右根节点相同，则继续遍历左右子树
            if(node->val == pRoot2->val){
                if(checkTree(node, pRoot2)) return true;
            }
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return false ;;
    }
};