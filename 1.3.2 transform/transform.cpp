#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int func90(int n,int** square_before,int** square_after){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(*(*(square_before+i)+j)!=*(*(square_after+j)+abs(i-n+1))){
        return 0;
      }
    }
  }
  return 1;
}
int func180(int n,int** square_before,int** square_after){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(*(*(square_before+i)+j)!=*(*(square_after+abs(j-n+1))+abs(j-n+1))){
        return 0;
      }
    }
  }
  return 2;
}
int func270(int n,int** square_before,int** square_after){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(*(*(square_before+i)+j)!=*(*(square_after+abs(j-n-1))+i)){
        return 0;
      }
    }
  }
  return 3;
}
int funcReflect(int n,int** square_before,int** square_after){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(*(*(square_before+i)+j)!=*(*(square_after+i)+abs(j-n-1))){
        return 0;
      }
    }
  }
  return 4;
}
int funcReflectAndTurn(int n,int** square_before,int** square_after){
  int i,j;
  int** square_temp = new int*[n];
  for(int i=0;i<n;i++)
      square_temp[i] = new int[n];

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      square_temp[i][j]=*(*(square_before+i)+abs(j-n-1));
      }
    }
  if(func90(n,square_temp,square_after)){
    return 5;
  }else if(func180(n,square_temp,square_after)){
    return 5;
  }else if(func270(n,square_temp,square_after)){
    return 5;
  }else{
    return 0;
  }
}
int funcNoChange(int n,int** square_before,int** square_after){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(*(*(square_before+i)+j)!=*(*(square_after+i)+j)){
        return 0;
      }
    }
  }
  return 6;
}
int main(){
  int i=0,j=0;
  int n=0,answer=0;
  char temp;
  //input
  ifstream fin("transform.in");
  fin >> n;
  //1.声明二维数组
  int** square_before = new int*[n];
  for(int i=0;i<n;i++)
      square_before[i] = new int[n];
  int** square_after = new int*[n];
  for(int i=0;i<n;i++)
      square_after[i] = new int[n];
  //2.将transform.in的数据输入二维数组中
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      fin >> temp;
      if(temp=='@'){
        square_before[i][j]=1;
      }else if(temp=='-'){
        square_before[i][j]=0;
      }
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      fin >> temp;
      if(temp=='@'){
        square_after[i][j]=1;
      }else if(temp=='-'){
        square_after[i][j]=0;
      }
    }
  }
  //3.cout输出查看数组的内容
  /*for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cout << square_before[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cout << square_after[i][j] << ' ';
    }
    cout << endl;
  }*/

  //compute && output
  ofstream fout("transform.out");

  while(true){
    answer=func90(n,square_before,square_after);
    if(answer){
      fout << answer;

      break;
    }
    answer=func180(n,square_before,square_after);
    if(answer){
      fout << answer;
      break;
    }
    answer=func270(n,square_before,square_after);
    if(answer){
      fout << answer;
      break;
    }
    answer=funcReflect(n,square_before,square_after);
    if(answer){
      fout << answer;
      break;
    }
    answer=funcReflectAndTurn(n,square_before,square_after);
    if(answer){
      fout << answer;
      break;
    }
    answer=funcNoChange(n,square_before,square_after);
    if(answer){
      fout << answer;
      break;
    }
    fout << '7';
    break;
  }

  //output


  for(int i=0;i<n;i++)
      delete []square_before[i];
  delete []square_before;
  for(int i=0;i<n;i++)
      delete []square_after[i];
  delete []square_after;
  return 0;
}
