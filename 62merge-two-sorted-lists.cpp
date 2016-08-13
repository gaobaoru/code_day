题目描述


Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //时间复杂度O(min(m,n)),空间复杂度为O(1)
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode dummy(-1);
        ListNode* p = &dummy;
        for(;l1 != nullptr && l2 != nullptr; p = p->next){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 != nullptr ? l1 : l2;
        return dummy.next;
    }
}; 
