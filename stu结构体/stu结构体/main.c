//
//  main.c
//  stu结构体
//
//  Created by 朱勇麒 on 2020/9/14.
//  Copyright © 2020 朱勇麒. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define N 100

//创建学生结构题
typedef struct stu{
    char *name;
    int number;
    //0为男生,1为女生
    int sex;
    float score;
}STU;


int main(){
    //新建四个学生
    STU stu1={"甲",20188327,0,91.22};
    STU stu2={"乙",20188327,0,92.22};
    STU stu3={"丙",20188327,0,93.22};
    STU stu4={"丁",20188327,0,94.22};
    
    //学生地址数组
    STU *student[]={&stu1,&stu2,&stu3,&stu4};
    int i=0;
    float max=0;
    STU *this = NULL;
    
    for(i=0;i<4;i++){
        if( (student[i]->score) >max){
            max= student[i] -> score;
            this=student[i];
        }
    }
    
    FILE *fp;
    if((fp = fopen("/Users/zhuyongqi/c/student.txt ","w+")) == NULL){
        puts("File to open");
    }
    
    char str1[100]="姓名";
    char str2[100];
    char str3[100];
    
    strcat(str1,this->name);
    sprintf(str2,"性别：%d",this->sex);
    sprintf(str3,"分数： %f",this->score);
        
    fputs("分数最高的学生是: \n",fp);
    fputs(str1,fp);
    fputs("\n",fp);
    fputs(str2,fp);
    fputs("\n",fp);
    fputs(str3,fp);
    fputs("\n",fp);
    fclose(fp);
    
}


