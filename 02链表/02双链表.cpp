/*
 * @Author: your name
 * @Date: 2022-05-06 11:03:32
 * @LastEditTime: 2022-05-07 15:34:36
 * @LastEditors: Ikarikr 413826180@qq.com
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \WDJSJ代码笔记\双链表.cpp
 */
#include "malloc.h"


typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

//InitialDLinkList
bool InitDLinkList(DLinkList &L){
    L=(DLinkList)malloc(sizeof(DNode));
    if(L==NULL){return false;}
    L->prior=NULL;
    L->next=NULL;
    return true;
}

bool Empty(DLinkList L){
    if(L->next==NULL){
        return true;
    }else{
        return false;
    }
}

bool InsertNextDNode(DNode *p,DNode *s){
    if(p==NULL||s==NULL){
        return false;
    }
    s->next=p->next;
    s->prior=p;
    if(p->next !=NULL){
        p->next->prior=s;
    }
    p->next=s;
    return true;
}

bool DeleteNextDNode(DNode *p){
    if(p==NULL ||p->next==NULL){return false;}
    DNode* q=p->next;
    p->next=q->next;
    if(q->next !=NULL){
        q->next->prior=p;
    }

    free(q);
    return true;
}
