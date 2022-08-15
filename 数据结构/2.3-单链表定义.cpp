#include <stdio.h>
#include<mm_malloc.h>

// 单链表的定义
// ElemType 以 int 为例

typedef struct LNode //定义单链表节点类型
{
    int data;           //每个节点存放一个数据
    struct LNode *next; //指针指向下一个节点
} LNode, *LinkList;

// typedef struct LNode LNode;
// typedef struct LNode *LinkList;

//不带头结点版本
bool InitList(LinkList &L)
{
    L = NULL; //空表, 暂时还没有结点
    return true;
}

//带头结点版本
bool InitList2(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //分配一个头结点
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

void test01()
{
    LinkList L; //声明一个指向单链表的指针
    //初始化一个空表
    InitList(L);
}
