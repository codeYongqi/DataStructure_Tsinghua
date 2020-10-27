//
//  main.c
//  数组循环队列
//
//  Created by 朱勇麒 on 2020/10/18.
//  Copyright © 2020 朱勇麒. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct stu{
    char* num;
}STU;

typedef struct {
    STU* base;
    int front;
    int rear;
}SqQueue;

void InitQueue(SqQueue* queue){
    queue->base=(STU*)malloc(MAXSIZE*sizeof(STU));
    if(!queue->base)exit(EXIT_FAILURE);
    queue->front=queue->rear=0;
    puts("初始化成功");
}

int QueueLength(SqQueue* queue){
    return (queue->rear - queue->front +MAXSIZE)%MAXSIZE;
}

void EnQueue(SqQueue* queue,char* s){
    if((queue->rear+1) % MAXSIZE ==queue->front) exit(EXIT_FAILURE);
    STU stu;
    stu.num=s;
    queue->base[queue->rear]=stu;
    queue->rear=(queue->rear+1) % MAXSIZE;
}

char* DeQueue(SqQueue* queue){
    char *s;
    if(queue->front==queue->rear) exit(EXIT_FAILURE);
    s=queue->base[queue->front].num;
    queue->front=(queue->front+1)%MAXSIZE;
    return s;
}

void DestoryQueue(SqQueue* queue){
    if(queue->base){
        free(queue->base);
        queue->base=NULL;
    }
    puts("队列已销毁");
}

int main() {
    SqQueue q;
    SqQueue* queue=&q;
    
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
                DestoryQueue(queue);
                break;
                
                case 5:
                exit(0);
                break;
                
        }
        
    }}
