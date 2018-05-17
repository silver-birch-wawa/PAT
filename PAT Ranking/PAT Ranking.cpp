#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Stu{
    long stu_id;  // 位数太大要用long
    int grade;
    int rank_all;
    int location;
    int rank_location;
}stu[3000];

bool cmp(Stu x, Stu y){
  return x.grade > y.grade ;
}

int main()
{
    int i=0,j=0,k=0;
    int location=0;
    int rank;
    int grade;
    int point=0;
    long stu_id;

    // 记录局部排序  局部数组开始的标记
    int start;
    // 记录总的样例数
    int sum=0;

    scanf("%d",&location);
    for(i=0;i<location;i++){
        scanf("%d",&k);
        sum+=k;
        start=point;
        for(j=0;j<k;j++){
            scanf("%ld %d",&stu_id,&grade);
            stu[point].grade=grade;
            stu[point].stu_id=stu_id;
            stu[point].location=i+1;
            point++;
        }
        // 局部排序
        sort(stu+start,stu+point,cmp);

        for(j=start;j<point;j++){
          stu[j].rank_location=j-start+1;
        }
        // 全局排序
        sort(stu+0,stu+point,cmp);

        stu[0].rank_all=1;
        for(j=1;j<point;j++){
            if(stu[j].grade==stu[j-1].grade){
              stu[j].rank_all=stu[j-1].rank_all;
            }
            stu[j].rank_all=j+1;
        }
    }
    printf("%d\n",sum);
    for(j=0;j<point;j++){
      printf("%ld %d %d %d\n",stu[j].stu_id,stu[j].rank_all,stu[j].location,stu[j].rank_location);
    }
}
