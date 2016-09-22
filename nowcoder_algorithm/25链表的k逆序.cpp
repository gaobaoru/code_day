

有一个单链表，请设计一个算法，使得每K个节点之间逆序，如果最后不够K个节点一组，则不调整最后几个节点。例如链表1->2->3->4->5->6->7->8->null，K=3这个例子。调整后为，3->2->1->6->5->4->7->8->null。因为K==3，所以每三个节点之间逆序，但其中的7，8不调整，因为只有两个节点不够一组。

给定一个单链表的头指针head,同时给定K值，返回逆序后的链表的头指针。


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) {
        // write code here
        ListNode *p = head;
        ListNode *q = head;
        stack<int> s;
        int count = 0;
        while(q){
            count++;
            s.push(q->val);
            q = q->next;
            if(count == k){
                while(p != q){
                    p->val = s.top();
                    s.pop();
                    p = p->next;
                }
                count = 0;
            }
        }
        return head;
    }
};
