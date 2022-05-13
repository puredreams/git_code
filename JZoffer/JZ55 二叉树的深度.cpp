//队列
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
    int TreeDepth(TreeNode* pRoot) {
    if(!pRoot) return 0;
    //队列存储每一层的节点
    queue<TreeNode*> q;
    //根节点入队列
    q.push(pRoot);
    //记录深度
    int res = 0;
    while(!q.empty()){
        //记录当前层有多少个节点
        int n = q.size();
        while(n--){
            //本层的根节点做队头，再入队的就是左右孩子
            TreeNode* node = q.front();
            q.pop();
            //添加下一层的左右结点
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res++;
    }
    return res;
    }
};

//递归
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
    int TreeDepth(TreeNode* pRoot) {
    if(!pRoot) return 0;
    int lval = TreeDepth(pRoot->left);
    int rval = TreeDepth(pRoot->right);
    return max(lval,rval)+ 1;
    }
};