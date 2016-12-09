题目描述


Sort a linked list using insertion sort. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//时间复杂度为O(n^2),空间复杂度为O(1)
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN);
        for(ListNode* cur = head; cur != nullptr;){
            auto position = findInsertPos(&dummy, cur->val);
            ListNode* tmp = cur->next;
            cur->next = position->next;
            position->next = cur;
            cur = tmp;
        }
        return dummy.next;
    }
    
    ListNode* findInsertPos(ListNode* head, int value){
        ListNode* pre = nullptr;
        for(ListNode* cur = head; cur != nullptr && cur->val <= value; 
            pre = cur, cur=cur->next) ;
        return pre;
    }
};
