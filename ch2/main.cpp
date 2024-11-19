#include<stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;//顺序表中元素类型起别名
typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;//SqList是这个结构体的别名

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

void print(SqList L){
    for(int i = 0; i < L.length; ++i){
        printf("%3d", L.data[i]);
    }
    printf("\n");
}
/**
 * 向顺序表中插入元素
 * @param L  顺序表
 * @param i  要插到第i个位置处
 * @param elem   待插入元素
 * @return   成功为true，否则为false
 */
bool insert(SqList &L, int i, ElemType elem){
    //1.判断i的合法性，i属于[1,length+1]
    if(i < 1 || i > L.length + 1){
        return false;
    }
    //2.判断还有无位置
    if(L.length >= MaxSize){
        return false;
    }
    //3.向后挪，腾位置；从下标角度分析：要插到i-1，所以i-1到len-1都要向后挪
    //挪的顺序：从右到左依次挪，从len-1 -> i-1
    //依次接收左面来的数据
    for(int j = L.length; j > i - 1; --j){
        L.data[j] = L.data[j -1];
    }
    //4.插入元素e !!链表长度+1!!
    L.data[i-1] = elem;
    L.length++;
    return true;
}

void testSeq(){

    SqList L;//1.定义顺序表
    bool ret;//
    for (int i = 0; i < 3; ++i) {
        L.data[i] = i+1;
    }
    L.length=3;
    print(L);
}

LinkList creatHeadInsert(LinkList &L){
    //0.
    LNode *s;
    int x;

    //1.创建头结点并初始化(头结点只需初始化next)
    L = (LinkList)malloc(sizeof (LNode));
    L->next = NULL;

    //2.输入数据
    scanf("%d", &x);
    //约定输入9999为终止输入
    while(x != 9999){
        //3.给结点分配空间，赋值，头插
        s = (LinkList)malloc(sizeof (LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;

        //4.继续输入
        scanf("%d", &x);
    }
    return L;
}

LinkList listTailInsert(LinkList &L){
    //0.存待插入数据
    int x;
    //创建头结点并初始化
    L =(LinkList) malloc(sizeof (LNode));
    L->next = NULL;
    //s用于创建结点；r指向最后一个结点，初始时指向头结点
    LNode *s, *r = L;

    //1.输入数据
    scanf("%d", &x);

    while (x != 9999){
        //创建新结点，赋值，尾插
        s = (LinkList) malloc(sizeof (LNode));
        s->data = x;
        r->next = s;//尾插
        r = s;//更新指向尾部的指针

        scanf("%d", &x);
    }
    r->next  = NULL;
    return L;
}

/**
 * 获取第n个结点的元素值
 * @param L
 * @param index
 * @return
 */
LinkList getElem1(LinkList L, int index){
    int count = 1;//计数器记录第一个结点，计数器与p同步
    LNode *p = L->next;//辅助结点指向第一个有值的结点
    //校验参数index的合法性
    if(index == 0){//值为0，则返回头结点
        return L;
    }
    if(index < 0){
        return NULL;
    }

    while(p && count<index){
        p = p->next;
        count++;
    }
    return p;
}
/*
 * 按值查找
 *
 */
LinkList getElem2(LinkList L, ElemType num){
    LNode *p = L->next;
    while(p && p->data != num){
        p = p->next;
    }
    return p;
}

/**
 * 向单链表的第i个位置插入结点
 * @param L
 * @param i
 * @param e
 * @return
 */
bool insertLinkList(LinkList &L, int i, ElemType e){

}

void printLinkList(LinkList L){
    L = L->next;//指向第一个有值的结点
    while (L != NULL){
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");
}

void testLink(){
    LinkList L;
    L = creatHeadInsert(L);
    printLinkList(L);
}

int main(){
    testLink();
    return 0;
}