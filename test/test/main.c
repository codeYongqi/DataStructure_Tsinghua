#include <stdio.h>
#include <stdlib.h>

int main(){
    int len;
    scanf("%d",&len);
    int num[len];
    for (int i = 0; i < len; i++) {
            int j;
            scanf("%d",&j);
            num[i]=j;
    }

    int thisSum=0,MaxSum=0,last_Sum=0;
    int begin=0,end=0,begin_last=0;
    for (int i = 0; i < len; i++) {
        thisSum+=num[i];
        if((thisSum>MaxSum)&&(thisSum>last_Sum)) {begin=begin_last;MaxSum=thisSum;last_Sum=thisSum;end=i;}
        else if(thisSum<0) {
            thisSum=0;
            begin_last=i+1;
        }
    }
    printf("%d %d %d",MaxSum,begin,end);
}
