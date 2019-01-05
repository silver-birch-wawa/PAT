#include<iostream>
#include<algorithm>
using namespace std;
#define N 300000
typedef struct stu{
  long long id;
  int score;
  int final_rank;
  int location_number;
  int local_rank;
  stu(){
    id=0;
    score=0;
    final_rank=0;
    location_number=0;
    local_rank=0;
  }
}Stu;
int locations=0;
int length[N]={0};
bool cmp(stu &a,stu &b){
  return a.score>=b.score;
}
int main(){
  scanf("%d",&locations);
  int i,j;
  int sig=0;
  Stu stu[N];
  for(i=0;i<locations;i++){
    scanf("%d",&length[i]);
    sig+=length[i];
    for(j=0;j<length[i];j++){
      cin>>stu[sig-length[i]+j].id>>stu[sig-length[i]+j].score;
      stu[sig-length[i]+j].location_number=i+1;
    }
    sort(stu+sig-length[i],stu+sig,cmp);
    int rank=1;
    stu[sig-length[i]].local_rank=1;
    for(j=1;j<length[i];j++){
      //cout<<"local_rank:"<<sig-length[i]+j<<endl;
      if(stu[sig-length[i]+j].score==stu[sig-length[i]+j-1].score){
        stu[sig-length[i]+j].local_rank=stu[sig-length[i]+j-1].local_rank;
      }
      else{
        stu[sig-length[i]+j].local_rank=j+1;
      }
    }
  }
  sig=0;
  for(i=0;i<locations;i++){
    sig+=length[i];
  }
  sort(stu,stu+sig,cmp);
  stu[0].final_rank=1;
  for(i=1;i<sig;i++){
    if(stu[i].score==stu[i-1].score){
      stu[i].final_rank=stu[i-1].final_rank;
    }
    else{
      stu[i].final_rank=i+1;
    }
  }
  cout<<sig<<endl;
  for(i=0;i<sig;i++){
    cout<<stu[i].id<<" "<<stu[i].final_rank<<" "<<stu[i].location_number<<" "<<stu[i].local_rank<<endl;
  }
}
