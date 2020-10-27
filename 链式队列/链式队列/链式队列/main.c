//
//  main.c
//  链式队列
//
//  Created by 朱勇麒 on 2020/10/18.
//  Copyright © 2020 朱勇麒. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct QNode{
    char* number;
    struct QNode* next;
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue* queue){
    queue->front=queue->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!queue->front) exit(EXIT_FAILURE);
    queue->front ->next =NULL;
    puts("初始化成功");
}

void Destory(LinkQueue* queue){
    while (queue->front) {
        queue->rear=queue->front->next;
        free(queue->front);
        queue->front=queue->rear;
    }
    puts("队列已销毁");
}

void EnQueue(LinkQueue* queue,char* number){
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(EXIT_FAILURE);
    p->number=number;
    p->next=NULL;

    queue->rear->next =p;
    queue->rear=p;
    
}

char* DeQueue(LinkQueue* queue){
    char* number;
    if(queue->rear==queue->front) exit(EXIT_FAILURE);
    QueuePtr p=queue->front->next;
    number=p->number;
    
    queue->front->next=p->next;
    if(queue->rear==p)queue->rear=queue->front;
    free(p);
    return number;
}

int main(){
    LinkQueue q;
    LinkQueue* queue=&q;
    
    int a;
    char s[12];
    char *res=s;
    while (1) {
        puts("请选择功能:\n1.初始化队列\n2:添加元素 \n3:删除元素 \n4:销毁队列\n5:退出程序");
        a=-1;
        scanf("%d",&a);
        switch(a){
                case 1:
                InitQueue(queue);
                break;
                
                case 2:
                puts("请输入要添加的元素");
                scanf("%s",s);
                EnQueue(queue, s);
                break;
                
                case 3:
                res=DeQueue(queue);
                puts("删除了");
                puts(res);
                break;
                
                case 4:
                Destory(queue);
                break;
                
                case 5:
                exit(0);
                break;
                
        }
        
    }
        
    return 0;
}
