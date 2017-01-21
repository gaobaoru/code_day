题目描述

Given a linked list, return the node where the cycle begins. If there is no cycle, returnnull. 

Follow up:
 Can you solve it without using extra space?

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode* slow2 = head;
                while(slow2 != slow){
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow2;
            }
        }
        return NULL;
    }
};
