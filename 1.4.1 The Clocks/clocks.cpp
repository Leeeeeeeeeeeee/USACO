//1.方法一：枚举
//每种变换方法可以使用0-3次，并且每种变换方法在前与后是等效的。
//所以，利用递归，按题中顺序枚举所有可能的解，并且每次记录下途径。
//那么第一种解就是我们要求的答案，输出即可。

#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int style_seq[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
//A0 B1 C2 D3 E4 F5 G6 H7 I8
int style[9][5]={
  {0 ,1 ,3 , 4,-1},//ABDE
  {0 ,1 ,2 ,-1,-1},//ABC
  {1 ,2 ,4 , 5,-1},//BCEF
  {0 ,3 ,6 ,-1,-1},//ADG
  {1 ,3 ,4 , 5, 7},//BDEFH
  {2 ,5 ,8 ,-1,-1},//CFI
  {3 ,4 ,6 , 7,-1},//DEGH
  {6 ,7 ,8 ,-1,-1},//GHI
  {4 ,5 ,7 , 8,-1},//EFHI
};

int isNeeded(int* clocks){
  int i=0;
  for(i=0;i<9;i++){
    if(clocks[i]==12) continue;
    else return 0;
  }
  for(i=0;i<9;i++){
    cout << clocks[i] << ' ';
    if((i+1)%3==0) cout << endl;
  }
  for(i=0;i<10;i++){
    cout << style_seq[i] << ' ';
  }
  cout << endl;
  return 1;
}

int change(int* clocks,int depth){
  int i=0,j=0,k=0;
  int temp=0;
  //1.判断是否已进入递归的最深层
  if(depth==0){
    //cout << "to the end!" << endl << endl;
    return -1;
  }
  if(depth==10){
    for(k=0;k<10;k++){
      style_seq[k]=-1;
    }
  }
  //2.依次按9种方法改变数组
  for(i=0;i<9;i++){
    //2.1 记录下style序列
    //cout << "depth: " << depth << endl;
    //cout << "style: " << i << endl;
    //2.2 改变数组
    style_seq[depth%10]=i;
    for(j=0;j<5;j++){
      if(style[i][j]==-1) break;
      if(clocks[style[i][j]]==12){
        //顺时针旋转90度，数字+3，12时变为3
        clocks[style[i][j]]=3;
      }else{
        clocks[style[i][j]]+=3;
      }
    }
    //2.3 输出展示
    /*for(k=0;k<9;k++){
      cout << clocks[k] << ' ';
      if((k+1)%3==0) cout << endl;
    }
    cout << endl;*/
    //2.4 判断是否满足条件，是的话返回，不是的话进行递归
    if(isNeeded(clocks)==1){
      return 1;
    }else{
      temp = change(clocks,depth-1);
      if(temp == 1){
        return 1;
      }
    }
  }
  return 0;
}

int main(){
  int i=0;
  int clocks_old[9];
  int clocks_new[9];
  int temp = 0;
  //input
  ifstream fin("clocks.in");
  for(i=0;i<9;i++){
    fin >> clocks_old[i] ;
  }

  //compute
  for(i=0;i<9;i++){
    clocks_new[i]=clocks_old[i];
  }
  cout << "old clocks:" << endl;
  for(i=0;i<9;i++){
    cout << clocks_new[i] << ' ';
    if((i+1)%3==0) cout << endl;
  }
  cout << endl;

  temp = change(clocks_new,10);
  cout << "temp: " << temp << endl;

  //output

  return 0;
}
