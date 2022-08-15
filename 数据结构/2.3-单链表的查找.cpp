#include <stdio.h>
//按位查找

typedef struct LNode //定义单链表节点类型
{
    int data;           //每个节点存放一个数据
    struct LNode *next; //指针指向下一个节点
} LNode, *LinkList;

LNode *GetElem(LinkList &L, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    int j = 0;
    p = L;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return j;
}