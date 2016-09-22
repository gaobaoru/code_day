

对于一个链表，我们需要用一个特定阈值完成对它的分化，使得小于等于这个值的结点移到前面，大于该值的结点在后面，同时保证两类结点内部的位置关系不变。

给定一个链表的头结点head，同时给定阈值val，请返回一个链表，使小于等于它的结点在前，大于等于它的在后，保证结点值不重复。
测试样例：

{1,4,2,5},3

{1,2,4,5}


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Divide {
public:
    ListNode* listDivide(ListNode* head, int val) {
        // write code here
        ListNode *pSmallHead = NULL;
        ListNode *pSmallTmp = NULL;
        ListNode *pBigHead = NULL;
        ListNode *pBigTmp = NULL;
        while(head){
            ListNode *pTmp = head;
            head = head->next;
            pTmp->next = NULL;
            if(pTmp->val > val){
                if(pBigHead){
                    pBigTmp->next = pTmp;
                    pBigTmp = pTmp;
                }else{
                    pBigHead = pTmp;
                    pBigTmp = pTmp;
                }
            }else{
                if(pSmallHead){
                    pSmallTmp->next = pTmp;
                    pSmallTmp = pTmp;
                }else{
                    pSmallHead = pTmp;
                    pSmallTmp = pTmp;
                }
            }
        }
        if(!pSmallHead)
            return pBigHead;
        if(!pBigHead)
            return pSmallHead;
        pSmallTmp->next = pBigHead;
        return pSmallHead;
    }
};
