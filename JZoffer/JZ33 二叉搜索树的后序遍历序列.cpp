/*
题目链接: https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=23289&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回 true ,否则返回 false 。假设输入的数组的任意两个数字都互不相同。

数据范围： 节点数量 0 \le n \le 10000≤n≤1000 ，节点上的值满足 1 \le val \le 10^{5}1≤val≤10 
5
  ，保证节点上的值各不相同
要求：空间复杂度 O(n)O(n) ，时间时间复杂度 O(n^2)O(n 
2
 )
提示：
1.二叉搜索树是指父亲节点大于左子树中的全部节点，但是小于右子树中的全部节点的树。
2.该题我们约定空树不是二叉搜索树
3.后序遍历是指按照 “左子树-右子树-根节点” 的顺序遍历
4.参考下面的二叉搜索树，示例 1

示例1
输入：
[1,3,2]
复制
返回值：
true
复制
说明：
是上图的后序遍历 ，返回true         
示例2
输入：
[3,1,2]
复制
返回值：
false
复制
说明：
不属于上图的后序遍历，从另外的二叉搜索树也不能后序遍历出该序列 ，因为最后的2一定是根节点，前面一定是孩子节点，可能是左孩子，右孩子，根节点，也可能是全左孩子，根节点，也可能是全右孩子，根节点，但是[3,1,2]的组合都不能满足这些情况，故返回false    
示例3
输入：
[5,7,6,9,11,10,8]
复制
返回值：
true
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        //处理空序列
        if(sequence.size() == 0) return false;
        stack<int> s;
        int root = INT_MAX;
        //以根，右子树，左子树顺序遍历
        for(int i = sequence.size() - 1; i >= 0; i--){
            //确定根后一定是在右子树节点都遍历完成，因此当前sequence未遍历的节点中只含左子树，左子树的节点如果>root则说明违背二叉搜索的性质
            if(sequence[i] > root) return false;
            while(!s.empty() && s.top() > sequence[i]){
                root = s.top();
                s.pop();
            }
            s.push(sequence[i]);
        }
        return true;
    }
};


