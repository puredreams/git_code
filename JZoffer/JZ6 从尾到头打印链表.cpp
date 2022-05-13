class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<ListNode*> nodes;
        ListNode* phead = head;
        while (phead != nullptr){
            nodes.push(phead);
            phead = phead ->next;        
        }
        vector<int> res;
        while(!nodes.empty()){
            res.push_back(nodes.top()->val);
            nodes.pop();
        }
        return res;
    }
};