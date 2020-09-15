#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int i=0,j=0;
  int n=0;
  int timeslice[5001];//比实际时间多一个数，timeslice[0]废弃
  int start=0,end=0;
  int flag=0,flag_start=0,flag_end=0;
  int max0=0,max1=1,temp=0;
  memset(timeslice,0,sizeof(timeslice));
  //input
  ifstream fin ("milk2.in");
  fin >> n;
  for(i=0;i<n;i++){
    fin >> start >> end;
    for(j=start;j<end+1;j++){
      timeslice[j]=1;//数组的序号和实际时间相同
    }
  }
  //compute
  flag=timeslice[1];
  flag_start=1;
  for(i=1;i<5000+1;i++){
    if(timeslice[i]==flag){
      continue;
    }else{
      flag_end=i-1;

      if(flag_start==1){//1.是头部
        if(flag==0){
        }else if(flag==1){
          max1=flag_end-flag_start;
        }
      }else if(flag_end==5000){//2.是尾部
        if(flag==0){
        }else if(flag==1){
          temp=flag_end-flag_start;
          if(temp>max1){
            max1=temp;
          }
        }
      }else{//3.是中部
        if(flag==0){
          temp=flag_end-flag_start;
          if(temp>max0){
            max0=temp+2;
          }
        }else if(flag==1){
          temp=flag_end-flag_start;
          if(temp>max1){
            max1=temp;
          }
        }
      }
      flag=timeslice[i];
      flag_start=i;
    }
  }
  //output
  ofstream fout ("milk2.out");
  fout << max1 << ' ' << max0 << endl;
  return 0;
}
