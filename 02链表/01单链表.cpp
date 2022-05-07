/*
 * @Author: your name
 * @Date: 2022-04-21 09:55:48
 * @LastEditTime: 2022-05-06 11:24:29
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \WDJSJ代码笔记\02链表\单链表.cpp
 */
#define _CRT_SECURE_NO_WARNINGS
#include "stddef.h"
#include "malloc.h"
#include "stdio.h"

//定义单链表节点
//初始化链表两种实现
//单链表的插入和删除
    //按位序插入
    


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
//单链表的插入和删除
//按位序插入 - 带头结点
//在第 i 个位置插入元素e
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
//指定结点的前插
bool InsertPriorNode(LNode *p,int e){
    if(p==NULL){
        return false;
    }

    LNode* s =(LNode*)malloc(sizeof(LNode));

    p->next=s;
    s->next = p->next;
    s->data=p->data;
    p->data =e;

    return true;
    
}
bool InsertPriorNode(LNode *p,LNode* s){
    if( p == NULL || s == NULL){
        return false;
    }
    s->next=p->next;
    p->next =s;
    int temp =p->data;
    p->data=s->data;
    s->data=temp;

    return true;
}
//按位序删除（带头结点）
bool ListDelete(LinkList &L,int i , int &e){

    if(i<1){
        return false;
    }

    LNode* p;
    int j =0;
    p=L;

    while (p!=NULL && j<i-1)
    {
        p=p->next;
        j++;
    }
    
    if(p==NULL){ //i值不合法
        return false; 
    }
    
    LNode* q = p->next;
    p->next=q->next;
    e =q->data;
    free(q);
    return true;
}
//按位序删除（不带头结点）
bool ListDelete(LinkList &L,int i,int &e){
    if(i<1){
        return false;
    }

    if(i==1){
        LNode* q = L;
        e=q->data;
        L=L->next;
        free(q)
    }

    LNode* p =L;
    int j =1;
    while(p !=NULL && j<i-1){
        p=p->next;
        j++;
    }

    if(p==NULL){
        return false; 
    }
    
    LNode* q = p->next;
    p->next=q->next;
    e =q->data;
    free(q);
    return true;

}
//删除指定结点p
bool DeleteNode(LNode* p){
    if(p=NULL){
        return false;
    }

    LNode* q = p->next;
    if(q==NULL){
        p=NULL;
    }
    p->data=p->next->data;
    p->next=q->next;
    free(q);

    return true;
}
// Singly Linked List search 
LNode* bGetElem(LinkList L,int i){
    if(i<1){
        return NULL;
    }

    LNode* p = L;
    int j =0 ;
    while (p !=NULL && j<i)
    {
        p = p->next;
        j++;
    }

    return p; 
}
LNode* GetElem(LinkList L,int e){
    LNode* p = L;
    while (p !=NULL && p->data !=e)
    {
        p = p->next;
    }
    return p; 
}
// Find Linked List Length
int Length(LinkList L){
    int len=0;
    LNode* p = L;
    while(p->data!=NULL){
        p=p->next;
        len++;
    }

    return len;
}
// Build Linked
//尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s,*r = L;
    scanf("%d",&x);
    while (x !=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}
//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}

