题目描述

Given a list, rotate the list to the right by k places, where k is non-negative. 

For example:
 Given1->2->3->4->5->NULLand k =2,
 return4->5->1->2->3->NULL. 

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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==NULL || k ==0) return head;
        int len = 1;
        ListNode *p = head;
        while(p->next){
            p = p->next;
            len++;
        }
        k = len - k%len;
        p->next = head;
        for(int i=0; i<k;i++){
            p = p->next;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};
