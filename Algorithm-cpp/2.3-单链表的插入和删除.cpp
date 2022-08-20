#include <stdio.h>
#include <mm_malloc.h>

typedef struct LNode //定义单链表节点类型
{
    int data;           //每个节点存放一个数据
    struct LNode *next; //指针指向下一个节点
} LNode, *LinkList;

//按位序插入(带头结点)
//在第 i 个位置插入元素 e(带头结点)
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *p;                      //指针 p 指向当前扫描到的结点
    int j = 0;                     //当前p指向的是第几个结点
    p = L;                         // L指向头结点, 头结点是第0个结点(不存数据)
    while (p != NULL && j < i - 1) //循环找到第 i-1 个结点
    {
        p = p->next;
        j++;
    }
    if (p == NULL) // i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; //将结点 s 连到 p 之后
    return true; //插入成功
}

//按位序插入(不带头结点版本)
bool ListInsert02(LinkList &L, int i, int e)
{
    if (i < 1)
    {
        return 0;
    }
    if (i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return;
    }
    LNode *p;
    int j = 1;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//后插操作: 在p结点之后插入数据元素 e
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
    {
        return 0;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return 0;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//前插操作: 在p结点之前插入元素 e
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
    {
        return 0;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return 0;
    }
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return 1;
}

//按位序删除(带头结点)
bool ListDelete(LinkList &L, int i, int e)
{
    if (i < 1)
    {
        return 0;
    }
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        return false;
    }
    if (p->next == NULL)
    {
        return false;
    }
    LNode *q = q->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return 1;
}