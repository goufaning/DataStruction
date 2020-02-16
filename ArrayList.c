/**
 * @author goufn
 * @Data 2020/2/16
 * 说明：本程序实现了一个顺序表
*/
#include <stdio.h>
#include <stdlib.h>
// 顺序表的大小
#define MAXSIZE 100
typedef int ElementType;
typedef struct {
    ElementType *data;
    int length;
}sqlist;

// 判断线性表是否为空，返回1为空，0为不空
int list_empty(sqlist L)
{
    if (0 == L.length)
        return 1;
    else
        return 0;
}

// 按序号查找，查找第i个元素的值（从0开始），找到返回1，将结果保存在e中，查找失败返回-1
int get_elem(sqlist L,int i,ElementType *e)
{
    if (i<0||i>L.length-1)
        return -1;
    *e = L.data[i];
    return i;
}

// 按内容查找，查找线性表中值为e的元素，查找成功返回对应的序号，返回-1表示失败
int local_elem(sqlist L, ElementType e)
{
    int i;
    for (i = 0; i < L.length; i++) {
        if (e == L.data[i])
            return i;
    }
    return -1;
}

// 插入操作，在线性表的第i个位置插入元素e，返回1表示成功
int list_insert(sqlist *L,int i,ElementType e)
{
    int j;
    if (i<0||i>L->length)
    {
        printf("插入位置错误");
        return -1;
    }
    else if(L->length>=MAXSIZE)
    {
        printf("顺序表已满，不能插入元素");
        return 0;
    }
    else
    {
        for (j=L->length;j>i;j--)
        {
            L->data[j] = L->data[j-1];
        }
        L->data[i] = e;
        L->length = L->length + 1;
        return 1;
    }
}

// 删除线性表中第i个位置的元素
int list_delete(sqlist *L,int i)
{
    int j;
    if (L->length<=0)
    {
        printf("顺序表已空，不能删除！");
        return -1;
    }else if(i<0||i>L->length-1)
    {
        printf("删除位置错误！");
        return -1;
    }
    else
    {
        for (j=i;j<L->length-1;j++)
        {
            L->data[j] = L->data[j+1];
        }

        L->length = L->length - 1;
        return 1;
    }
}
// 初始化线性表
void init_list(sqlist *L)
{
    L->data = (ElementType *)malloc(MAXSIZE * sizeof(ElementType));
    L->length = 0;
}
// 销毁顺序表
void clean_list(sqlist *L)
{
    L->length = 0;
    free(L->data);
    L->data = NULL;
}
// 打印顺序表
void print(sqlist *L) {
    int i;
    printf("线性表=");
    for(i=0; i<L->length; i++)
        printf("%d ",L->data[i]);
}

int main()
{
    sqlist array;
    int i,x;
    int n,m;//线性表长度
    init_list(&array);
    printf("请输入线性表的长度:");
    scanf ("%d",&n);
    printf("请输入线性表中的元素(用空格隔开):");
    for(i=0; i<n; i++) {
        scanf ("%d",&m);
        list_insert(&array, i, m);
    }
    print(&array);
    printf("\n请输入要插入到线性表中的数字和插入的位置(用空格隔开):");
    scanf("%d%d",&x,&i);
    list_insert(&array,i,x);
    print(&array);
    printf("\n请输入要删除的数字的位置:");
    scanf("%d",&i);
    list_delete(&array,i) ;
    print(&array);
    printf("\n请输入要查找的数字:");
    scanf("%d",&x);
    printf("数字%d所在的位置为%d\n",x,local_elem(array,x));
    clean_list(&array);
    return 0;
}



