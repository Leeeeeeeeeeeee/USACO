
#include <fstream>
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
/*
牛式
    * * *
  x   * *
  --------
    * * *
  * * *
  --------
  * * * *
*/

int getNum1(int* num,int* num_1,int n){
  int i=0,j=0,k=0;
  int num_1_i=0;//数组的序数
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
        num_1[num_1_i]=num[i]*100+num[j]*10+num[k]*1;
        num_1_i++;
      }
    }
  }
  return 0;
}
int getNum2(int* num,int* num_2,int n){
  int i=0,j=0;
  int num_2_i=0;//数组的序数
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      num_2[num_2_i]=num[i]*10+num[j]*1;
      num_2_i++;
    }
  }
  return 0;
}
int main(){
  int i=0,j=0;
  int n=0;//输入的数字有多少个
  int num1=0,num2=0;//第一行的数据，第二行的数据
  //input
  ifstream fin("crypt1.in");
  fin >> n;
  int num[n];
  for(i=0;i<n;i++){
    fin >> num[i];
    if(num[i]>9) exit(1);
  }
  int num_1[n*n*n];
  memset(num_1,0,sizeof(int)*n*n*n);
  int num_2[n*n];
  memset(num_2,0,sizeof(int)*n*n);
  //compute && output
  //1.获得第一行的数字（3位）5x5x5=125
  getNum1(num,num_1,n);
  //2.获得第二行的数字（2位）5x5=25
  getNum2(num,num_2,n);
  ofstream fout("crypt1.out");
  for(i=0;i<n*n*n;i++){
    for(j=0;j<n*n;j++){
      //3.验证第一行的数字乘以第二行数字的个数位得到的数字<1000
      if(num_1[i]*(num_2[j]%10) > 999) continue;
      //4.验证第一行的数字乘以第二行数字的十数位得到的数字<1000
      if(num_1[i]*(num_2[j]/10) > 999) continue;
      //5.验证第一行的数字乘以第二行的数字得到的结果<10000
      if(num_1[i]*num_2[j] > 9999) continue;
      fout << num_1[i] << ' ' << num_2[j] << endl;
    }
  }
  return 0;
}
