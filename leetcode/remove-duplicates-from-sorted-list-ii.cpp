题目描述

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 

For example,
 Given1->2->3->3->4->4->5, return1->2->5.
 Given1->1->1->2->3, return2->3. 

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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode list(INT_MIN);
        list.next = head;
        ListNode *prev = &list, *cur = head;
        while(cur){
            bool duplicated = false;
            while(cur->next && cur->val == cur->next->val){
                duplicated = true;
                ListNode *tmp = cur;
                cur = cur->next;
                delete tmp;
            }
            if(duplicated){
                ListNode *tmp = cur;
                cur = cur->next;
                delete tmp;
                continue;
            }
            prev->next = cur;
            prev = prev->next;
            cur = cur->next;
        }
        
        prev->next = cur;
        return list.next;
    }
};
