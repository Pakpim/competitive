#include<stdio.h>
int main(){
    int h,m,x;
    scanf("%d%d%d",&h,&m,&x);
    printf("%02d %02d",(h+(m+x)/60)%24,(m+x)%60);
}