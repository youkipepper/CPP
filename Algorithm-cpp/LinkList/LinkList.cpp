#include <stdio.h>
#include"LinkList.hpp"

int main()
{

    List *list = createList();

    return 0;
    
}

int main_test()
{
    Node node1;
    Node node2;
    Node node3;

    //构建链表
    node1 = (Node){3, &node2};
    node2 = (Node){4, &node3};
    node3 = (Node){5, NULL};

    //通过一个结点, 就可以找到后继的所有结点(遍历)
    Node *curNode = &node1;

    while (curNode != NULL)
    {
        printf("%d ", curNode->data);
        curNode = curNode->next; // 让指针向后移, 获取下一个结点
    }

    return 0;
}

