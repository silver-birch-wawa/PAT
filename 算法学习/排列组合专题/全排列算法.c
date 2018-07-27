#include<stdio.h>
#include<string.h>
#define N 24
void exchange(char input[],int destination,int point){
    char temp;
    temp=input[point];
    input[point]=input[destination];
    input[destination]=temp;
}
void p(char input[],int start,int end){
    int i;
    if(start==end){
        printf("\n%s",input);
        return;
    }
    for(i=start;i<end;i++){
        exchange(input,start,i);
        p(input,start+1,end);
        exchange(input,start,i);
    }
}

int main()
{
    char str[N];
    scanf("%s",&str);
    p(str,0,strlen(str));
}
