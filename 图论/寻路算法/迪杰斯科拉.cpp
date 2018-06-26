/*先建立邻接矩阵的二维数组再以此建立邻接表形式的结构链表*/
#include<stdio.h>
#include<stdlib.h>
#define datatype char
#define FALSE 0
#define YES 1
#define MAX 10000
#define N 8888
typedef struct
{
   datatype tail_data;
   struct Node* nextarc;
}Node;

typedef struct
{
    datatype first_data;
    Node *firstarc;
}head_node;

typedef struct
{
   head_node* adjvex;
   int n,e;   /*n是点数，e是边数*/
}GRAph;
/*********************以下为矩阵数组的搭建*****************************/

/*初始化邻接矩阵的二维数组*/
int**  build_the_graph(int line)
{
    int i=0,j=0;
    int **Graph;
    if((Graph=(int**)malloc(line*sizeof(int*)))==NULL)
    {
        printf("第一次内存分配有误！\n");
        return -1;
    }
    for(i=0;i<line;i++)
    {
        if((Graph[i]=(int*)malloc(line*sizeof(int)))==NULL)
        {printf("第二次分配内存失败！\n");
         return -1;
        }
    }
    return Graph;
}

/*接下来我们计算边的个数*/
int culculate_e(int **G,int line)
{
    int i=0,j=0;
    int sum=0;
    for(i=0;i<line;i++)
    {
        for(j=0;j<line;j++)
        {
            if((G[i][j])!='0')
          {
            //printf("G:%c  ",G[i][j]);
            /*这里要小心getc得到的为ascii码的值为48，所以要用‘0’而非0！！*/
            sum++;
          }
        }
    }
    printf("\nsum=%d\n",sum);
    sum/=2;
    return sum;
}

/*从txt文件中读取数据到数组中*/
int init_Graph(int *(*Graph),int line)
{
    int a[36]={N,5,2,10,N,10,5,N,2,N,1,3,2,2,N,5,8,N,10,N,5,N,7,N,N,1,8,7,N,2,10,3,N,N,2,N};
    int i=0,j=0;
    for(i=0;i<line;i++){
        for(j=0;j<line;j++){
            Graph[i][j]=a[i*6+j];
        }
    }

}
/*********************以上为矩阵数组的搭建*****************************/

/**************************dijskla算法*******************************/
int select(int choose[],int line)/*前提是已使用了的点被标为 0!!!*/
{
   int i=0,temp=0,min=MAX;
   int number=0;
   for(i=0;i<line;i++)
   {
      temp=choose[i];
      if(choose[i]!=0)
     {
      //printf("\nchoose[i]:%d",choose[i]);
      if(temp<min)
        {
         min=temp;
         number=i;
        }
      }
   }
   //printf("\ni:%d",i);
   return number;
}
void dijskla(int *(*G),int line)
{
    int i,j,k,NUM=0;
    int pre_select_number=0;/*保存父值*/
    int select_number=0;
    int choose[line];  /*存储权值*/
    int pre_point[line];    /*存储输出的点的次序*/
    int selected[line];/*判别是否已被选过*/
    for(i=0;i<line;i++)
    {
        selected[i]=FALSE;
        choose[i]=G[0][i]-48;/*给第一次使用进行初始化*/
        if(choose[i]!=0)
        {
            pre_point[i]=0;
        }
        //printf("\nG[0][i]:%d",G[0][i]);
        else pre_point[i]=-1;
       // printf("\npre_point[%d]:%d",i,pre_point[i]);
    }
    pre_point[0]=0;/*开头的父值指向自己*/
    selected[0]=YES;
while(NUM!=line-1)/*第一个点是内定的不需要所以可以少一次操作*/
 {
     pre_select_number=pre_point[select_number];
     select_number=select(choose,line);
     /*选出非0最小值*/
     selected[select_number]=YES;
     /*标记为已读*/
    /*从一行中筛选出除0外的最小值赋给变量select_number*/
for(i=0;i<line;i++)
 {
     if(((G[select_number][i]-48)!=0)&&selected[i]!=YES)
     {
        if(i!=select_number&&((choose[select_number]+G[select_number][i]-48)<choose[i]))
      {
         //printf("G[select_number][i]:%d",G[select_number][i]);
         pre_point[i]=select_number;
         choose[i]=G[select_number][i]+choose[select_number]-48;
         //printf("\n1***choose[%d]:%d selectd[]:%d,pre_point[]:%d",i,choose[i],selected[i],pre_point[i]);
      }
      else if(choose[i]==0)
      {
          pre_point[i]=select_number;
         choose[i]=G[select_number][i]+choose[select_number]-48;
      }
    }
}
   choose[select_number]=0;/*choose置零要放在后面，
   1是防止少加了一个choose[select_number]
   2是防止select最小数时把已读的数再挑一遍！！
   */
   printf("\n%d->%d->",pre_point[select_number],select_number);
   NUM++;
 }
}
/**************************dijskla算法*******************************/

int main()
{
    int i=0,j=0;
    int **Graph_vertex;
    int line=6;
    printf("共%d行\n",line);
    printf("开始初始化图：\n");
    if(Graph_vertex=build_the_graph(line))
   {
       printf("初始化成功\n");
   }
    init_Graph(Graph_vertex,line);
   for(i=0;i<line;i++)
   {
       for(j=0;j<line;j++)
       {
           printf("[%d,%d]=%d   ",i,j,Graph_vertex[i][j]);
       }
       printf("\n");
   }
  dijskla(Graph_vertex,line);
}
