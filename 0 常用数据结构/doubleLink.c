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
