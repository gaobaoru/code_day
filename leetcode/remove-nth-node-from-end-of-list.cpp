题目描述

Given a linked list, remove the nth node from the end of list and return its head. 

For example, 
   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
 Given n will always be valid.
 Try to do this in one pass. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode list(-1);
        list.next = head;
        ListNode *p = &list, *q = &list;
        for(int i=0;i<n;i++)
            q = q->next;
        while(q->next){
            p = p->next;
            q = q->next;
        }
        ListNode* tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        return list.next;
    }
};
