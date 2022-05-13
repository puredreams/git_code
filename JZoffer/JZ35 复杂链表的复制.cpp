/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
    if(!pHead) return NULL;
    //定义新链表的头指针
    RandomListNode* newhead = new RandomListNode(pHead->label);
    //po指向旧链表的头，pn指向新链表的头
    RandomListNode* po = pHead, *pn = newhead;
    //哈希用于记录旧节点对应的新节点是否已经开辟，并且存储旧链表与先链表的地址
    unordered_map<RandomListNode*, RandomListNode*> map;
    //第一次遍历.保存每一个节点新旧的映射关系
    while(po){
        map[po] = new RandomListNode(po->label);
        po = po->next;
    }
    po = pHead;
    //第二次遍历给每个节点的random和next成员赋值
    while(po){
        pn->next = map[po->next];
        pn->random = map[po->random];
        po = po->next;
        pn = pn->next;
    }
        return newhead;
    }
};