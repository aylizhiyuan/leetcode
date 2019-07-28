#include <stdio.h>
#include <stdlib.h>
typedef struct line{
    struct line * prev;
    int data;
    struct line * next;
}line;
//双向链表的创建
line * initLine(line * head);
//双向链表的插入
line * insertLine(line *head,int data,int add);
//双向链表的删除
line * delLine(line * head,int data);
//双向链表的查找
int selectLine(line *head,int elem);
//双向链表的更新
line * updateLine(line *head,int add,int newElem);
//显示双向链表的数据
void display(line *head);

int main(){
    line * head = NULL;
    //创建链表
    head = initLine(head);
    display(head);
    //位置3插入元素7
    head = insertLine(head,7,3);
    display(head);
    //删除元素2
    head = delLine(head,2);
    display(head);
    printf("元素3的位置是%d\n",selectLine(head,3));
    //修改位置3中的数据为6
    head = updateLine(head,3,6);
    display(head);
    return 0;
}
line *initLine(line *head){
    head = (line *)malloc(sizeof(line));
    head->prev = NULL;
    head->next = NULL;
    head->data = 1;
    line *list = head;
    for(int i=2;i<=5;i++){
        line *body = (line *)malloc(sizeof(line));
        body->prev = NULL;
        body->next = NULL;
        body->data = i;
        //开始赋值
        list->next = body;
        body->prev = list;
        list = list->next;
    }
    return head;
}
line *insertLine(line *head,int data,int add){
       line * temp = (line *)malloc(sizeof(line));
       temp->data = data;
       temp->prev = NULL;
       temp->next = NULL;
       //插入到链表的头部要特殊考虑
       if(add == 1){
           temp->next = head;
           head->prev = temp;
           head = temp;
       }else{
           //插入到中间或者是最后
           line * body = head;
           //找到要插入位置的前一个节点
           for(int i=1;i<add-1;i++){
               body = body->next;
           }
           //判断条件为真，说明插入位置为链表尾部
           if(body->next == NULL){
               body->next = temp;
               temp->prev = body;
           }else{
               // 上一个点body ---> body->next 
               //新的节点要插入到body 和body->next中间来
               //我们要改变的是body->next temp->prev 
               // temp->next 以及 body->next->prev
               body->next->prev = temp;
               temp->next = body->next;
               body->next = temp;
               temp->prev = body;
           }
       }
       return head;
}
line * delLine(line *head ,int data){
    line * temp = head;
    //遍历链表
    while(temp){
        //判断当前节点中数据和data是否相等，相等摘除
        if(temp->data == data){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    printf("链表中无该元素");
    return head;
}
int selectLine(line *head,int elem){
    line * t = head;
    int i=1;
    while(t){
        if(t->data == elem){
            return i;
        }
        i++;
        t = t->next;
    }
    return -1;
}
line * updateLine(line *p ,int add, int newElem){
    line * temp = p;
    //遍历到更新的节点位置
    for(int i=1;i<add;i++){
        temp = temp->next;
    }
    temp->data = newElem;
    return p;
}
void display(line *head){
    line * temp = head;
    while(temp){
        if(temp->next == NULL){
            printf("%d\n",temp->data);
        }else{
            printf("%d->",temp->data);
        }
        temp = temp->next;
    }
}
