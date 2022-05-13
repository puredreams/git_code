//常规解法
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    //链表为空，返回NULL
    if(!pHead1 ||!pHead2)
        return NULL;
 
    int len1 = 0, len2 = 0;
    //链表1长度
    ListNode* p = pHead1;
    while(p){
        len1++;
        p = p->next;
    }
    //链表2的长度
    p = pHead2;
    while(p){
        len2++;
        p = p->next;
    }
    //链子长的先走abs(len1-len2)步骤
    if(len1 > len2){
        for(int i = 0 ; i < len1 - len2; ++i){
            pHead1 = pHead1->next;
        }
    }
    else{
        for(int i = 0 ; i < len2 - len1; ++i){
            pHead2 = pHead2->next;
        }
    }
    //当两个链表同步后，指针相等的地方就是第一个公共节点
    while(pHead1 && pHead2 && pHead1 != pHead2 ){
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
    }
    return pHead1;
    }
};

//官方解法
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        //双指针
        ListNode* a = pHead1;
        ListNode* b = pHead2;
        //有一个链表为空，无公共节点，返回null
        if ( !pHead1 || !pHead2 )
            return NULL;
        //相当于链表相连，遍历了遍历整个链表
        while(a != b){
            //如果a没有走到链表尾部，a继续往下走一步，走到a的尾部，将再从b开始遍历。
            a = (a == nullptr)? pHead2:a->next;
            b = (b == nullptr)? pHead1:b->next;
        }
        return a;
    }
};