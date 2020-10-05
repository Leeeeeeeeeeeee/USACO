#include <fstream>
#include <iostream>
#include <string.h>
#include <stdarg.h> //可变函数标准宏
using namespace std;
#define N 4

int recArea(int x,int y){
  return x*y;
}

int myMax (int count, ...)//第一个参数是计算的总数量，第二个参数开始是要计算的数值
{
  int max = 0;
  int temp = 0;
	va_list pvar;//申明va_list数据类型变量pvar，该变量访问变长参数列表中的参数。
  //宏va_start初始化变长参数列表。pvar是va_list型变量，记载列表中的参数信息。
  //parmN是省略号"..."前的一个数名，va_start根据此参数，判断参数列表的起始位置。
  //va_start(pvar, parmN);
	va_start(pvar,count);
  //获取变长参数列表中参数的值。pvar是va_list型变量，type为参数值的类型，也是宏va_arg返回数值的类型。
  //宏va_arg执行完毕后自动更改对象pvar，将其指向下一个参数。
  //va_arg(pvar, type);
	while(count--)
	{
    temp = va_arg(pvar,int);
    if(temp>max){
      max = temp;
    }
	}
  //关闭本次对变长参数列表的访问。
	va_end (pvar);
  return max;
}

void getRec_1(int recs[4][2],int* xy){
  int i=0;
  //初始化封闭矩形的长宽
  *xy=0;
  *(xy+1)=0;
  //设置宽:所有的宽加在一起
  for(i=0;i<N;i++)
    *xy += recs[i][0];
  //设置长：最长的长
  *(xy+1) += recs[0][1];
}

void getRec_2(int recs[4][2],int* xy){
  int i=0;
  *xy=0;
  *(xy+1)=0;
  //设置宽
  for(i=1;i<N;i++)
    *xy += recs[i][0];
  if(recs[0][1]>(*xy))
    *xy = recs[0][1];
  //设置长
    *(xy+1)=recs[0][0]+recs[1][1];
}

void getRec_3(int recs[4][2],int* xy){
  int i=0;
  *xy=0;
  *(xy+1)=0;
  //设置宽
  for(i=0;i<N-1;i++)
    *xy += recs[i][0];
  if(*xy < (recs[N-1][1]+recs[0][0]))
    *xy = recs[N-1][1]+recs[0][0];
  //设置长
  if(recs[0][1] > recs[1][1]+recs[N-1][0])
    *(xy+1) = recs[0][1] ;
  else
    *(xy+1) = recs[1][1]+recs[N-1][0];
}

void getRec_4(int recs[4][2],int* xy){
  int i=0;
  *xy=0;
  *(xy+1)=0;
  //设置宽
  *xy += myMax(2,recs[N-1][0],recs[N-2][0]);
  for(i=0;i<N-2;i++)
    *xy += recs[i][0];
  //设置长
  *(xy+1) = recs[N-1][1] + recs[N-2][1];
  if(*(xy+1) < recs[0][1])
    *(xy+1) = recs[0][1];
}

void getRec_5(int recs[4][2],int* xy){
  int i=0;
  *xy=0;
  *(xy+1)=0;
  //设置宽
  //设置长
}

void getRec_6(int recs[4][2],int* xy){
  int i=0;
  *xy=0;
  *(xy+1)=0;
  int temp[4]={0,0,0,0};
  if(N!=4){
    cout << "this rec can't use func6" << endl;
    exit(0);
  }
  temp[0] = recs[0][1]+recs[1][0];
  temp[1] = recs[1][1]+recs[2][0];
  temp[2] = recs[2][1]+recs[3][0];
  temp[3] = recs[3][1]+recs[0][0];
  //设置宽
  *xy = myMax(2,temp[1],temp[3]);
  //设置长
  *(xy+1) = myMax(2,temp[0],temp[2]);
}
void getRec(int seq,int recs[4][2],int* xy){
  switch (seq) {
    case 1:
      getRec_1(recs,xy);
      break;
    case 2:
      getRec_2(recs,xy);
      break;
    case 3:
      getRec_3(recs,xy);
      break;
    case 4:
      getRec_4(recs,xy);
      break;
    case 6:
      getRec_6(recs,xy);
      break;
    default:
      cout << "wrong func number" << endl;
  }
}
int main(){
  int i=0,j=0;
  int recs[4][2];//表示四个矩形的数组
  int xy[2]={0,0};//表示按方案得到的大的封闭矩形的xy值，第一项是宽，第二项是长
  int area = 0;//得到的矩形的面积
  int area_min = 0;//需求的最大矩形面积
  memset(recs,0,sizeof(int)*8);
  //input
  //1.输入矩形
  ifstream fin("packrec.in");
  for(i=0;i<4;i++){
    for(j=0;j<2;j++){
      fin >> recs[i][j] ;
    }
  }
  //2.将内部的二层数组排序，[i][0]是宽，[i][1]是长
  for(i=0;i<4;i++){
    if(recs[i][0]>recs[i][1])
      swap(recs[i][0],recs[i][1]);
  }
  //3.将外部的一层数组排序，根据[i][1]的值降序排序
  for(i=0;i<3;i++)
    for(j=0;j<(3-i);j++)//冒泡排序
      if(recs[j][1]<recs[j+1][1])
      {
        swap(recs[j][0],recs[j+1][0]);
        swap(recs[j][1],recs[j+1][1]);
      }
  //4.输出显示
  for(i=0;i<4;i++){
    cout << recs[i][0] << ' ' << recs[i][1] << endl;
  }
  cout << endl;
  //compute
  getRec(1,recs,xy);
  area_min = recArea(xy[0],xy[1]);
  for(i=2;i<=6;i++){
    if(i==5) continue;
    getRec(i,recs,xy);
    area = recArea(xy[0],xy[1]);
    cout << "seq:" << i << " " << area << endl;
    cout << "x:" << xy[0] << " y:" << xy[1] << endl;
    if(area < area_min)
      area_min = area;
  }
  ofstream fout("packrec.out");
  fout << area_min << endl;
  for(i=1;i<=6;i++){
    if(i==5) continue;
    getRec(i,recs,xy);
    if(recArea(xy[0],xy[1]) == area_min) {
      fout << xy[0] << " " << xy[1] << endl;
    }
  }


  //output

  return 0;
}
