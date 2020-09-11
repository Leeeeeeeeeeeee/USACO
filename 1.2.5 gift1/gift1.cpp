/*
ID: qq267181
TASK: ride
LANG: C++
*/

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

typedef struct {
  int seq;
  string name;
  int account=0;
}member;

int main(){
  int i,j,n;//循环用变量i,j、结构体数组的长度（总人数）
  int receivers_n,receivers_money;//被给予的人数、被给予的序号，被给予的金额
  int givers_seq,givers_money;//给予者的序号、给予者的金额
  string cache1,cache2;

  ifstream fin ("gift1.in");
  ofstream fout ("gift1.out",ios_base::out);

  //input && handle
  fin >> n;
  member m[n];
  for(i=0;i<n;i++){
    m[i].seq=i;
    fin >> m[i].name;
    if( m[i].name.length()>18){
      exit(1);
    }
  }
  //每个循环都是一次给予操作（对于给予者来说）
  while(!fin.eof()){
    fin >> cache1;
    //1.输入并查找给予者的序号
    for(i=0;i<n;i++){
      if(cache1==m[i].name){
        givers_seq=i;
        fin >> givers_money >> receivers_n;
        break;
      }
    }
    //2.确认给予的金额，被给予者的余额
    if(givers_money==0 || receivers_n==0){
      for(i=0;i<receivers_n;i++){
        fin >> cache2;
      }
      continue;
    }
    receivers_money = givers_money / receivers_n;
    m[givers_seq].account += (givers_money%receivers_money)-givers_money;
    //3.开始给每个被给予者金钱
    for(i=0;i<receivers_n;i++){//每个循环都是一次给予操作（对于被给予者来说）
      fin >> cache2;
      for(j=0;j<n;j++){
        if(cache2==m[j].name){//找到被给予者的序号
          m[j].account += receivers_money;
        }
      }
    }
  }
  //output
  for(i=0;i<n;i++){
    fout << m[i].name << ' ' << m[i].account << endl;
  }
  return 0;
}
