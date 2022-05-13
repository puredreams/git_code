//双指针
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
    ListNode* deleteDuplication(ListNode* pHead) {
    if (!pHead) return NULL;
    //创建虚拟头节点，防止第一个节点就重复的问题
    ListNode* nhead = new ListNode(0);
    nhead->next =  pHead;
    ListNode* pre= nhead, *cur = pHead;
    while(cur){
        //相邻节点值相等
        if(cur ->next && cur->val == cur->next->val){
            //找出所有的相同节点
            while(cur->next && cur->val == cur->next->val){
                cur = cur->next;
            }
            cur = cur->next;
            //跳过重复节点链接
            pre ->next = cur;
        }
        else{
            pre = cur;
            cur = cur->next;
        }
    }
    return nhead->next;
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
    ListNode* deleteDuplication(ListNode* pHead) {
    if (!pHead) return NULL;
    //创建虚拟头节点，防止第一个节点就重复的问题
    ListNode* nhead = new ListNode(0);
    nhead->next =  pHead;
    ListNode *cur = nhead;
    //记录每个节点的个数
    unordered_map<int, int> map;
    while(cur){
        map[cur->val]++;
        cur = cur->next;
    }
    //重新遍历链表，删除重复元素
    cur = nhead;
    while(cur->next){
        if(map[cur->next->val] != 1){
            //跳过重复元素
            cur->next = cur->next->next;
        }else{
            cur = cur->next;
        }
    }
    //返回头节点
    return nhead->next;
    }
};