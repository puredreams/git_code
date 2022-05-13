/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (!pRoot) return {};
        vector<vector<int> > res;
        queue<TreeNode*> q;
        q.push(pRoot);
        //记录层数
        int tier = 1;
        while(!q.empty()){
            //记录每一层的节点个数
            auto n = q.size();
            //存每一层的数据
            vector<int> vec;
            while(n--){
                TreeNode* node = q.front(); q.pop();
                vec.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            //处理偶数层,反转
            if(tier % 2 == 0){
                reverse(vec.begin(),vec.end());
            }
            //下一层
            tier++;
            //最终的结果结果
            res.push_back(vec);
        }
        return res;      
    }
};