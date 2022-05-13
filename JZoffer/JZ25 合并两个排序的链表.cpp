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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        //创建一个新表头
        ListNode* newHead = new ListNode(0);
        //创建新表头指针
        ListNode* p = newHead;
        //当其中一个链表为空，直接返回另一个链表
        if(pHead1 == NULL) 
            return pHead2;
        if(pHead2 == NULL) 
            return pHead1;
        
        while(pHead1 && pHead2){
            //选择头节点小的链表作为新链表的头节点
            if(pHead1->val < pHead2->val){
                p->next = pHead1;
                //只移动取值的指针
                pHead1 = pHead1->next;
            }
            else{
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            //新节点指针后移
            p = p->next;
        }
        //两个链表合并时有一个先为空，直接连在另一个的后面
        if(pHead1 != NULL)
            p->next = pHead1;
        else
            p->next = pHead2;
        //返回值去掉表头
        return newHead ->next;
    }
};