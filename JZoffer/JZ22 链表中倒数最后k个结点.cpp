//暴力查找
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
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        int len = 0;
        ListNode *p = pHead;
        while(p){
            len++;
            p = p->next;
        }
        if(len < k) return NULL;
        p = pHead;
        for(int i = 0 ; i < len-k; ++i){
            p = p->next;
        }
        return p;
    }
};

//快慢指针
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
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        ListNode* fast = pHead ,*slow = pHead;
        //快指针先走k步
        for(int i = 0; i < k; ++i){
            if(fast != nullptr){
                fast = fast->next;   
            }else{
                return slow = nullptr;
            }
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
         return slow;
    }
};