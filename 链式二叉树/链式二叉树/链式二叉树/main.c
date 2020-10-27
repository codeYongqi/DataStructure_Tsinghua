//
//  main.c
//  链式二叉树
//
//  Created by 朱勇麒 on 2020/10/21.
//  Copyright © 2020 朱勇麒. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode{
    int data;
    struct BiTNode* lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree *t){
    *t=(BiTNode*)malloc(sizeof(BiTNode));
    (*t)->data=1;
    (*t)->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*t)->lchild->data=2;
    (*t)->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*t)->rchild->data=3;
    
    (*t)->lchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*t)->lchild->lchild->data=4;
    (*t)->lchild->lchild->lchild=NULL;
    (*t)->lchild->lchild->rchild=NULL;
    
    (*t)->lchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*t)->lchild->rchild->data=5;
    (*t)->lchild->rchild->lchild=NULL;
    (*t)->lchild->rchild->rchild=NULL;
    
    (*t)->rchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*t)->rchild->lchild->data=6;
    (*t)->rchild->lchild->lchild=NULL;
    (*t)->rchild->lchild->rchild=NULL;
    
    (*t)->rchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*t)->rchild->rchild->data=7;
    (*t)->rchild->rchild->lchild=NULL;
    (*t)->rchild->rchild->rchild=NULL;
}

//前序遍历
/*void displayElem(BiTNode* elem){
    printf("%d",elem->data);
}

void PreOrderTraverse(BiTree t){

    if(t){
        PreOrderTraverse(t->lchild);
        PreOrderTraverse(t->rchild);
        displayElem(t);
    }
    return;
}*/

//寻找值对应节点的双亲节点
/*
int flag=0;
BiTNode* m=NULL;
void presearch(BiTree t,int k){
    if(t&&(flag==0)){
        if(t->lchild!=NULL){
            if(t->lchild->data==k){
                flag=1;
                m=t;
                return ;
            }
        }
        
        if(t->rchild!=NULL){
            if(t->rchild->data==k){
            flag=1;
            m=t;
            return ;
            }
        }
        presearch(t->lchild, k);
        presearch(t->rchild, k);
    }
}

void find(BiTree t,int k){
    presearch(t,k);
    if(flag==1) printf("%d",m->data);
    else puts("null");
    
}
*/
int main() {
    BiTree tree;
    CreateBiTree(&tree);
    
  //  PreOrderTraverse(tree);
    return 0;
}
