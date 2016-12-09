题目描述

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list. 

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is. 

You may not alter the values in the nodes, only nodes itself may be changed. 

Only constant memory is allowed. 

For example,
 Given this linked list:1->2->3->4->5 

For k = 2, you should return:2->1->4->3->5 

For k = 3, you should return:3->2->1->4->5 

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL || head->next==NULL || k<2) return head;
        ListNode list(-1);
        list.next = head;
        
        for(ListNode *prev = &list, *end = head; end; end = prev->next){
            for(int i=1;i<k && end; i++)
                end = end->next;
            if(end == NULL) break;
            
            prev = reverse(prev,prev->next,end);
        }
        return list.next;
    }
    
    ListNode* reverse(ListNode* prev, ListNode* begin, ListNode* end){
        ListNode *endNext = end->next;
        for(ListNode *p = begin, *cur = p->next, *pnext = cur->next;
           cur != endNext;
           p = cur, cur = pnext, pnext = pnext?pnext->next:NULL)
            cur->next = p;
        begin->next = endNext;
        prev->next = end;
        return begin;
    }
};
