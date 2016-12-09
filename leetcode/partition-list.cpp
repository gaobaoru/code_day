题目描述

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. 

You should preserve the original relative order of the nodes in each of the two partitions. 

For example,
 Given1->4->3->2->5->2and x = 3,
 return1->2->2->4->3->5. 


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
    ListNode *partition(ListNode *head, int x) {
        ListNode left_list(-1);
        ListNode right_list(-1);
        
        auto left_cur = &left_list;
        auto right_cur = &right_list;
        
        for(ListNode* cur = head; cur; cur = cur->next){
            if(cur->val < x){
                left_cur->next = cur;
                left_cur = cur;
            }else{
                right_cur->next = cur;
                right_cur = cur;
            }
        }
        left_cur->next = right_list.next;
        right_cur->next = NULL;
        
        return left_list.next;
    }
};

