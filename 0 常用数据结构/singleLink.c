#include <stdio.h>
#include <stdlib.h>
typedef struct Link {
    int elem; //链表中的值
    struct Link *next; //指向下一个元素的指针
}link;

//初始化链表
link * initLink();
//链表插入元素
link * insertElem(link *p,int elem,int add);
//删除链表中的元素
link * delElem(link *p,int add);
//查找链表中的函数
int selectElem(link *p,int elem);
//更新链表中的数据
link *updateElem(link *p,int add,int newElem);
//显示链表中的数据
void display(link *p);

int main(){
    //初始化链表数据
    printf("初始化链表为:\n");
    link *p = initLink();
    display(p);
    printf("在第4的位置上插入元素5:\n");
    p = insertElem(p,5,4);
    display(p);
    printf("删除元素3:\n");
    p = delElem(p,3);
    display(p);
    printf("查找元素2的位置为:\n");
    int address = selectElem(p,2);
    printf("元素2位置上的为:%d\n",address);
    printf("更改第3的位置上的数据为7:\n");
    p = updateElem(p,3,7);
    display(p);
    return 0;
}
link *initLink(){
    link *p = (link *)malloc(sizeof(link));
    link *temp = p; //指向头结点，用于遍历
    for(int i=1;i<5;i++){
        link *a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}
link *insertElem(link *p,int elem,int add){
    link * temp = p;
    for(int i=1;i<add;i++){
        if(temp == NULL){
            printf("插入位置无效");
            return p;
        }
    }
    //创建一个新的结点
    link *c = (link*)malloc(sizeof(link));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;
    return p;
}
link *delElem(link *p,int add){
    link *temp = p;
    //遍历到被删除节点的上一个节点
    for(int i=1;i<add;i++){
        temp = temp->next;
    }
    link *del = temp->next; //这是我们要删除的节点
    temp->next = temp->next->next;
    free(del);
    return p;
}
int selectElem(link *p,int elem){
    link *t = p;
    int i=1;
    while(t->next){
        t = t->next;
        if(t->elem == elem){
            return i;
        }
        i++;
    }
    return -1;
}
link * updateElem(link *p,int add,int newElem){
    link *temp = p;
    temp = temp->next;
    for(int i=1;i<add;i++){
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}
void display(link *p){
    link * temp = p;
    while(temp->next){
        temp = temp->next;
        printf("%d ",temp->elem);
    }
    printf("\n");
}