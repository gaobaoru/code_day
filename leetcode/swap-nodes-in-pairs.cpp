题目描述

Given a linked list, swap every two adjacent nodes and return its head. 

For example,
 Given1->2->3->4, you should return the list as2->1->4->3. 

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode list(-1);
        list.next = head;
        
        for(ListNode *prev = &list, *cur = prev->next, *pnext = cur->next;
           pnext; prev = cur, cur = cur->next, pnext = cur?cur->next:NULL){
            prev->next = pnext;
            cur->next = pnext->next;
            pnext->next = cur;
        }
        return list.next;
    }
};
