/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param val int整型 
     * @return ListNode类
     */
    ListNode* deleteNode(ListNode* head, int val) {
        // write code here
        if(!head) return NULL;
        //定义虚拟头指针，防止删除的第一个元素是头节点
        ListNode* nhead = new ListNode(-1);
        nhead->next = head;
        ListNode* p = nhead;
        while(p->next){
            //找到删除的节点
            if(p->next->val == val){
                ListNode *tmp = p->next;
                p->next = p->next->next;
                free(tmp);
            }else{
                p = p->next;
            }
        }
        return nhead->next;
    }
};