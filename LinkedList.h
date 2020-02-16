/**
 * @author goufn
 * @Data 2020/2/16 6:14 下午
 * 说明：链表头文件
*/

#include <stdio.h>
#include <stdlib.h>
#ifndef DATASTRUCTION_LINKEDLIST_H
#define DATASTRUCTION_LINKEDLIST_H
typedef int ElementType;
typedef struct node Node;
typedef struct node* LinkList;

LinkList CreateLinkListF(int n);
LinkList CreateLinkListR(int n);
void InsertAfterX(Node *p,ElementType x);
void InsertBeforeX(LinkList L,Node* p,ElementType x);
int DeleteAfter(Node *p);
void DeleteNode(LinkList L,Node* p);
void DelectByIndex(LinkList L,int i);
int DelectByValue(LinkList L,ElementType x);
Node* LocateByIndex(LinkList L,int i);
Node* LocateByValue(LinkList L,ElementType x);
void PrintList(LinkList head);

#endif //DATASTRUCTION_LINKEDLIST_H

