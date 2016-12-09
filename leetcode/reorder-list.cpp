题目描述

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→… 

You must do this in-place without altering the nodes' values. 

For example,
 Given{1,2,3,4}, reorder it to{1,4,2,3}. 

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
    void reorderList(ListNode *head) {
        if(head==NULL || head->next == NULL) return;
        ListNode *slow = head, *fast = head, *prev = NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        slow = reverse(slow);
        
        ListNode *cur = head;
        while(cur->next){
            ListNode *tmp = cur->next;
            cur->next = slow;
            slow = slow->next;
            cur->next->next = tmp;
            cur = tmp;
        }
        cur->next = slow;
    }
    
    ListNode* reverse(ListNode *head){
        ListNode *p = head;
        if(head && head->next){
            ListNode *tmp = NULL;
            ListNode *q = head->next;
            while(q){
                tmp = q->next;
                q->next = p;
                p = q;
                q = tmp;
            }
            head->next = NULL;
        }
        return p;
    }
};
