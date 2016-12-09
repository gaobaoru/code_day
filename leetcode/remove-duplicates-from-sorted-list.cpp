题目描述

Given a sorted linked list, delete all duplicates such that each element appear only once. 

For example,
 Given1->1->2, return1->2.
 Given1->1->2->3->3, return1->2->3. 

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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) return NULL;
        
        for(ListNode *prev = head, *cur = head->next; cur; cur=prev->next){
            if(prev->val == cur->val){
                prev->next = cur->next;
                delete cur;
            }else{
                prev = cur;
            }
        }
        
        return head;
    }
};
