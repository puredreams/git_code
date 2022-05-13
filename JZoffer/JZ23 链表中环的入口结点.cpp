//快慢指针
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(!pHead && !pHead->next) return nullptr;
        //定义快慢指针
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        //快指针走两步，慢指针走一步,这里的条件要注意，不能判断为->next->next
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            //如果相遇，说明有环
            if(fast == slow)
                break;
        }
        //如果快指针走到头，表示没环返回空
        if(fast == nullptr || fast ->next == nullptr)
            return NULL;
        //如果有环，任意一个节点指向头节点
        fast = pHead;
        //找出入环节点,此时快指针和慢指针都走一步
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
//哈希
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        //用哈希保存链表
        unordered_set<ListNode*> set;
        ListNode* p = pHead;
        while(p){
            //判断p是否出现过，如果是，直接返回。
            if(set.count(p))
                return p;
            else
                set.insert(p);
            //向后移动
            p = p->next;
        }
        //无环
        return nullptr;
    }
};