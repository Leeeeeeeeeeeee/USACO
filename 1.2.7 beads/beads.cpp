
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int i=0,j=0;
  int n=0;
  string beads_s;
  string beads_templ,beads_tempr,temp;
  char beads_letterl,beads_letterr;
  int beads_countl=0,beads_countr=0;
  int count[n+2];
  int max=0;
  cout << "check point:initialize variable successfully." << endl;
  //input
  ifstream fin ("beads.in");
  fin >> n >> beads_s;
  //compute 穷尽算法
  for(i=0;i<n+1;i++){
    //1.从切点开始区分两个序列
    beads_templ=beads_s.substr(0,i);
    beads_tempr=beads_s.substr(i,n);
    beads_tempr.append(beads_templ);
    reverse(beads_templ.begin(),beads_templ.end());
    temp=beads_s.substr(i,n);
    reverse(temp.begin(),temp.end());
    beads_templ.append(temp);
    cout << beads_templ << ' ' << beads_tempr <<endl;
    //2.左序列计数
    beads_countl=0;
    beads_letterl=beads_templ[0];
    if(beads_letterl=='w'){
      for(j=0;j<n;j++){
        if(beads_templ[j]=='w'){
          continue;
        }else{
          beads_letterl=beads_templ[j];
          break;
        }
      }
    }
    for(j=0;j<n;j++){
      if(beads_templ[j]==beads_letterl || beads_templ[j]=='w'){
        beads_countl++;
      }else{
        break;
      }
    }
    //3.右序列计数
    beads_countr=0;
    beads_letterr=beads_tempr[0];
    if(beads_letterr=='w'){
      for(j=0;j<n;j++){
        if(beads_tempr[j]=='w'){
          continue;
        }else{
          beads_letterr=beads_tempr[j];
          break;
        }
      }
    }
    for(j=0;j<n;j++){
      if(beads_tempr[j]==beads_letterr || beads_tempr[j]=='w'){
        beads_countr++;
      }else{
        break;
      }
    }
    //4.总数计数
    count[i] = beads_countl + beads_countr;
    cout << beads_countl << ' ' << beads_countr << ' ' << count[i] << endl;
    cout << endl;
  }
  //5.找出最大的count
  for(i=0;i<n+1;i++){
    if(count[i]>max){
      max=count[i];
    }
  }
  cout << max;
  //output
  ofstream fout ("beads.out");
  fout << max << endl;
  return 0;
}
