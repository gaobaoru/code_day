题目描述

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//时间复杂度为O(n1+n2+...),空间复杂度为O(1)
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* p = lists[0];
        for(unsigned long i = 1; i < lists.size(); i++){
            p = mergeTwoLists(p, lists[i]);
        }
        return p;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode dummy(-1);
        ListNode* p = &dummy;
        for(; l1 != nullptr && l2 != nullptr; p=p->next){
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
