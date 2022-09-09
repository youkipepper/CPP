#pragma once
#include <mm_malloc.h>
#include <iostream>

// 抽象数据类型
typedef int Data;

// 设计一个结构体, 每一个结点
typedef struct Node
{
    Data data;
    struct Node *next;
} Node, List;
// Node 代表结点, List 代表链表

//创建链表
List *createList()
{
    //动态内存分配
    List *head = (List *)calloc(1, sizeof(List));
    // head->next =NULL;//使用calloc不需要手动初始化为NULL;
    if (head == NULL)
    {
        puts("creat List faild~\n");
        return NULL;
    }

    return head;
}

//创建链表