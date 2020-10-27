//
//  main.c
//  循环链表
//
//  Created by 朱勇麒 on 2020/9/14.
//  Copyright © 2020 朱勇麒. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//节点
typedef struct node{
    int number;
    struct node* next;
}person;

person* initLink(int n){
    //头节点
    person* head=NULL;
    //尾节点
    person* cyclic=NULL;
    
    head=(person*)malloc(sizeof(person));
    //头节点作为第一个人
    head->number=1;
    head->next=NULL;
    
    cyclic=head;
    
    for (int i=2; i<=n; i++) {
        
        person* body=(person*)malloc(sizeof(person));
        body->number=i;
        body->next=NULL;
        //头节点不动，尾节点增加
        cyclic->next=body;
        cyclic=cyclic->next;
    }
    //首位相连
    cyclic->next=head;
    return head;
}

void findAnkKill(person* head,int k,int m){
    person* p=NULL;
    person* tail=head;
    
    //找到第一个节点上一个节点
    while (tail->next!=head) {
        tail=tail->next;
    }
    
    p=head;
    
    while (p->number!=k) {
        //tail 始终是p上一个节点
        tail=p;
        p=p->next;
    }
    
    while (p->next!=p) {
        int i=0;
        
        for (i=1; i<m; i++) {
            tail=p;
            p=p->next;
        }
        
        tail->next=p->next;
        printf("出列人的编号为：%d \n",p->number);
        free(p);
        p=tail->next;
        
    }
    
    free(p);
}

int main(){
    int m,n,k;
    person* head=NULL;
    puts("请输入总人数：");
    scanf("%d",&n);
    head=initLink(n);
    puts("从第k人开始：");
    scanf("%d",&k);
    puts("每次数n个人：");
    scanf("%d",&m);
    
    findAnkKill(head, k, m);
}
