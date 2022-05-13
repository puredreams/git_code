/*描述
不分行从上往下打印出二叉树的每个节点，同层节点从左至右打印。例如输入{8,6,10,#,#,2,1}，如以下图中的示例二叉树，则依次打印8,6,10,2,1(空节点不打印，跳过)，请你将打印的结果存放到一个数组里面，返回。  
https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=23280&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13

具体做法：

step 1：首先判断二叉树是否为空，空树没有遍历结果。
step 2：建立辅助队列，根节点首先进入队列。
不管层次怎么访问，根节点一定是第一个，那它肯定排在队伍的最前面。
step 3：每次遍历队首节点，如果它们有子节点，依次加入队列排队等待访问。
*/
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
    vector<int> PrintFromTopToBottom(TreeNode* root){
    	vector<int> res;
		//如果是空直接返回vector
		if(root == NULL) return res;
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* cur;
		while(!q.empty()){
			cur = q.front();
			q.pop();
			res.push_back(cur->val);
			if(cur->left) q.push(cur->left);
			if(cur->right) q.push(cur->right);
		}
		return res;
    }
};