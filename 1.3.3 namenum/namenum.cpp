#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int check(char name[4]){
  int i=0;
  string dict_name;
  ifstream dict("dict.txt");
  dict >> dict_name;
  for(i=0;i<4;i++){
    if(name[i]!=dict_name[i]) return 0;
  }
  return 1;
}
int main(){
  int i=0,j=0,m=0,n=0;
  int temp[4]={0,0,0,0};
  int result=0;
  string number;
  char name[5]={' ',' ',' ',' ','\0'};
  char letter[8][3]={//2-9
    {'A','B','C'},
    {'D','E','F'},
    {'G','H','I'},
    {'J','K','L'},
    {'M','N','O'},
    {'P','R','S'},
    {'T','U','V'},
    {'W','X','Y'}
  };
  //input
  ifstream fin("namenum.in");
  fin >> number;
  for(i=0;i<4;i++){
    temp[i]=int(number[i]-'0');
  }
  //compute
  //可能性：3x3x3x3=81
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      for(m=0;m<3;m++){
        for(n=0;n<3;n++){
          name[0]=letter[temp[0]-2][i];
          name[1]=letter[temp[1]-2][j];
          name[2]=letter[temp[2]-2][m];
          name[3]=letter[temp[3]-2][n];
          result = check(name);
          if(result==1) break;
        }
        if(result==1) break;
      }
      if(result==1) break;
    }
    if(result==1) break;
  }
  //output
  ofstream fout("namenum.out");
  if(result==0){
    fout << "no name" << endl;
  }else{
    fout << name[0] << name[1] << name[2] << name[3] << endl;
  }
  return 0;
}
