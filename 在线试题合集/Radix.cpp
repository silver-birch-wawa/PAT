#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
// 字符转数字
int char2int(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if (c >= 'a' && c <= 'z')
	{
		return c - 'a' + 10;
	}
	else
	{
		return -1;
	}
}
// 查找字符串中的最大单个数，+1得到最小进制数然后提交
int findSmallestRadix(char num[])
{
	int max = 0;
	for (int i = 0; num[i] != '\0'; i++)
	{
		if (max < char2int(num[i]))
		{
			max = char2int(num[i]);
		}
	}
	return max + 1;
}
// 计算为十进制的时候可能溢出
LL getnum(char x[],LL guess){
  int i,j;
  LL sum=0;
  for(i=0;i<strlen(x);i++){
    if(x[i]>='a'){
      sum*=guess;
      sum+=x[i]-'a'+10;
    }
    else{
      sum*=guess;
      sum+=x[i]-'0';
    }
  }
  // cout<<"target:"<<sum<<endl;
  return sum;
}
// 进制的答案
LL answers=-1;
void binsearch(char x[],LL target,LL start,LL ends){
  // cout<<start<<"  "<<ends<<endl;
  if(start>ends){
    return;
  }
  if(start==ends){
    LL nums=getnum(x,start);
    // 小心溢出<0
    if(nums<0){
      // 失败，没有解
      answers=-1;
      return;
    }
    if(nums==target){
      if(answers!=-1){
        answers=min(answers,start);
      }
      else{
        answers=start;
      }
      return;
    }
    return;
  }

  int i,j;
  LL sum=0;
  LL guess=(start+ends)/2;
  // cout<<"guess"<<guess<<endl;
  for(i=0;i<strlen(x);i++){
    if(x[i]>='a'){
        sum*=guess;
        sum+=x[i]-'a'+10;
    }
    else{
        sum*=guess;
        sum+=x[i]-'0';
    }
    if(sum>target||sum<0){
        // sum<0说明LL装不下溢出了，所以肯定在 start和 middle-1之间
        // 当sum大于target的时候就不需要再算下去了
        // middle必须-1/+1，要不然会有34，35永远是34，35
        // cout<<"???"<<sum<<endl;
        binsearch(x,target,start,guess-1);
        return;
    }
  }
  // cout<<"sum:"<<sum<<endl;
  if(sum==target){
    if(answers!=-1){
      answers=min(answers,guess);
    }
    else{
      answers=guess;
    }
    return;
  }
  binsearch(x,target,guess+1,ends);
}
int main(){
  char a[50];
  char b[50];
  int signal=0;
  int radix=0;

  scanf("%s %s %d %d",&a,&b,&signal,&radix);
  // 避免0 0的特殊情况
  if(strlen(a)==strlen(b)&&strlen(a)==1){
    if(a[0]=='0'&&b[0]=='0'){
      cout<<2;
      return 0;
    }
  }

  if(signal==1){
    LL target=getnum(a,radix);
    // 最大进制肯定没有target+1大
    // 因为进制可能很大，所以必须进行二分查找
    // 需要计算进制的下限，因为1a用二进制计算的结果是2+10=12，跟十进制的12相等，很显然是错误的。
    int start= findSmallestRadix(b);
    binsearch(b,target,start,target+1);
  }
  else{
    LL target=getnum(b,radix);
    int start= findSmallestRadix(a);
    binsearch(a,target,start,target+1);
  }
  if(answers==-1){
    printf("Impossible");
    return 0;
  }
  printf("%lld",answers);
}
/*
6 110 1 10

1 ab 1 2

32 20 2 16

7 7 1 10

a a 1 10

0 0 1 10
2

1 1 1 10
2

2 2 1 10
3

55o01 2388985 2 10

100010110000111010110001001011101001011101 2388987787869 2 10

238898778787
298623473483

10 10 2 10
*/
