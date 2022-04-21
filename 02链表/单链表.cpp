/*
 * @Author: your name
 * @Date: 2022-04-21 09:55:48
 * @LastEditTime: 2022-04-21 16:09:40
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \WDJSJ代码笔记\02链表\单链表.cpp
 */
#include "stddef.h"
#include "malloc.h"

/**
 * @description: 定义一个单链表
 * @attention：在C语言中定义结构体，需要用typedef 声明结构体别名，
 * @attention:否则在声明结构体变量时，需要加struct [结构体名] [结构体变量名]
 * @attention：C++不需要
 */
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct LNode LNode;
typedef struct LNode *LinkList;

//初始化链表两种实现

/**
 * @description: 初始化链表-不带头结点
 */
bool InitList(LinkList &L)
{ //注意这里&
    L = NULL;
    return true;
}

/**
 * @description: 初始化链表0带头结点
 */
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

//单链表的插入和删除

//按位序插入 - 带头结点
/**
 * @description: 在第 i 个位置插入元素e
 * @param {LinkList} &L
 * @param {int} i
 * @param {int} e
 * @return {*}
 */
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
    {
        return false;
    }

    LNode *p;
    p = L;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = L->next;
        j++;
    }

    if (p == NULL)
    {
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}

//按位序插入 - 不带头结点

bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
    {
        return false;
    }

    if(i==1){
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s->data=e;
        s->next=L;
        L=s; //头指针指向新节点
        return true;
        }
    
    LNode *p;
    p =L;
    int j = 1; //从第二个节点开始
    
    while (p != NULL && j < i - 1)
    {
        p = L->next;
        j++;
    }

    if (p == NULL)
    {
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}

//指定结点的后插操作

bool InsertNextNode(LNode *p,int e){
    if(p ==NULL){
        return false;
    }
    LNode* s=(LNode*)malloc(sizeof(LNode));

    s->data=e;
    s->next=p->next;
    p->next=s;

    return true;

}
