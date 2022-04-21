#include "stddef.h"
#include "malloc.h"

//定义一个单链表
struct LNode
{
    int *data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct LNode LNode;
typedef struct LNode *LinkList;

//初始化链表-不带头结点
bool InitList(LinkList &L)
{ //注意这里&
    L = NULL;
    return true;
}

//初始化链表0带头结点
bool InitList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if (L = NULL)
    {
        return false;
    }
    L->next = NULL;
    return true;
}
