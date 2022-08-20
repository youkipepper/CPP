#include <stdio.h>
#include <mm_malloc.h>
typedef struct LNode //定义单链表结点类型
{
    int data;            //每个结点存放一个数据元素
    struct LNode *next; //指针指向下一个结点
} LNode, *LinkList;

//初始化一个单链表(带头结点)
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //分配一个头结点
    if (L == NULL)
    {
        return false;
    }
    L->next = NULL;
    return true;
}

//在第 i 个位置插入元素 e (带头结点)
bool ListInsert(LinkList &L, int i, int e)
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
        return 0;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

void test()
{
    LinkList L; //声明一个指向单链表的指针
    //初始化一个空表
    InitList(L);
}