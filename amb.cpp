#include<stdio.h>
#include<string.h>

int main()
{
    char a[20];
    int i,t=0;
    printf("Enter Ambiguous Production: E->");
    gets(a);
    char b[5]={'E','P','Q','R','S'};
    for(i=0;a[i]!='\0';){
        if(a[i]=='|'){
            i++;
        }
        else if(a[i]=='i' && a[i+1]=='d')
        {
            printf("%c->id",b[t]);
            i=i+2;
        }
        else{if(a[i+1]=='^')
        {
            printf("%c->%c^%c|%c\n",b[t],b[t+1],b[t],b[t+1]);
            t++;
            i=i+3;
        }
        else
        {
            printf("%c->%c%c%c|%c\n",b[t],b[t],a[i+1],b[t+1],b[t+1]);
            t++;
            i=i+3;
        }}}}
