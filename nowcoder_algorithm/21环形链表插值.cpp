

有一个整数val，如何在节点值有序的环形链表中插入一个节点值为val的节点，并且保证这个环形单链表依然有序。

给定链表的信息，及元素的值A及对应的nxt指向的元素编号同时给定val，请构造出这个环形链表，并插入该值。
测试样例：

[1,3,4,5,7],[1,2,3,4,0],2

返回：{1,2,3,4,5,7}


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class InsertValue {
public:
    ListNode* insert(vector<int> A, vector<int> nxt, int val) {
        // write code here
        if(A.empty()) return NULL;
        ListNode* head = createList(A, nxt);
        ListNode* p = head;
        ListNode* q = head->next;
        while(q != head && !(val >= p->val && val <= q->val)){
            p = q;
            q = p->next;
        }
        p->next = new ListNode(val);
        p->next->next = q;
        if(q == head && val < q->val){
            head = p->next;
        }
        p = p->next;
        while(p->next != head){
            p = p->next;
        }
        p->next = NULL;
        return head;
    }
private:
    ListNode* createList(vector<int> A, vector<int> next){
        if(A.empty()) return NULL;
        int i = 0;
        ListNode* head = new ListNode(A[i]);
        ListNode* cur = head;
        while(next[i] != 0){
            i = next[i];
            cur->next = new ListNode(A[i]);
            cur = cur->next;
        }
        cur->next = head;
        return head;
    }
};
