/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        //判断链表为空或者链表长度为1，顺序不能调换
        if( pHead == NULL || pHead->next == NULL){
            return pHead;
        }
        //当前节点的前一个节点
        ListNode* pre = nullptr;
        //当前节点的后一个节点
        ListNode* nex = nullptr;
        while(pHead != nullptr){
            //记录当前节点的下一个节点
            nex = pHead->next;
            //当前节点的下一个节点指向前一个结点，完成反转
            pHead->next = pre;
            //前一个节点向右移动
            pre = pHead;
            //当前节点继续往右走
            pHead = nex;
        }
        return pre;
    }
};