#include<stdio.h>
#include<string.h>

#define N 24

char print[N]="a";

void exchange(char input[],int destination,int point){
    char temp;
    temp=input[point];
    input[point]=input[destination];
    input[destination]=temp;
}
void p(char input[],char output[],int start,int end){
    int i;
    if(start==end-1){
        output[start]=input[end-1];
        printf("\n%s",output);
        return;
    }
    for(i=start;i<end;i++){
        output[start]=input[i];
        exchange(input,start,i);
        p(input,output,start+1,end);
        exchange(input,start,i);
    }
}
void c(char input[],char output[],int start,int end){
    int i;
    if(start==end){
        output[end]='\0';
        printf("\n>>>> %s:",output);
        p(output,print,0,strlen(output));
    }
    for(i=start;i<strlen(input);i++){
        output[start]=input[i];
        exchange(input,start,i);
        c(input,output,start+1,end);
        exchange(input,start,i);
    }
}
int main()
{
    char str[N];
    char output[N];
    scanf("%s",&str);
    strcpy(output,str);

    int c_top=0;  // C(c_top,c_bottom);
    scanf("%d",&c_top);
    c(str,output,0,c_top);
}
