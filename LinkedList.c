/**
 * @author goufn
 * @Data 2020/2/16 5:40 下午
 * 说明：链表的实现
*/
#include "LinkedList.h"
struct node
{
    ElementType data;
    Node *next;
};
/*头插法建立单链表，n为要初始化的结点个数*/
LinkList CreateLinkListF(int n)
{
    Node *head;
    Node *s;
    int i;
    ElementType x;
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    for(i=0;i<=n;i++)
    {
        scanf("%d",&x);
        s = (Node*)malloc(sizeof(Node));
        s->data = x;
        s->next = head->next;
        head->next = s;
    }
    return head;
}

/*尾插法建立单链表,n为要初始化的结点个数*/
LinkList CreateLinkListR(int n)
{
    Node *head,*s,*r;
    int i;
    ElementType x;
    head = (Node*)malloc(sizeof(Node));
    r = head;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        s = (Node*)malloc(sizeof(Node));
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return head;
}

/*在结点p后面插入新结点，新结点的数据为x*/
void InsertAfterX(Node *p,ElementType x)
{
    Node *s;
    s = (Node*)malloc(sizeof(Node));
    s->data = x;
    s->next = p->next;
    p->next = s;
}

/*在结点p前面插入新结点，新结点的数据为x*/
void InsertBeforeX(LinkList L,Node* p,ElementType x)
{
    Node *s,*q;
    s = (Node*)malloc(sizeof(Node));
    s->data = x;
    q = L;
    while(q->next!=p)
        q = q->next;
    s->next = q->next;
    q->next = s;
}

/*删除p结点后面的结点，如果p是最后一个结点，返回0，否则返回1，代表删除成功*/
int DeleteAfter(Node *p)
{
    Node *r;
    if(p->next != NULL)
    {
        r = p->next;
        p->next = r->next;
        free(r);
        return 1;
    }
    return 0;
}

/*删除p结点*/
void DeleteNode(LinkList L,Node* p)
{
    Node* q;
    q = L;
    while(q->next!=p)
        q = q->next;
    q->next = p->next;
    free(p);
}

/*删除第i个结点*/
void DelectByIndex(LinkList L,int i)
{
    Node *p,*q;
    q = LocateByIndex(L,i-1);
    if(q==NULL)
    {
        printf("第i-1个结点不存在！");
    }
    else if(q->next==NULL)
    {
        printf("第i个结点不存在！");
    }else
    {
        p = q->next;
        q->next = p->next;
        free(p);
    }
}

/*删除单链表中所有值为x的结点，返回删除的结点个数*/
int DelectByValue(LinkList L,ElementType x)
{
    Node *p,*q;
    int count = 0;
    q = L;
    while(q->next!=NULL)
    {
        p = q->next;
        if(p->data==x)
        {
            q->next = p->next;
            free(p);
            count++;
        }
        else
            q = p;
    }
    return count;
}

// 打印链表
void PrintList(LinkList head)
{
    Node *p = head;
    if(p==NULL){
        printf("空链表");
    }
    else{
        p = p->next;
        while(p!=NULL)
        {
            printf("%d",p->data);
            printf("   ");
            p=p->next;
        }
    }
}
/*查找第i个元素结点，找到返回其指针，否则返回NULL*/
Node* LocateByIndex(LinkList L,int i)
{
    Node *p = L;
    int j = 0;
    while(j<i&&p->next!=NULL)
    {
        p = p->next;
        j++;
    }
    if(j==i)
        return p;
    else
        return NULL;
}

/*查找值为x的结点，找到返回其指针，否则返回NULL*/
Node* LocateByValue(LinkList L,ElementType x)
{
    Node *p = L->next;
    while(p!=NULL&&p->data!=x)
        p = p->next;
    return p;
}

int main(void)
{
    int i;
    ElementType x;
    LinkList head=NULL;
    while(1){
        printf("单向链表的基本操作\n");
        printf("**********************************\n");
        printf("1.创建链表\n");
        printf("2.插入数据\n");
        printf("3.删除数据\n");
        printf("4.打印链表\n");
        printf("5.按值查找\n");
        printf("6.退出\n");
        printf("**********************************\n");
        printf("请选择：");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                head=CreateLinkListR(0);
                printf("创建成功！");
                break;
            case 2:
                printf("输入要插入的数据：");
                scanf("%d",&x);
                if(head==NULL)
                    head=CreateLinkListR(0);
                InsertAfterX(head,x);
                break;
            case 3:
                printf("输入要删除的数据：");
                scanf("%d",&x);
                DelectByValue(head,x);
                break;
            case 4:PrintList(head);getchar();getchar();break;
            case 5:
                printf("输入要查询的数据：");
                scanf("%d",&x);
                if(LocateByValue(head, x)==0)
                    printf("无此数据！");
                else{
                    printf("有此数据");
                    getchar();getchar();
                }
                break;
            case 6:exit(0);
        }
    }
    return 0;
}










