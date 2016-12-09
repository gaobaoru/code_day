题目描述

Reverse a linked list from position m to n. Do it in-place and in one-pass. 

For example:
 Given1->2->3->4->5->NULL, m = 2 and n = 4, 

return1->4->3->2->5->NULL. 

Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list. 

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode list(-1);
        list.next = head;
        
        ListNode* pre = &list;
        for(int i=0;i<m-1;i++)
            pre = pre->next;
        ListNode* const pHead = pre;
        
        pre = pre->next;
        ListNode* pcur = pre->next;
        ListNode* tmp;
        for(int i=m;i<n;i++){
            tmp = pcur->next;
            pcur->next = pHead->next;
            pHead->next = pcur;
            pre->next = tmp;
            pcur = tmp;
        }
        return list.next;
    }
};
