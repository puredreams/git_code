/*
题目链接：
https://www.nowcoder.com/practice/a9d0ecbacef9410ca97463e4a5c83be7?tpId=13&tqId=1374963&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13

思想：
知识点：二叉树递归

递归是一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法，它通常把一个大型复杂的问题层层转化为一个与原问题相似的规模较小的问题来求解。因此递归过程，最重要的就是查看能不能讲原本的问题分解为更小的子问题，这是使用递归的关键。

而二叉树的递归，则是将某个节点的左子树、右子树看成一颗完整的树，那么对于子树的访问或者操作就是对于原树的访问或者操作的子问题，因此可以自我调用函数不断进入子树。

思路：

因为我们需要将二叉树镜像，意味着每个左右子树都会交换位置，如果我们从上到下对遍历到的节点交换位置，但是它们后面的节点无法跟着他们一起被交换，因此我们可以考虑自底向上对每两个相对位置的节点交换位置，这样往上各个子树也会被交换位置。

自底向上的遍历方式，我们可以采用后序递归的方法。

具体做法：

step 1：先深度最左端的节点，遇到空树返回，处理最左端的两个子节点交换位置。
step 2：然后进入右子树，继续按照先左后右再回中的方式访问。
step 3：再返回到父问题，交换父问题两个子节点的值。
*/
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        if(pRoot == NULL) return NULL;
        TreeNode* left = Mirror(pRoot->left);
        TreeNode* right = Mirror(pRoot->right); 
        pRoot->left = right;
        pRoot->right = left;
        return pRoot;
    }
};