题目描述

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list. 

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8 

时间复杂度O（m+n）,空间复杂度O（1）
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode list(-1);
        int carry = 0;
        ListNode *head = &list;
        for(ListNode *pa = l1, *pb = l2; pa != NULL || pb != NULL;
           pa = pa==NULL?NULL:pa->next, pb = pb==NULL?NULL:pb->next,head = head->next){
            const int ai = pa==NULL?0:pa->val;
            const int bi = pb==NULL?0:pb->val;
            const int value = (ai + bi + carry) % 10;
            carry = (ai + bi + carry) / 10;
            head->next = new ListNode(value);
        }
        if(carry > 0)
            head->next = new ListNode(carry);
        return list.next;
    }
};
