#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
void createArithmeticProg(int *seq,int n,int a,int b){
  int i=0;
  //cout << "a:" << a << " b:" << b << endl;
  for(i=0;i<n;i++){
    *(seq+i)=a+(b*i);
    //cout << "seq[" << i << "]" << seq[i] << endl;
  }
}

bool isBivariateCorrelate(int number){
  int x=0,y=0;
  for(x=0;x<=number;x++){
    for(y=0;y<=number;y++){
      if(number==x*x+y*y) return true;
    }
  }
  return false;
}



int main(){
  //1.定义变量，输入数值
  int n=0,m=0;
  int i=0,j=0;
  int z=0;
  int flag=0;
  int temp=0,length=0;
  vector<vector<int>>vec_seq;
  vector<int>seq_out;
  ifstream fin("ariprog.in");
  fin >> n >> m;
  if(n>10000) exit(1);
  int seq_cal[n]={};
  //2.处理数据
  for(i=0;i<=2*m*m;i++){
    for(j=1;j<=2*m*m;j++){
      //cout << "n:" << n << " i:" << i << " j:" << j << endl;
      //2.1 创造等差数列，i为a，j为b
      createArithmeticProg(seq_cal,n,i,j);
      //2.2 判断等差数列里的数字是否都为双平方数
      for(z=0;z<n;z++){
        if(isBivariateCorrelate(seq_cal[z])){
          //cout << "seq:" << sequence[z] << " good!" << endl;
          flag=1;
        }else{
          //cout << "seq:" << sequence[z] << " bad!" << endl;
          flag=0;
          break;
        }
      }
      if(flag==1){
        //cout << i << ' ' << j << endl;
        seq_out.push_back(i);
        seq_out.push_back(j);
        vec_seq.push_back(seq_out);
        seq_out.clear();
      }
    }
  }
  //2.3 先按b排序
  for (i = 0; i < vec_seq.size() - 1; i++)
    for (j = 0; j < vec_seq.size() - 1 - i; j++)
      if (vec_seq[j][1] > vec_seq[j + 1][1]){
        swap(vec_seq[j][0],vec_seq[j+1][0]);
        swap(vec_seq[j][1],vec_seq[j+1][1]);
      }
  //2.4 再按a排序
  temp = vec_seq[0][1];
  for(i=0;i<int(vec_seq.size());i++){
    if(vec_seq[i][1]==temp){
      length++;
    }else{
      temp=vec_seq[i][1];
      if(length>1){
        for (j = 0; j < length - 1; j++)
          for (z = 0; z < length - 1 - j; z++)
            if (vec_seq[i-length+z][0] > vec_seq[i-length+z+1][0]){
              swap(vec_seq[i-length+z][0],vec_seq[i-length+z+1][0]);
              swap(vec_seq[i-length+z][1],vec_seq[i-length+z+1][1]);
            }
      }
      length=1;
    }
  }
  ofstream fout("ariporg.out");
  for(i=0;i<int(vec_seq.size());i++){
    for(j=0;j<2;j++){
      //cout << j << ":" << vec_seq[i][j] << " ";
      fout << vec_seq[i][j] << ' ';
    }
    //cout << endl;
    fout << endl;
  }
  return 0;
}
