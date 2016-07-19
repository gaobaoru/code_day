#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
}Node;

typedef struct _list{
    Node *head;
    Node *tail;
}List;

void add(List *pList,int number);
void print(List *pList);
void reverselist(List *pList);
void clearlist(List *pList);

int main(int argc,char const *argv[])
{
    List list;
    list.head = list.tail = NULL;
    int number;
    do
    {
        scanf("%d",&number);
        if(number != -1)
        {
            add(&list,number);
        }

    }while(number != -1);
    reverselist(&list);
    print(&list);
    return 0;
}

void add(List *pList,int number)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    if(pList->tail)
    {
        pList->tail->next = p;
        pList->tail = p;
    }
    else
    {
        pList->head = pList->tail = p;
    }

}

void print(List *pList)
{
    Node *p;
    for(p=pList->head;p;p = p->next)
    {
        printf("%d ",p->value);
    }
    printf("\n");
}
//链表逆序
void reverselist(List *pList)
{
    if(pList->head && pList->head->next)
    {
        Node *t = NULL;
        Node *p = pList->head;
        Node *q = pList->head->next;
        while( q )
        {
            t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        pList->head->next = NULL;
        pList->head = p;
    }
}
