//
//  main.c
//  静态链表
//
//  Created by 朱勇麒 on 2020/9/15.
//  Copyright © 2020 朱勇麒. All rights reserved.
//

#include <stdio.h>
#define MAX 6

typedef struct {
    int data;//数据
    int cur;//游标
}component;

//备用链表
void reserveArr(component* array){
    int i=0;
    for (i=0; i<MAX; i++) {
        array[i].cur=i+1;
        array[i].data=0;
    }
    array[MAX-1].cur=0;
}

//分配空间,从备用链表摘掉节点
int mallocArr(component* array){
    int i=array[0].cur;
    if(array[0].cur){
        array[0].cur=array[i].cur;
    }
    return i;
}

//初始化链表
int initArr(component* array){
    int tempBody=0,body=0;
    int i=0;
    
    //备用链表
    reserveArr(array);
    body=mallocArr(array);
    
    array[body].data=1;
    array[body].cur=0;
    
    tempBody=body;
    
    for (i=2; i<4; i++) {
        int j=mallocArr(array);
        array[j].data=i;
        array[tempBody].cur=j;
        tempBody=j;
    }
    
    array[tempBody].cur=0;
    return body;
}

//插入元素
void insertArr(component* arr,int body,int add,int num){
    int tempBody=body;
    int insert=0;
    for(int i=1;i<add;i++){
        tempBody=arr[tempBody].cur;
    }
    
    insert=mallocArr(arr);
    arr[insert].data=num;
    arr[insert].cur=arr[tempBody].cur;
    arr[tempBody].cur=insert;
}


//遍历显示静态链表
void displayArr(component* arr,int body){
    int tempbody=body;
    while (arr[tempbody].cur) {
        printf("%d,%d \n",arr[tempbody].data,arr[tempbody].cur);
        tempbody=arr[tempbody].cur;
    }
    printf("%d,%d \n",arr[tempbody].data,arr[tempbody].cur);
}

int main(){
    component arr[MAX];
    int body=initArr(arr);
    
    printf("静态链表为：\n");
    displayArr(arr, body);
    
    insertArr(arr, 1 , 2 , 100);
    printf("静态链表为：\n");
    displayArr(arr, body);
    
    return 0;
    
}
