#include <stdio.h>
#include <stdlib.h>
typedef struct queue{
    int data;
    struct queue * next;
}queue;

queue * initQueue(){
    queue * queueList = (queue *)malloc(sizeof(queue));
    queueList->next = NULL;
    return queueList;
}
queue * enQueue(queue * rear,int data){
    queue * enElem = (queue *)malloc(sizeof(queue));
    enElem->data = data;
    enElem->next = NULL;
    //使用尾插法
    rear->next = enElem;
    rear = enElem;
    return rear;
}
queue * deQueue(queue *top,queue * rear){
    if(top->next == NULL){
        printf("队列为空");
        return rear;
    }
    queue * p = top->next;
    printf("%d ",p->data);
    top->next = p->next;
    if(rear == p){
        rear = top;
    }
    free(p);
    return rear;
}
int main(){
    queue * queueList,*top,*rear;
    queueList=top=rear=initQueue();//创建头结点
    //向链队列中添加结点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
    rear=enQueue(rear, 1);
    rear=enQueue(rear, 2);
    rear=enQueue(rear, 3);
    rear=enQueue(rear, 4);
    //入队完成，所有数据元素开始出队列
    rear=deQueue(top, rear);
    rear=deQueue(top, rear);
    rear=deQueue(top, rear);
    rear=deQueue(top, rear);
    rear=deQueue(top, rear);
    return 0;
}